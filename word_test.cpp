#include <iostream>
#include <cassert>
#include <cstdlib>
#include "word.h"
using namespace std;

int main(){
  Word* head=NULL;
  word_insert(head,"apple","test1.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"app","test1.txt");
  word_insert(head,"apple","test2.txt");
  word_insert(head,"apple","test1.txt");
  word_insert(head,"appl","test1.txt");
  word_insert(head,"apple","test1.txt");
  word_insert(head,"appl","test1.txt");
  word_insert(head,"apple","test1.txt");
  Word* temp=head;
  for(int i=0;i<3;i++){
    temp->sort_list();
    temp=temp->link();
  }
  temp=head;
  List* temp_l;
  List* l;
  while(temp){
    l=temp->get_head();
    temp_l=l;
    while(temp_l){
      cout<<"word: "<<temp->get_word()<<" ";
      cout<<"file: "<<temp_l->fname()<<"; count: "<<temp_l->count()<<endl;
      temp_l=temp_l->link();

    }
    temp=temp->link();
  }
  return 0;
}
