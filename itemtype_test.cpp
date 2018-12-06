
#include "itemtype.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
using namespace std;

int main(){

  string s1="test1.txt";
  string s2="test2.txt";
  File f;
  f.set_count(1);
  assert(f.get_count()==1);
  f.set_fname("test.txt");
  assert(f.get_fname()=="test.txt");


  File h(s1);
  assert(h.get_fname()==s1);
  assert(h.get_count()==1);
  h.set_count(h.get_count()+1);
  assert(h.get_count()==2);
  cout<<"all tests passed";
  return 0;
}
