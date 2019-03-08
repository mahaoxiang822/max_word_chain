// max_word_chain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "InputHandler.h"
#include "Core.h"
#include <iostream>
using namespace std;
bool judge(vector<string > in, vector<string> ans) {
	if (in.size() != ans.size())
		return false;
	int len = (int)in.size();
	bool same = true;
	for (int i = 0; i < len; i++) {
		if (in[i] != ans[i])
			same = false;
	}
	if (same)
		return true;
	return false;
}

void output(char *res[], int len) {
	cout << "-----------------------" << endl;
	for (int i = 0; i < len; i++) {
		cout << res[i] << endl;
	}
}
/*char *test_list1[] = { "abc","cbd","dbbw","csw","zde","opl","wxx" };
char *test_list2[] = { "room", "mazhenya", "apple", "elephant","mahaoxiang","gxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", "zzzzzzzzzzzzzzzzzzzzzzzzzzzzorange","peanut" };
char *test_list3[] = { "abc","cbd","bba","ddb","yz","uv","wx","vw","xy" };*/
int main(int argc, char* argv[])
{
	/*vector<string> para;
	vector<string> result;
	InputHandler inputhanler;
	Core core;
	for (int i = 0; i < argc; i++) {
		para.push_back(argv[i]);
	}
	inputhanler.handle_parameters(argc, para);
	inputhanler.file_read();
	inputhanler.handle_readin();
	inputhanler.clear_duplicate();
	core.max_chain_word(inputhanler.word_list, result, inputhanler.head_ch, inputhanler.tail_ch, inputhanler.enable_loop);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<<endl;
	}*/
	/*Core core;
	int word_num = 8;
	int answer_num = 3;
	char **results5 = new char*[word_num + 1];
	char *answer5[] = { "mazhenya", "apple", "elephant" };
	int res = core.gen_chain_char(test_list2, word_num, results5, 'm', 't', false);
	assert(judge(core.array2string(results5, res), core.array2string(answer5, answer_num)));*/
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
