// max_word_chain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "InputHandler.h"
#include "Core.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
int main(int argc, char* argv[])
{
	vector<string> para;
	vector<string> result;
	InputHandler inputhanler;
	Core core;
	ofstream solution;
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
		inputhanler.handle_parameters(argc, para);
		inputhanler.file_read();
		inputhanler.handle_readin();
		inputhanler.clear_duplicate();
		core.max_chain_word(inputhanler.word_list, result, inputhanler.head_ch, inputhanler.tail_ch, inputhanler.enable_loop);
	}
	catch (const char* error_message) {
		cout << error_message << endl;
	}
	try {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
			solution << result[i] << endl;
		}
		solution.close();
	}
	catch (...) {
		cout << "output exception" << endl;
	}
}*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
