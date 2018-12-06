#include "list.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
using namespace std;
 int main(){
   string s1="test1.txt";
   string s2="test2.txt";
   string s3="test3.txt";
   string s4="test4.txt";
   List* l=new List(s1);
   //tests for member functions
   assert(l->fname()==s1);
   assert(l->count()==1);
   l->set_count(l->count()+1);
   assert(l->count()==2);
   assert(l->link()==NULL);
   assert(l->prev()==NULL);


   //tests for head_insert
   head_insert(l,s2);
   assert(l->fname()==s2);
   assert(l->count()==1);;
   assert(l->link()->fname()==s1);
   assert(l->link()->count()==2);
   assert(l->link()->link()==NULL);

   //tests for list_update
   list_update(l,s1);
   List* test1=search(l,s1);
   assert(test1->fname()==s1);
   assert(test1->count()==3);

   list_update(l,s3);
   assert(l->fname()==s3);
   assert(l->count()==1);
   assert(l->link()->fname()==s2);

   //tests for min_file
   List* m=min_file(l);
   assert(m->fname()==s3);
   list_update(l,s3);
   list_update(l,s4);
   List* n=min_file(l);
   assert(n->fname()==s4);

   //tests for sort
   sort(l);
   List* a=l;
   while(a){
     cout<<"file name "<<a->fname()<<" count: "<<a->count()<<endl;
     a=a->link();
   }
   //tests for erase_one
   cout<<"all tests passed";




   return 0;

 }
