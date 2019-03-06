#pragma once

#include <string>
#include<vector>
#include <iostream>
#include <vector>



using namespace std;
class  InputHandler
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
	void handle_readin();
	void clear_duplicate();
	void handle_parameters(int para_num, vector<string> para);



private:
	string readin;



};



