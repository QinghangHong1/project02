#include <iostream>
#include <cstdlib>
#include <string>
#include "word.h"

using namespace std;

Word::Word(string word_name,string file_name){
  word=word_name;
  head=new List(file_name);
  link_field=NULL;
  prev_field=NULL;
}
string Word::get_word(){
  return word;
}


void Word::update_list(string file_name){
  list_update(head,file_name);
}
Word* Word::link(){
  return link_field;
}
Word* Word::prev(){
  return prev_field;
}
void Word::set_link(Word* next){
  link_field=next;
}
void Word::set_prev(Word* previous){
  prev_field=previous;
}
void Word::sort_list(){
  sort(head);
}
List* Word::get_head(){
  return head;
}
Word* search(Word* head,string word_name){
  Word* temp=head;
  while(temp){
    if(temp->get_word()==word_name){
      return temp;
    }
    temp=temp->link();
  }
  return NULL;
}
int length(Word* head){
  int count=0;
  Word* temp=head;
  while(temp){
    count++;
    temp=temp->link();
  }
  return count;
}

void word_insert(Word*& head, string word_name, string file_name){
  if(head==NULL){
    Word* new_word=new Word(word_name,file_name);
    head=new_word;
    //cout<<"add word "<<word_name<<" to the empty word list with file "<<file_name<<endl;
    //cout<<"empty "<<word_name<<" "<<endl;
  }else if(search(head,word_name)==NULL){//word does not exist in the word list
    Word* new_word=new Word(word_name,file_name);
    
    
    Word* temp=head;
    bool added=false;
    while(temp){
      if((word_name.compare(temp->get_word()))<0){//insert to the front of temp
        added=true;
        if(temp->prev()!=NULL){//temp in the middle
          new_word->set_link(temp);
          new_word->set_prev(temp->prev());
          temp->prev()->set_link(new_word);
          temp->set_prev(new_word);
	  break;
          //cout<<"add new word "<<word_name<<" to the middle word list"<<" and file "<<file_name<<endl;
	  //cout<<"middle insert "<<word_name<<" "<<endl;
        }else{//temp is the head
	  
	  new_word->set_link(temp);
          temp->set_prev(new_word);
          head=new_word;
	  //cout<<"head insert "<<word_name<<" "<<endl;
	  break;
          //cout<<"add new word "<<word_name<< " to the begginning word list"<<" and file "<<file_name<<endl;
        }
      }
      temp=temp->link();
    }
    if(!added){//add to the end of list
      Word* t=head;
      for(int i=0;i<(length(head)-1);i++){//iterate  the to last word
        t=t->link();
      }
      new_word->set_prev(t);
      t->set_link(new_word);
      //cout<<"add new word "<<word_name<<"to the end of word list"<<" and file "<<file_name<<endl;
      //cout<<"tail add "<<word_name<<" "<<endl;
    
    }
  }else{//word in the list
    Word* found=search(head,word_name);
    found->update_list(file_name);
    //cout<<"update "<<word_name<<endl;
    //cout<<"found word: "<<word_name<<" and update the file "<<file_name<<endl;
  }
}

void printList(Word* head){
  Word* temp=head;
  while(temp){
    cout<<temp->get_word()<<" ";
    temp=temp->link();
  }
}
