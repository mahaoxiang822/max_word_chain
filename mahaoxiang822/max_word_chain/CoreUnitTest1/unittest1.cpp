#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/Core.h"
#include "../Core/Solve.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest1
{	
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
	
	char *test_list1[] = { "abc","cbd","dbbw","csw","zde","opl","wxx" };
	char *test_list2[] = {"room", "mazhenya", "apple", "elephant","mahaoxiang","gxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", "zzzzzzzzzzzzzzzzzzzzzzzzzzzzorange","peanut"};
	char *test_list3[] = {"abc","cbd","bba","ddb","yz","uv","wx","vw","xy"};
	char *test_list4[] = { "xppppy", "fb","ef","bc","de","cd","zpppb","yppppz" };
	char *test_list5[] = { "xppppy", "fb","ef","bc","ft","tb","zpppb","yppppz" };
	char *test_list6[] = { "xppppy", "ce","ef","bc","de","cd","zpppb","yppppz" };
	char *test_list7[] = { "tppppppppz","zppppppppx","ab","ef","bc","de","cd" };
	char *test_list8[] = { "ac","bz","cb","cc" };
	char *test_list9[] = { "ac","bc","cb","cc" };//有环
	char *test_list10[] = { "cx","xy","bc","zd","yz","ab","de","cpppppppppppppppppppd" };
	char *test_list11[] = {"abc", "abc", "xyz"};
	
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			char *answer1[] = { "abc","cbd","dbbw","wxx" };
			int word_num = 7;
			int answer_num = 4;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_word(test_list1, word_num, results1, 0, 0, false);
			Assert::IsTrue(judge(array2string(results1,res), array2string(answer1,answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}

		TEST_METHOD(TestMethod2)
		{
			int word_num = 7;
			int answer_num = 2;
			char **results2 = new char*[word_num + 1];
			char *answer2[] = { "dbbw", "wxx" };
			int res = Core::gen_chain_word(test_list1, 7, results2, 'd', 0, false);
			Assert::IsTrue(judge(array2string(results2, res), array2string(answer2, 2)));
		}

		TEST_METHOD(TestMethod3)
		{
			int word_num = 7;
			int answer_num = 3;
			char **results3 = new char*[word_num + 1];
			char *answer3[] = { "abc","cbd","dbbw"};
			int res = Core::gen_chain_word(test_list1, word_num, results3, 0, 'w', false);
			Assert::IsTrue(judge(array2string(results3, res), array2string(answer3, answer_num)));
		}
		TEST_METHOD(TestMethod4) {
			int word_num = 8;
			int answer_num = 4;
			char **results4 = new char*[word_num + 1];
			char *answer4[] = { "room", "mazhenya", "apple", "elephant" };
			int res = Core::gen_chain_word(test_list2, word_num, results4, 0, 0, false);
			Assert::IsTrue(judge(array2string(results4, res), array2string(answer4, answer_num)));
		}
		TEST_METHOD(TestMethod5) { 
			int word_num = 8;
			int answer_num = 3;
			char **results5 = new char*[word_num + 1];
			char *answer5[] = { "mazhenya", "apple", "elephant" };
			int res = Core::gen_chain_char(test_list2, word_num, results5, 'm', 't', false);
			Assert::IsTrue(judge(array2string(results5, res), array2string(answer5, answer_num)));
		}
		TEST_METHOD(TestMethod6) {// -c 以t结尾
			int word_num = 8;
			int answer_num = 2;
			char **results = new char*[word_num + 1];
			char *answer[] = { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzorange", "elephant" };
			int res = Core::gen_chain_char(test_list2, word_num, results, 0, 't', false);
			Assert::IsTrue(judge(array2string(results, res), array2string(answer, answer_num)));
		}
		TEST_METHOD(TestMethod7) {
			int word_num = 8;
			int answer_num = 2;
			char **results = new char*[word_num + 1];
			char *answer[] = { "mahaoxiang","gxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};
			int res = Core::gen_chain_char(test_list2, word_num, results, 'm', 0, false);
			Assert::IsTrue(judge(array2string(results, res), array2string(answer, answer_num)));
		}
		TEST_METHOD(TestMethod8) {
			int word_num = 9;
			int answer_num = 5;
			char **results = new char*[word_num + 1];
			char *answer[] = { "uv","vw","wx","xy","yz" };
			int res = Core::gen_chain_word(test_list3, word_num, results, 0, 0, true);
			//output(results, res);
			Assert::IsTrue(judge(array2string(results, res), array2string(answer, answer_num)));
		}

		TEST_METHOD(TestMethod9) {
			int word_num = 9;
			int answer_num = 4;
			char **results = new char*[word_num + 1];
			char *answer[] = { "abc","cbd","ddb","bba" };
			int res = Core::gen_chain_word(test_list3, word_num, results, 0, 'a', true);
			//output(results, res);
			Assert::IsTrue(judge(array2string(results, res), array2string(answer, answer_num)));
		}
		TEST_METHOD(TestMethod10) {
			try {
				int word_num = 9;
				int answer_num = 4;
				char **results = new char*[word_num + 1];
				int res = Core::gen_chain_word(test_list3, word_num, results, 0, 0, false);
				Assert::IsTrue(res == -1);
			}
			catch (const char*  s) {
				Assert::IsTrue(strcmp(s, LOOP_ERROR) == 0);
				//Assert::IsTrue(s == LOOP_ERROR);
				cout << s << endl;
			}
			try {
				int word_num = 9;
				int answer_num = 4;
				char **results = new char*[word_num + 1];
				int res = Core::gen_chain_char(test_list3, word_num, results, 0, 0, false);
				Assert::IsTrue(res == -1);
			}
			catch (const char*  s) {
				Assert::IsTrue(strcmp(s, LOOP_ERROR) == 0);
				//Assert::IsTrue(s == LOOP_ERROR);
				cout << s << endl;
			}
			try {
				int word_num = 9;
				int answer_num = 4;
				char **results = new char*[word_num + 1];
				int res = Core::gen_chain_char(test_list3, word_num, results, '+', '-', true);
				Assert::IsTrue(res == -1);
			}
			catch (const char*  s) {
				Assert::IsTrue(strcmp(s, TAIL_CHAR_ERROR) == 0);
				//Assert::IsTrue(s == LOOP_ERROR);
				cout << s << endl;
			}
			try {
				int word_num = 9;
				int answer_num = 4;
				char **results = new char*[word_num + 1];
				int res = Core::gen_chain_char(test_list3, word_num, results,  '-',0, true);
				Assert::IsTrue(res == -1);
			}
			catch (const char*  s) {
				Assert::IsTrue(strcmp(s, HEAD_CHAR_ERROR) == 0);
				cout << s << endl;
			}
		}
		TEST_METHOD(TestMethod12) {
			char *test_list[] = {"happ1we2", "yuer", "opui8op"};
			try {
				int word_num = 3;
				int answer_num = 0;
				char **results = new char*[word_num + 1];
				int res = Core::gen_chain_word(test_list, word_num, results, 0, 0, false);
			}
			catch (const char* s) {
				Assert::IsTrue(strcmp(s, WORD_ILLEGAL)==0);
				cout << s << endl;
			}
			try {
				int word_num = 3;
				int answer_num = 0;
				char **results = new char*[word_num + 1];
				int res = Core::gen_chain_char(test_list, word_num, results, 0, 0, false);
			}
			catch (const char* s) {
				Assert::IsTrue(strcmp(s, WORD_ILLEGAL) == 0);
				cout << s << endl;
			}
		}
		TEST_METHOD(TestMethod13)
		{
			char *answer1[] = { "xppppy","yppppz","zpppb","bc","cd","de","ef","fb" };
			int word_num = 8;
			int answer_num = 8;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_word(test_list4, word_num, results1, 0, 0, true);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod14)
		{
			char *answer1[] = { "xppppy","yppppz","zpppb","bc"};
			int word_num = 8;
			int answer_num = 4;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_word(test_list5, word_num, results1, 0, 0, false);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod15)
		{
			char *answer1[] = { "xppppy","yppppz","zpppb","bc","cd","de","ef" };
			int word_num = 8;
			int answer_num = 7;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_word(test_list6, word_num, results1, 0, 0, false);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod17)
		{
			char *answer1[] = { "ab", "bc", "cd", "de", "ef" };
			int word_num = 7;
			int answer_num = 5;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_word(test_list7, word_num, results1, 0, 0, true);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod18)
		{
			char *answer1[] = { "tppppppppz", "zppppppppx" };
			int word_num = 7;
			int answer_num = 2;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_char(test_list7, word_num, results1, 0, 0, true);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod19)
		{
			char *answer1[] = { "ac", "cc", "cb","bz" };
			int word_num = 4;
			int answer_num = 4;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_char(test_list8, word_num, results1, 0, 0, false);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod20)
		{
			char *answer1[] = { "ac", "cb", "bc", "cc" };
			int word_num = 4;
			int answer_num = 4;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_char(test_list9, word_num, results1, 0, 0, true);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod21)
		{
			char *answer1[] = {"ab", "bc", "cx","xy","yz","zd","de" };
			int word_num = 8;
			int answer_num = 7;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_word(test_list10, word_num, results1, 0, 0, true);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod22)
		{
			char *answer1[] = { "ab", "bc", "cpppppppppppppppppppd","de" };
			int word_num = 8;
			int answer_num = 4;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_char(test_list10, word_num, results1, 0, 0, true);
			Assert::IsTrue(judge(array2string(results1, res), array2string(answer1, answer_num)));
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
		TEST_METHOD(TestMethod23)
		{
			int word_num = 3;
			int answer_num = 0;
			char **results1 = new char*[word_num + 1];
			int res = Core::gen_chain_char(test_list11, word_num, results1, 0, 0, true);
			Assert::IsTrue(res==0);
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
			int res = Core::gen_chain_char(test_list12, word_num, results1, 0, 0, true);
			Assert::IsTrue(res == 0);
			for (int i = 0; i < res; i++)
				delete[] results1[i];
			delete[] results1;
		}
	};
}