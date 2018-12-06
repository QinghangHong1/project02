#ifndef LIST_H
#define LIST_H
#include "itemtype.h"

using namespace std;

class List
{
    public:
        //constructor
        List();
        List(string file_name,int freq=1);
        List(File f_head);
        //observers
        string fname();
        int count();
        List* link();
        List* prev();
        
        //modifiers
        void set_fname(string file_name);
        void set_count(int count);
        void set_link(List* l);
        void set_prev(List* p);
      private:
        File data;
        List* link_field;
        List* prev_field;
};
void head_insert(List*& head,string file_name, int count=1);
void list_update(List*& head,string file_name);
void erase_one(List*& head, List*& delete_list);
List* search(List* head, string file_name);
List* min_file(List* head);
void sort(List*& head);






#endif // LIST_H
