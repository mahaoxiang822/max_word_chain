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
}

bool InputHandler::console_read() {
	return true;
}

bool InputHandler::file_read(string filename) {
	ifstream wordlist;
	ostringstream content;
	wordlist.open(filename, ios::in);
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
	for (int i = 0; i < word_list.size(); i++) {
		cout << word_list[i] << endl;
	}
}