#pragma once
#include <string>
#include<vector>
#include <iostream>
#include <vector>
using namespace std;
class InputHandler
{
public:
	InputHandler();

	bool console_read();
	bool file_read(string filename);
	void handle_readin();
	void clear_duplicate();
	
 

private:
	string readin;
	vector<string> word_list;
};


