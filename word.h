#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "list.h"
using namespace std;

class Word{
  public:
    //constructor
    Word(string word_name,string file_name);
    //observers
    string get_word();//return the word
    //reurn the frequency of this word in the file
    size_t get_count(string file_name);

    Word* link();
    Word* prev();
    List* get_head();
    //modifiers
    void set_word(string word_name);
    void update_list(string file_name);
    void set_link(Word* next);
    void set_prev(Word* previous);
    void sort_list();
  private:
    string word;
    List* head;
    Word* link_field;
    Word* prev_field;
};

//helper methods
Word* search(Word* head,string word_name);

void word_insert(Word*& head, string word_name, string file_name);
int length(Word* head);
void printList(Word* head);
#endif
