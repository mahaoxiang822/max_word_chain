#pragma once
#ifdef MY_DLL_API
#else
#define MY_DLL_API _declspec(dllimport)
#endif



#include <string>
#include<vector>
#include <iostream>
#include <vector>



using namespace std;
class InputHandler
{
public:
	InputHandler();

	vector<string> word_list;
	int mode;//mode=0最多单词 mode=1最长单词
	char head_ch;
	char tail_ch;
	string inputfile_path;
	bool enable_loop;
	bool console_read();
	bool file_read();
	void string_read(string input);
	void handle_readin();
	void clear_duplicate();
	void handle_parameters(int para_num, vector<string> para);



private:
	string readin;



};



