#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <fstream>

#include "word.h"
#include "wordsearchcount.h"

using namespace std;

int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

int main(int argc, char* argv[])
{
	string dir; //
	vector<string> files = vector<string>();
	Word word_array[1000];
	  int used=0;

	if (argc < 2){
		cout << "No Directory specified; Exiting ..." << endl;
		  return(-1);
		}
	dir = string(argv[1]);
	if (getdir(dir,files)!=0){
		cout << "Error opening " << dir << "; Exiting ..." << endl;
		 return(-2);
	}

	Word* head=NULL;
  string slash("/");
	for (unsigned int i = 0;i < files.size();i++) {
		if(files[i][0]=='.')continue; //skip hidden files
		ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
		// ...read the file...
		string word;
		while(true){
		  fin>>word;
		  if(fin.eof()) { break;}
		  else {
			  word_insert(head,word,files[i]);

		  }
		}
		fin.close();
	}
  Word* temp=head;
  while(temp){
    temp.sort_list();
  }

  while(true){
    string word1;
    string word2;

    cin.ignore(1000,'\n');
    cout<<"Enter word: ";
    cin>>word1;
    if(word1=="-1"){
      break;
    }
    cout<<"Enter word: ";
    cin<<word2;
    if(word2=="-1"){
      break;
    }
    Word* search1=head;
    while(search1){//search word1 from the word list
      if(search1->get_word()==word1){
        break;
      }
      search1=search1->link();
    }
	  File* f1=search1->f_head();
    File* temp_f1=f1;
    List union_list(temp_f1);
    temp_f1=temp_f1->link();
    while(temp_f1){//insert the files of word1 into union_file

      union_list.update_file(temp_f1->get_fname());
      temp_f1=temp_f1->link();
    }

    Word* search2=head;
    while(search2){//search word2 from word list
      if(search2->get_word()==word2){
        break;
      }
      search2=search2->link();
    }
    File* f2=search2->f_head();
    File* temp_f2=f2;
    while(temp_f2){//insert the files of word2 into union_file
      union_list.update_file(temp_f2->get_fname());
      temp_f2=temp_f2->link();
    }
    File* union_head=union_list.get_head();
    File* union_temp=union_head;
    while(union_temp){
      cout<<union_temp->get_fname()<<endl;
      union_temp=union_temp->link();
    }
    cin.ignore(1000,'\n');
  }

  return 0;
}
