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
  while(temp!=NULL){
    temp->sort_list();
    temp=temp->link();
  }
	while(true){
	  string user_word;
    int threshold;
	  cin.ignore(1000,'\n');
	  cout<<"Enter word: ";
	  cin>>user_word;
    if(user_word=="-1"){
		  break;
	  }
    cout<<"Enter threshold: ";
    cin>>threshold;
    Word* search=head;
    while(search){
      if(search->get_word()==user_word){
        break;
      }
      search=search->link();
    }
	  File* f=search->f_head();
    File* temp_f=f;
    while((temp_f->get_count()>=threshold)&& (temp_f!=NULL)){
      std::cout << "File: " << temp_f->get_fname()<<"; Count: "<<temp_f->get_count()<<endl;
      temp_f=temp_f->link();
    }

	  cin.ignore(1000,'\n');
	}
  return 0;

}
