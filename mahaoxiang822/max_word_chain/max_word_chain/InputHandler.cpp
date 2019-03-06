#include "pch.h"
#include "InputHandler.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace::std;

InputHandler::InputHandler() {
	readin = "";
	mode = 0;
	inputfile_path = "";
	head_ch = 0;
	tail_ch = 0;
	enable_loop = false;
}

bool InputHandler::console_read() {
	return true;
}

bool InputHandler::file_read() {
	
	ifstream wordlist;
	ostringstream content;
	wordlist.open(inputfile_path, ios::in);
	content << wordlist.rdbuf();
	readin = content.str();
	return true;
}

void InputHandler::handle_readin() {
	string word="";
	for (int i = 0; i < readin.size(); i++) {
		if (('a' <= readin[i] && 'z' >= readin[i]) ||
			('A' <= readin[i] && 'Z' >= readin[i])) {
				word += readin[i];			
		}
		else {
			if (word.size() == 0) {
				continue;
			}
			else
			{
				word_list.push_back(word);
				word = "";
			}
		}
	}
}


void InputHandler::clear_duplicate() {
	sort(word_list.begin(), word_list.end());
	word_list.erase(unique(word_list.begin(), word_list.end()), word_list.end());

}

void InputHandler::handle_parameters(int para_num,vector<string> para) {
	for (int i = 0; i < para_num; i++) {
		if (para[i] == "-w" && i<para_num-1) {
			inputfile_path = para[i + 1];
		}
		if (para[i] == "-c" && i < para_num - 1) {
			inputfile_path = para[i + 1];
		}
		if (para[i] == "-h" && i < para_num - 1) {
			head_ch = para[i + 1][0];
		}
		if (para[i] == "-t" && i < para_num - 1) {
			tail_ch = para[i + 1][0];
		}
		if (para[i] == "-r") {
			enable_loop = true;
		}
	}
}