#pragma once
#ifdef DLL_INPUTHANDLER_EXPORTS
#define DLL_INPUTHANDLER_API _declspec(dllexport)
#else
#define DLL_INPUTHANDLER_API _declspec(dllimport)
#endif



#include <string>
#include<vector>
#include <iostream>



using namespace std;
class DLL_INPUTHANDLER_API InputHandler
{
public:
	InputHandler();

	vector<string> word_list;
	int mode;//mode=0��൥�� mode=1�����
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



