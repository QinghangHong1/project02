#ifndef LIST_H
#define LIST_H
#include "itemtype.h"

using namespace std;

class List
{
    public:
        //constructor
        List();
        List(string file_name);
        List(File* f_head);
        //modifiers
        void update_file(string file_name);
        //observers
        size_t get_freq(string file_name);
        size_t get_size();
        File* get_head();
        void sort();

      private:
        File* head;
        size_t size;
};







#endif // LIST_H
