#ifndef FILE_H
#define FILE_H
#include <string>
using namespace std;
class File
{
	public:
		File();
		File(string file_name);
		int get_count() const;
		void set_count(int freq);
		string get_fname() const;
		void set_fname(string file_name);

	private:
		string fname;
		int count;

};
#endif
