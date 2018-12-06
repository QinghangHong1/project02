#include <iostream>
#include <cstdlib>
#include <cassert>
#include "list.h"
using namespace std;

List::List(){

}
List::List(string file_name,int freq){
  data.set_fname(file_name);
  data.set_count(freq);
  link_field=NULL;
  prev_field=NULL;
}
List::List(File f){
  data.set_fname(f.get_fname());
  data.set_count(f.get_count());
}
string List::fname(){
  return data.get_fname();
}
int List::count(){
  return data.get_count();
}
List* List::link(){
  return link_field;
}
List* List::prev(){
  return prev_field;
}
void List::set_fname(string file_name){
  data.set_fname(file_name);
}
void List::set_count(int count){
  data.set_count(count);
}
void List::set_link(List* l){
  link_field=l;
}
void List::set_prev(List* p){
  prev_field=p;
}
void head_insert(List*& head,string file_name, int count){
  List* new_list=new List(file_name);
  new_list->set_count(count);
  if(head==NULL){
    head=new_list;
  }

  new_list->set_link(head);
  head->set_prev(new_list);
  head=new_list;
}
List* search(List* head,string file_name){
  List* temp=head;
  while(temp){
    if(temp->fname()==file_name){
      return temp;
    }
    temp=temp->link();
  }
  return NULL;
}
void list_update(List*& head,string file_name){
  List* found=search(head,file_name);
  if(found!=NULL){
    found->set_count(found->count()+1);
  }else{
    head_insert(head,file_name,1);
  }
}
void erase_one(List*& head, List*& delete_list){
  if((head==NULL)||(delete_list==NULL)){
    return;
  }
  if((head==delete_list)&&(head->link()==NULL)){//only one node
    delete head;
    head=NULL;
  }else if(head==delete_list){//delete the first node of the list
    head=head->link();
    head->set_prev(NULL);
    delete delete_list;
  }else if(delete_list->link()==NULL){//delete the last node
    delete_list->prev()->set_link(NULL);
    delete delete_list;
  }else{//in the middle
    delete_list->prev()->set_link(delete_list->link());
    delete_list->link()->set_prev(delete_list->prev());
    delete delete_list;
  }
}
List* min_file(List* head){
  List* min_file=head;
  List* temp=head;
  int min=min_file->count();
  while(temp){
    if(temp->count()<min){
      min_file=temp;
      min=temp->count();
    }
    temp=temp->link();
  }
  return min_file;
}
void sort(List*& head){

  List* m=min_file(head);
  List* result=new List(m->fname(),m->count());
  erase_one(head,m);
  while(head!=NULL){
    List* min=min_file(head);
    head_insert(result,min->fname(),min->count());
    erase_one(head,min);

  }
  head=result;

}
