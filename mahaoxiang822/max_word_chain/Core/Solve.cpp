// Core::cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream>
#include "stdc++.h"
#include "Solve.h"
using namespace std;



bool check_word_legal(vector<string> word_list) {
	int size = word_list.size();
	for (int i = 0; i < size; i++) {
		string s = word_list[i];
		for (int j = 0; j <(int) s.length(); j++) {
			if (!(s[j] >= 'a' &&s[j] <= 'z'))
				return false;
		}
	}
	return true;
}

void Solver::form_digraph(vector<string> word_list) {
	this->word_list.clear();
	this->digraph.clear();
	int word_id = 0;
	for (auto it = word_list.begin(); it != word_list.end(); it++) {//遍历所有的单词，统计单词的长度
		this->word_list.push_back(word_info{ *it, (int)(*it).length() });
		char head_char = (*it)[0];
		head_char_list[head_char].push_back(word_id);//将单词按照头字母放入
		word_id++;
	}
	in_degree = *(new vector<int>(word_id));
	word_id = 0;
	for (auto it = word_list.begin(); it != word_list.end(); it++) {
		char tail_char = (*it).back();
		tail_char_list[tail_char].push_back(word_id);//单词按照末尾字母进行分类
		for (auto nit = head_char_list[tail_char].begin(); nit != head_char_list[tail_char].end(); nit++) {
			if ((*nit) != word_id) {
				digraph[word_id].push_back(*nit);
				in_degree[*nit]++;//将相关单词的入度加1
			}
		}
		word_id++;
	}
}

void Solver::remove_node(int v_id, vector<int > &degree) {
	for (auto it = digraph[v_id].begin(); it != digraph[v_id].end(); it++) {
		if (degree[*it] > 0)
			degree[*it]--;
	}
}

bool Solver::has_loop() {
	int word_num = (int)word_list.size();
	vector<int > in_degree_copy = in_degree;
	// step 1, if there doesn't exist a node whose indegree is 0, then has loop;
	vector<int> indegree_zero_id;
	for (int i = 0; i < word_num; i++)
		if (in_degree[i] == 0)
			indegree_zero_id.push_back(i);
	if (indegree_zero_id.size() == 0)
		return true;

	// continue to use sort
	vector<int > stack;
	while (!indegree_zero_id.empty()) {
		for (auto it = indegree_zero_id.begin(); it != indegree_zero_id.end(); it++) {
			stack.push_back(*it);
			remove_node(*it, in_degree_copy);
		}
		indegree_zero_id.clear();
		for (int i = 0; i < word_num; i++)
			if (in_degree_copy[i] == 0 && find(stack.begin(), stack.end(), i) == stack.end())
				indegree_zero_id.push_back(i);
	}
	//while (!stack.empty()) {
		//cout << stack.back()<<endl;
	//	stack.pop_back();
	//}
	if (stack.size() != word_num)
		return true;
	return false;
}

bool Solver::SPFA(char start_char, bool set_start, char tail_char, bool set_end, bool longest_word)
{
	int t;
	vector<int> start_set;
	int word_num = (int)word_list.size();
	queue<int> Q;
	vector<bool> visited(word_num);
	vector<int> dist(word_num);
	vector<int> path(word_num);
	for (int i = 0; i < word_num; i++) {
		visited[i] = false;
		dist[i] = 0;
	}
	if (!set_start) {//找所有入度为0的点放入start_set之中
		start_set.clear();
		for (int i = 0; i < word_num; i++)
			if (in_degree[i] == 0)
				start_set.push_back(i);
	}
	else
		start_set = head_char_list[start_char];
	for (auto it = start_set.begin(); it != start_set.end(); it++) {
		Q.push(*it);
		visited[*it] = true;
		dist[*it] = (longest_word) ? 1 : word_list[*it].length;
		path[*it] = -1;
	}
	//算出虚拟起点到所有点的最长路径
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		visited[t] = false;
		for (auto it = digraph[t].begin(); it != digraph[t].end(); it++) {
			int edge_v = (longest_word) ? 1 : word_list[*it].length;
			if (dist[t] + edge_v > dist[*it]) {
				dist[*it] = dist[t] + edge_v;
				path[*it] = t;
				if (!visited[*it]) {
					Q.push(*it);
					visited[*it] = true;
				}
			}
		}
	}
	//找出想要的答案
	int max_chain = 0;
	int index = -1;
	if (!set_end) {
		for (int i = 0; i < word_num; i++) {
			if (dist[i] > max_chain) {
				max_chain = dist[i];
				index = i;
			}
		}
	}
	else {
		for (auto it = tail_char_list[tail_char].begin(); it != tail_char_list[tail_char].end(); it++) {
			if (dist[*it] > max_chain) {
				max_chain = dist[*it];
				index = *it;
			}
		}
	}
	// find the whole path
	vector<int> stack;
	while (index != -1) {
		stack.push_back(index);
		index = path[index];
	}
	while (!stack.empty()) {
		if (longest_word)
			result_list_word.push_back(word_list[stack.back()].word);
		else
			result_list_char.push_back(word_list[stack.back()].word);
		//cout << word_list[stack.back()].word << endl;
		stack.pop_back();
	}

	/*for (int i = 0; i < word_num; i++) {
		cout << "word: "<<word_list[i].word <<endl;
		cout << "dist:" <<dist[i] << endl;
		cout << path[i] << endl;
		cout << "-----------------------" << endl;
	}*/
	return true;
}
bool  Solver::node_in_path(vector<int> path, int v_id, int now_id) {
	int index = now_id;
	while (index != -1) {
		if (index == v_id) return true;
		index = path[index];

	}
	return false;
}

//终止条件有两个，一个是这个节点没有出度为0，另外一个是此时想要访问的点之前已经被访问过了
void Solver::dfs(int v_id, vector<bool> &visit, vector<int> &path, vector<int> &dist, bool longest_word) {
	//cout << v_id << "  last: " << path[v_id] <<"dist: "<< dist[v_id]<< endl;
	visit[v_id] = true;
	for (auto it = digraph[v_id].begin(); it != digraph[v_id].end(); it++) {
		if (!visit[*it]) {
			int edge_v = (longest_word) ? 1 : word_list[*it].length;
			if (dist[v_id] + edge_v > dist[*it] && !node_in_path(path, *it, v_id)) {//更新的时候需要同时保证
				path[*it] = v_id;
				dist[*it] = dist[v_id] + edge_v;
			}
			dfs(*it, visit, path, dist, longest_word);
		}
	}
	visit[v_id] = false;
}

void Solver::loop_max_chain(char start_char, bool set_start, char end_set, bool set_end, bool longest_word) {
	int word_num = (int)word_list.size();
	vector<int> start_set;
	map<int, vector<int>> path;
	vector<bool> visit(word_num);
	map<int, vector<int>> dist;
	for (int i = 0; i < word_num; i++) {//设置初始值
		visit[i] = false;
	}

	if (set_start)
		start_set = head_char_list[start_char];
	else {
		for (int i = 0; i < word_num; i++)
			start_set.push_back(i);
	}

	//设置start_set中的长度是本身长度，路径上一个点是-1,进行dfs遍历的时候也是从start_set中的点开始遍历
	for (auto it = start_set.begin(); it != start_set.end(); it++) {
		vector<int> empty_path(word_num);
		vector<int> empty_dist(word_num);
		path[*it] = empty_path;
		dist[*it] = empty_dist;
		for (auto nit = start_set.begin(); nit != start_set.end(); nit++) {
			path[*it][*nit] = -1;
			dist[*it][*nit] = (longest_word) ? 1 : word_list[*nit].length;
		}

	}

	for (auto it = start_set.begin(); it != start_set.end(); it++) {
		dfs(*it, visit, path[*it], dist[*it], longest_word);
		//for(int i=0;i<word_num;i++) cout << path[*it][i] << " ";
		//cout << "-----------------" << endl;
	}

	//找出想要的答案
	int max_chain = 0; //最大链长度
	int index = -1; //终点
	int start_point = -1; // 起点
	if (!set_end) {
		for (auto it = start_set.begin(); it != start_set.end(); it++) {
			auto max = max_element(dist[*it].begin(), dist[*it].end());
			if (*max > max_chain) {
				start_point = *it;
				index = (int)(max - dist[*it].begin());
				max_chain = *max;
			}
		}
	}
	else {
		for (auto it = start_set.begin(); it != start_set.end(); it++) {
			int max = -1;
			int pos = -1;
			for (auto nit = tail_char_list[end_set].begin(); nit != tail_char_list[end_set].end(); nit++) {
				if (dist[*it][*nit] > max) {
					max = dist[*it][*nit];
					pos = *nit;
				}
			}
			if (max > max_chain) {
				max_chain = max;
				index = pos;
				start_point = *it;
			}

		}

	}
	// find the whole path
	vector<int> stack;
	while (index != -1) {
		stack.push_back(index);
		index = path[start_point][index];
	}
	while (!stack.empty()) {
		if (longest_word)
			result_list_word.push_back(word_list[stack.back()].word);
		else
			result_list_char.push_back(word_list[stack.back()].word);
		//cout << word_list[stack.back()].word << endl;
		stack.pop_back();
	}
}

vector<string> Solver::array2string(char *words[], int len) {
	vector<string> res;
	string s;
	for (int i = 0; i < len; i++) {
		s = words[i];
		res.push_back(s);
	}
	return res;
}
int Solver::string2array(vector<string> string_list, char *words[]) {//返回长度
	int size = (int)string_list.size();
	for (int i = 0; i < size; i++) {
		int len = string_list[i].length();
		words[i] = new char[len + 3];
		strcpy_s(words[i], len + 3, string_list[i].c_str());
	}
	return size;
}

void remove_same(vector<string> &string_list) {
	vector<string> copy = string_list;
	string_list.clear();
	for (auto it = copy.begin(); it != copy.end(); it++) {
		if (find(string_list.begin(), string_list.end(), *it) == string_list.end())
			string_list.push_back(*it);
	}
}

int Solver::gen_chain_word(char *words[], int len, char *result[], char head, char tail, bool enable_loop) {
	vector<string> res;
	int length = max_chain_word(array2string(words, len), res, head, tail, enable_loop);
	if (length != 0)
		string2array(this->result_list_word, result);
	return length;

}
int Solver::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop) {

	vector<string> res;
	int length = max_chain_char(array2string(words, len), res, head, tail, enable_loop);
	if (length != 0)
		string2array(res, result);
	return length;

}
int Solver::max_chain_word(vector<string> word_list, vector<string> &result, char head, char tail, bool enable_loop) {
	if (!check_word_legal(word_list))
		throw WORD_ILLEGAL;
	remove_same(word_list);
	form_digraph(word_list);
	bool loop_flag = has_loop();
	if (loop_flag && !enable_loop)
		throw LOOP_ERROR;
	if (tail != 0 && !(tail >= 'a'&& tail <= 'z'))
		throw TAIL_CHAR_ERROR;
	if (head != 0 && !(head >= 'a' && head <= 'z'))
		throw HEAD_CHAR_ERROR;
	if (!loop_flag) {
		SPFA(head, head != 0, tail, tail != 0, true);
	}
	else {
		loop_max_chain(head, head != 0, tail, tail != 0, true);
	}
	result = this->result_list_word;
	int res_len = (int)result.size();
	if (res_len == 1)
		res_len = 0;
	return res_len;
}
int Solver::max_chain_char(vector<string> word_list, vector<string> &result, char head, char tail, bool enable_loop) {
	if (!check_word_legal(word_list))
		throw WORD_ILLEGAL;
	remove_same(word_list);
	form_digraph(word_list);
	bool loop_flag = has_loop();
	if (loop_flag && !enable_loop)
		throw LOOP_ERROR;
	if (tail != 0 && !(tail >= 'a'&& tail <= 'z'))
		throw TAIL_CHAR_ERROR;
	if (head != 0 && !(head >= 'a' && head <= 'z'))
		throw HEAD_CHAR_ERROR;
	if (!loop_flag) {
		SPFA(head, head != 0, tail, tail != 0, false);
	}
	else {
		loop_max_chain(head, head != 0, tail, tail != 0, false);
	}
	result = this->result_list_char;
	int res_len = (int)result.size();
	if (res_len == 1)
		res_len = 0;
	return res_len;
}


