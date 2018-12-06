#include <iostream>
#include <cassert>
#include <cstdlib>
#include "word.h"
using namespace std;

int main(){
  Word* head=NULL;
  word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test1.txt");

  word_insert(head,"app","test1.txt");
  
  word_insert(head,"appl","test1.txt");
  word_insert(head,"appl","test2.txt");
  word_insert(head,"banana","test1.txt");
  word_insert(head,"apply","test2.txt");
  word_insert(head,"orange","test1.txt");
   word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test1.txt");

  word_insert(head,"app","test1.txt");
  
  word_insert(head,"appl","test1.txt");
  word_insert(head,"appl","test2.txt");
  word_insert(head,"banana","test1.txt");
  word_insert(head,"apply","test2.txt");
  word_insert(head,"orange","test1.txt");
   word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test1.txt");

  word_insert(head,"app","test1.txt");
  
  word_insert(head,"appl","test1.txt");
  word_insert(head,"appl","test2.txt");
  word_insert(head,"banana","test1.txt");
  word_insert(head,"apply","test2.txt");
  word_insert(head,"orange","test1.txt");
  Word* temp=head;
  for(int i=0;i<(length(head));i++){
    temp->sort_list();
    temp=temp->link();
  }
  printList(head);
  cout<<endl;
  temp=head;
  List* temp_l;
  List* l;
  while(temp){
    l=temp->get_head();
    temp_l=l;
    cout<<"word: "<<temp->get_word()<<endl;
    while(temp_l){
      
      cout<<"file: "<<temp_l->fname()<<"; count: "<<temp_l->count()<<endl;
      temp_l=temp_l->link();

    }
    cout<<"end of the word"<<endl;
    temp=temp->link();
    }
  return 0;
}
