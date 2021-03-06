// max_word_chain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "../Core/Core.h"
#include "../Core/Solve.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

vector<string> word_list;
string readin = "";
bool enable_loop = false;
int mode = -1;//mode=0最多单词 mode=1最长单词
char head_ch = 0;
char tail_ch = 0;
string inputfile_path = "";

vector<string> array2string(char *words[], int len) {
	vector<string> res;
	string s;
	for (int i = 0; i < len; i++) {
		s = words[i];
		res.push_back(s);
	}
	return res;
}
int string2array(vector<string> string_list, char *words[]) {//返回长度
	int size = (int)string_list.size();
	for (int i = 0; i < size; i++) {
		int len = string_list[i].length();
		words[i] = new char[len + 3];
		strcpy_s(words[i], len + 3, string_list[i].c_str());
	}
	return size;
}
bool console_read() {
	return true;
}

bool file_read() {

	ifstream wordlist;
	ostringstream content;
	try {
		wordlist.open(inputfile_path, ios::in);
		if (!wordlist.is_open()) {
			throw("file can't open");
		}
		content << wordlist.rdbuf();
		readin = content.str();
	}
	catch (...) {
		throw("file read exception");
	}
	return true;
}

void string_read(string input) {
	try {
		readin = input;
	}
	catch (...) {
		throw("gui input exception");
	}
}

void handle_readin() {
	string word = "";
	try {
		for (int i = 0; i < (int) readin.size(); i++) {
			if (('a' <= readin[i] && 'z' >= readin[i]) ||
				('A' <= readin[i] && 'Z' >= readin[i])) {
				char temp = readin[i];
				if ('A' <= temp && 'Z' >= temp) {
					temp = temp - ('A' - 'a');
				}
				word += temp;
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
		if (word.size() != 0) {
			word_list.push_back(word);
			word = "";
		}
	}
	catch (...) {
		throw("handle readin exception");
	}
}


void clear_duplicate() {
	try {
		sort(word_list.begin(), word_list.end());
		word_list.erase(unique(word_list.begin(), word_list.end()), word_list.end());
	}
	catch (...) {
		throw("clear duplicate word exception");
	}

}

void handle_parameters(int para_num, vector<string> para) {
	bool if_h =false;
	bool if_t = false;
	try {
		for (int i = 1; i < para_num; i++) {
			if (para[i] == "-w" && i < para_num - 1&& mode == -1) {
				mode = 0;
				inputfile_path = para[i + 1];
				i++;
				continue;
			}
			else if (para[i] == "-c" && i < para_num - 1 && mode == -1) {
				mode = 1;
				inputfile_path = para[i + 1];
				i++;
				continue;
			}
			else if (para[i] == "-h" && i < para_num - 1 && !if_h) {
				head_ch = para[i + 1][0];
				if_h = true;
				i++;
				continue;
			}
			else if (para[i] == "-t" && i < para_num - 1) {
				tail_ch = para[i + 1][0];
				if_t = true;
				i++;
				continue;
			}
			else if (para[i] == "-r") {
				enable_loop = true;
			}
			else {
				throw("wrong parameter");
			}
		}
	}
	catch (...) {
		throw("handle parameters error");
	}
	if (mode == -1) {
		throw ("havnt choose the mode");
	}

}

int main(int argc, char* argv[])
{
	vector<string> para;
	vector<string> result;
	ofstream solution;
	char ** in_word;
	char ** res;
	try {
		for (int i = 0; i < argc; i++) {
			para.push_back(argv[i]);
		}
	}
	catch (...) {
		cout<<"read para exception"<<endl;
	}
	try {
		solution.open("solution.txt", ios::out);
		handle_parameters(argc, para);
		file_read();
		handle_readin();
		clear_duplicate();
		int len =(int) word_list.size();
		in_word = new char*[len + 5];
		res = new char*[len + 5];
		string2array(word_list,in_word );
		int res_len = 0;
		if (mode == 0) {
			res_len=Core::gen_chain_word(in_word, len, res, head_ch, tail_ch, enable_loop);
		}
		else if (mode == 1) {
			res_len = Core::gen_chain_char(in_word, len, res, head_ch, tail_ch, enable_loop);
		}
		
		result = array2string(res, res_len);
	}
	catch (const char* error_message) {
		cout << error_message << endl;
	}
	try {
		for (int i = 0; i < (int) result.size(); i++) {
			cout << result[i] << endl;
			solution << result[i] << endl;
		}
		solution.close();
	}
	catch (...) {
		cout << "output exception" << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
