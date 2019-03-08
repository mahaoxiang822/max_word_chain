#include "stdafx.h"
#include "CppUnitTest.h"
#include "../max_word_chain/Core.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest1
{	
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
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			char *answer1[] = { "abc","cbd","dbbw","wxx" };
			int word_num = 7;
			int answer_num = 4;
			char **results1 = new char*[word_num + 1];
			Core core;
			int res = core.gen_chain_word(test_list1, word_num, results1, 0, 0, false);
			Assert::IsTrue(judge(core.array2string(results1,res), core.array2string(answer1,answer_num)));
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
			char *answer2[] = { "dbbw", "wxx" };
			int res = core.gen_chain_word(test_list1, 7, results2, 'd', 0, false);
			//output(results, res);
			Assert::IsTrue(judge(core.array2string(results2, res), core.array2string(answer2, 2)));
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
			char *answer3[] = { "abc","cbd","dbbw"};
			int res = core.gen_chain_word(test_list1, word_num, results3, 0, 'w', false);
			Assert::IsTrue(judge(core.array2string(results3, res), core.array2string(answer3, answer_num)));
		}
		TEST_METHOD(TestMethod4) {
			Core core;
			int word_num = 8;
			int answer_num = 4;
			char **results4 = new char*[word_num + 1];
			char *answer4[] = { "room", "mazhenya", "apple", "elephant" };
			int res = core.gen_chain_word(test_list2, word_num, results4, 0, 0, false);
			Assert::IsTrue(judge(core.array2string(results4, res), core.array2string(answer4, answer_num)));
		}
		TEST_METHOD(TestMethod5) { 
			Core core;
			int word_num = 8;
			int answer_num = 3;
			char **results5 = new char*[word_num + 1];
			char *answer5[] = { "mazhenya", "apple", "elephant" };
			int res = core.gen_chain_char(test_list2, word_num, results5, 'm', 't', false);
			Assert::IsTrue(judge(core.array2string(results5, res), core.array2string(answer5, answer_num)));
		}
		TEST_METHOD(TestMethod6) {// -c ÒÔt½áÎ²
			Core core;
			int word_num = 8;
			int answer_num = 2;
			char **results = new char*[word_num + 1];
			char *answer[] = { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzorange", "elephant" };
			int res = core.gen_chain_char(test_list2, word_num, results, 0, 't', false);
			Assert::IsTrue(judge(core.array2string(results, res), core.array2string(answer, answer_num)));
		}
		TEST_METHOD(TestMethod7) {
			Core core;
			int word_num = 8;
			int answer_num = 2;
			char **results = new char*[word_num + 1];
			char *answer[] = { "mahaoxiang","gxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};
			int res = core.gen_chain_char(test_list2, word_num, results, 'm', 0, false);
			Assert::IsTrue(judge(core.array2string(results, res), core.array2string(answer, answer_num)));
		}
		TEST_METHOD(TestMethod8) {
			Core core;
			int word_num = 9;
			int answer_num = 5;
			char **results = new char*[word_num + 1];
			char *answer[] = { "uv","vw","wx","xy","yz" };
			int res = core.gen_chain_word(test_list3, word_num, results, 0, 0, true);
			//output(results, res);
			Assert::IsTrue(judge(core.array2string(results, res), core.array2string(answer, answer_num)));
		}

		TEST_METHOD(TestMethod9) {
			Core core;
			int word_num = 9;
			int answer_num = 4;
			char **results = new char*[word_num + 1];
			char *answer[] = { "abc","cbd","ddb","bba" };
			int res = core.gen_chain_word(test_list3, word_num, results, 0, 'a', true);
			//output(results, res);
			Assert::IsTrue(judge(core.array2string(results, res), core.array2string(answer, answer_num)));
		}
		TEST_METHOD(TestMethod10) {
			Core core;
			int word_num = 9;
			int answer_num = 4;
			char **results = new char*[word_num + 1];
			int res = core.gen_chain_word(test_list3, word_num, results, 0, 0,false);
			Assert::IsTrue(res == -1);
		}
	};
}