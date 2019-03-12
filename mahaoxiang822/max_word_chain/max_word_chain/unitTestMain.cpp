#include "pch.h"
#include "Core.h"
using namespace std;
#define TEST_METHOD(x) void x()
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

const char *test_list1[] = { "abc","cbd","dbbw","csw","zde","opl","wxx" };
const char *test_list2[] = { "room", "mazhenya", "apple", "elephant","mahaoxiang","gxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", "zzzzzzzzzzzzzzzzzzzzzzzzzzzzorange","peanut" };
const char *test_list3[] = { "abc","cbd","bba","ddb","yz","uv","wx","vw","xy" };
const char *test_list4[] = { "xppppy", "fb","ef","bc","de","cd","zpppb","yppppz" };
const char *test_list5[] = { "xppppy", "fb","ef","bc","ft","tb","zpppb","yppppz" };
const char *test_list6[] = { "xppppy", "ce","ef","bc","de","cd","zpppb","yppppz" };
const char *test_list7[] = { "tppppppppz","zppppppppx","ab","ef","bc","de","cd" };
const char *test_list8[] = { "ac","bz","cb","cc" };
const char *test_list9[] = { "ac","bc","cb","cc" };//有环
const char *test_list10[] = { "cx","xy","bc","zd","yz","ab","de","cpppppppppppppppppppd" };
const char *test_list11[] = { "abc", "abc", "xyz" };
TEST_METHOD(TestMethod1)
{

	const char *answer1[] = { "abc","cbd","dbbw","wxx" };
	int word_num = 7;
	int answer_num = 4;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_word((char **)test_list1, word_num, results1, 0, 0, false);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}

TEST_METHOD(TestMethod2)
{ 
	Core core;
	int word_num = 7;
	int answer_num = 2;
	char **results2 = new char*[word_num + 1];
	const char *answer2[] = { "dbbw", "wxx" };
	int res = core.gen_chain_word((char **)test_list1, 7, results2, 'd', 0, true);
	//output(results, res);
	assert(judge(core.array2string(results2, res), core.array2string((char **)answer2, 2)));
	/*for (int i = 0; i < word_num; i++)
		delete[] results[i];
	delete[] results;*/
}

TEST_METHOD(TestMethod3)
{
	Core core;
	int word_num = 7;
	int answer_num = 3;
	char **results3 = new char*[word_num + 1];
	const char *answer3[] = { "abc","cbd","dbbw" };
	int res = core.gen_chain_word((char **)test_list1, word_num, results3, 0, 'w', false);
	assert(judge(core.array2string(results3, res), core.array2string((char **)answer3, answer_num)));
}
TEST_METHOD(TestMethod4) {
	Core core;
	int word_num = 8;
	int answer_num = 4;
	char **results4 = new char*[word_num + 1];
	const char *answer4[] = { "room", "mazhenya", "apple", "elephant" };
	int res = core.gen_chain_word((char **)test_list2, word_num, results4, 0, 0, false);
	assert(judge(core.array2string(results4, res), core.array2string((char **)answer4, answer_num)));
}
TEST_METHOD(TestMethod5) {
	Core core;
	int word_num = 8;
	int answer_num = 3;
	char **results5 = new char*[word_num + 1];
	const char *answer5[] = { "mazhenya", "apple", "elephant" };
	int res = core.gen_chain_char((char **)test_list2, word_num, results5, 'm', 't', false);
	assert(judge(core.array2string(results5, res), core.array2string((char **)answer5, answer_num)));
}
TEST_METHOD(TestMethod6) {// -c 以t结尾
 
	Core core;
	int word_num = 8;
	int answer_num = 2;
	char **results = new char*[word_num + 1];
	const char *answer[] = { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzorange", "elephant" };
	int res = core.gen_chain_char((char **)test_list2, word_num, results, 0, 't', false);
	assert(judge(core.array2string(results, res), core.array2string((char **)answer, answer_num)));
}
TEST_METHOD(TestMethod7) {
	Core core;
	int word_num = 8;
	int answer_num = 2;
	char **results = new char*[word_num + 1];
	const char *answer[] = { "mahaoxiang","gxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" };
	int res = core.gen_chain_char((char **)test_list2, word_num, results, 'm', 0, false);
	assert(judge(core.array2string(results, res), core.array2string((char **)answer, answer_num)));
}
TEST_METHOD(TestMethod8) {
	Core core;
	int word_num = 9;
	int answer_num = 5;
	char **results = new char*[word_num + 1];
	const char *answer[] = { "uv","vw","wx","xy","yz" };
	int res = core.gen_chain_word((char **)test_list3, word_num, results, 0, 0, true);
	//output(results, res);
	assert(judge(core.array2string(results, res), core.array2string((char **)answer, answer_num)));
}

TEST_METHOD(TestMethod9) {
	Core core;
	int word_num = 9;
	int answer_num = 4;
	char **results = new char*[word_num + 1];
	const char *answer[] = { "abc","cbd","ddb","bba" };
	int res = core.gen_chain_word((char **)test_list3, word_num, results, 0, 'a', true);
	//output(results, res);
	assert(judge(core.array2string(results, res), core.array2string((char **)answer, answer_num)));
}
TEST_METHOD(TestMethod10) {
	try {
		Core core;
		int word_num = 9;
		int answer_num = 4;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_word((char **)test_list3, word_num, results, 0, 0, false);
	}catch (const char*  s) {
		assert(strcmp(s, LOOP_ERROR) == 0);
		cout << s << endl;
	}
	try {
		Core core;
		int word_num = 9;
		int answer_num = 4;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_char((char **)test_list3, word_num, results, 0, 0, false);
	}catch (const char*  s) {
		assert(strcmp(s, LOOP_ERROR) == 0);
		//assert(s == LOOP_ERROR);
		cout << s << endl;
	}
	try {
		Core core;
		int word_num = 9;
		int answer_num = 4;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_char((char **)test_list3, word_num, results, '+', '-', true);
	}catch (const char*  s) {
		assert(strcmp(s, TAIL_CHAR_ERROR) == 0);
		//assert(s == LOOP_ERROR);
		cout << s << endl;
	}
	try {
		Core core;
		int word_num = 9;
		int answer_num = 4;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_char((char **)test_list3, word_num, results, '-', 0, true);
	}catch (const char*  s) {
		assert(strcmp(s, HEAD_CHAR_ERROR) == 0);
		//Assert::IsTrue(s == LOOP_ERROR);
		cout << s << endl;
	}
}

/*TEST_METHOD(TestMethod11) {
	try {
		Core core;
		int word_num = 9;
		int answer_num = 4;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_word(test_list3, word_num + 13, results, 0, 0, false);
	}
	catch (const char* s) {
		//assert(s == MEMORY_ERROR);
		assert(strcmp(s, MEMORY_ERROR)==0);
		cout << s << endl;
	}
}*/
TEST_METHOD(TestMethod12) {
	const char *test_list[] = { "happ1we2", "yuer", "opui8op" };
	try {
		Core core;
		int word_num = 3;
		int answer_num = 0;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_word((char **)test_list, word_num, results, 0, 0, false);
	}	catch (const char* s) {
		//assert(s == WORD_ILLEGAL);
		assert(strcmp(s, WORD_ILLEGAL) == 0);
		cout << s << endl;
	}
	try {
		Core core;
		int word_num = 3;
		int answer_num = 0;
		char **results = new char*[word_num + 1];
		int res = core.gen_chain_char((char **)test_list, word_num, results, 0, 0, false);
	}	catch (const char* s) {
		//assert(s == WORD_ILLEGAL);
		assert(strcmp(s, WORD_ILLEGAL) == 0);
		cout << s << endl;
	}
}
TEST_METHOD(TestMethod13)
{
	const char *answer1[] = { "xppppy","yppppz","zpppb","bc","cd","de","ef","fb" };
	int word_num = 8;
	int answer_num = 8;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_word((char **)test_list4, word_num, results1, 0, 0, true);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod14)
{
	const char *answer1[] = { "xppppy","yppppz","zpppb","bc" };
	int word_num = 8;
	int answer_num = 4;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_word((char **)test_list5, word_num, results1, 0, 0, false);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod15)
{
	const char *answer1[] = { "xppppy","yppppz","zpppb","bc","cd","de","ef" };
	int word_num = 8;
	int answer_num = 7;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_word((char **)test_list6, word_num, results1, 0, 0, false);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod17)
{
	const char *answer1[] = { "ab", "bc", "cd", "de", "ef" };
	int word_num = 7;
	int answer_num = 5;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_word((char **)test_list7, word_num, results1, 0, 0, true);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod18)
{
	const char *answer1[] = { "tppppppppz", "zppppppppx" };
	int word_num = 7;
	int answer_num = 2;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_char((char **)test_list7, word_num, results1, 0, 0, true);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod19)
{
	const char *answer1[] = { "ac", "cc", "cb","bz" };
	int word_num = 4;
	int answer_num = 4;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_char((char **)test_list8, word_num, results1, 0, 0, false);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod20)
{
	const char *answer1[] = { "ac", "cb", "bc", "cc" };
	int word_num = 4;
	int answer_num = 4;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_char((char **)test_list9, word_num, results1, 0, 0, true);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod21)
{
	const char *answer1[] = { "ab", "bc", "cx","xy","yz","zd","de" };
	int word_num = 8;
	int answer_num = 7;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_word((char **)test_list10, word_num, results1, 0, 0, true);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod22)
{
	const char *answer1[] = { "ab", "bc", "cpppppppppppppppppppd","de" };
	int word_num = 8;
	int answer_num = 4;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_char((char **)test_list10, word_num, results1, 0, 0, true);
	assert(judge(core.array2string(results1, res), core.array2string((char **)answer1, answer_num)));
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod23)
{
	int word_num = 3;
	int answer_num = 0;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_char((char **)test_list11, word_num, results1, 0, 0, true);
	assert(res == 0);
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
TEST_METHOD(TestMethod24)
{
	char *test_list12[1];
	int word_num = 0;
	int answer_num = 0;
	char **results1 = new char*[word_num + 1];
	Core core;
	int res = core.gen_chain_char(test_list12, word_num, results1, 0, 0, true);
	assert(res == 0);
	for (int i = 0; i < res; i++)
		delete[] results1[i];
	delete[] results1;
}
int main()
{
	
	TestMethod1();
	TestMethod2();
	TestMethod3();
	TestMethod4();
	TestMethod5();
	TestMethod6();
	TestMethod7();
	TestMethod8();
	TestMethod9();
	TestMethod10();
	TestMethod12();
	TestMethod13();
	TestMethod14();
	TestMethod15();
	TestMethod17();
	TestMethod18();
	TestMethod19();
	TestMethod20();
	TestMethod21();
	TestMethod22();
	TestMethod23();
	TestMethod24();









	return 0;
}