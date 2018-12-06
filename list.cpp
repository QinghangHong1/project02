#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

List::List(){

  size=0;
}

List::List(string file_name){
  head=new File(file_name);
  size=1;
}
List::List(File* f_head){
  head=f_head;
  if(head==NULL){
    size=0;
  }else{
    size=list_length(head);
  }
}

void List::update_file(string file_name){

  File* target=search(head,file_name);
  if(size==0){
    head=new File(file_name);
    size++;
    return;
  }
  if(target!=NULL){
    target->set_count(target->get_count()+1);

  }else{

    insert(head,file_name);
    size++;
  }

}

size_t List::get_freq(string file_name){
  File* temp=search(head,file_name);
  if(temp==NULL){
    return 0;
  }
  return temp->get_count();

}

size_t List::get_size(){
  return size;
}
File* List::get_head(){
  return head;
}
void List::sort(){

  File* new_head=NULL;

  while(head!=NULL){
    File* temp=head;
    File* min_file=head;
    size_t min_count=temp->get_count();
    while(temp!=NULL){//find the file with mininum count
      if(temp->get_count()<min_count){
        min_count=temp->get_count();
        min_file=temp;
      }
      temp=temp->link();
    }
    insert(new_head,min_file->get_fname(),min_file->get_count());
    if((min_file->link()==NULL)&&(min_file->prev()==NULL)){//min_file the only node
      delete min_file;
      head=NULL;
    }else if(min_file->link()==NULL){//min_file at the end of list

      min_file->prev()->set_link(NULL);
      delete min_file;
    }else if(min_file->prev()==NULL){//min_file is the head
      min_file->link()->set_prev(NULL);
      head=min_file->link();
      delete min_file;
    }else{//min_file in the middle
      min_file->prev()->set_link(min_file->link());
      min_file->link()->set_prev(min_file->prev());
      delete min_file;
    }
  }
  head=new_head;
}
