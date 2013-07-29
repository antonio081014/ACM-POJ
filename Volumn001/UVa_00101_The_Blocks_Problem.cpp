//Fri Apr 15 01:53:13 CDT 2011
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<int> > block;

void init(int N) {
	block.clear();
	for (int i = 0; i < N; i++)
		block.push_back(vector<int> (1, i));
	//	for (int i = 0; i < N; i++)
	//		for (int j = 0; j < block[i].size(); j++)
	//			cout << block[i][j] << endl;
}

pair<pair<int, int> , pair<int, int> > findPosition(int a, int b, int N) {
	int x1, y1, x2, y2;
	bool flag1 = true;
	bool flag2 = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < block[i].size(); j++) {
			if (block[i][j] == a && flag1) {
				x1 = i;
				y1 = j;
				flag1 = false;
			}
			if (block[i][j] == b && flag2) {
				x2 = i;
				y2 = j;
				flag2 = false;
			}
			if (!flag1 && !flag2)
				break;
		}
	}
	//	cout << x1 << y1 << endl;
	//	cout << x2 << y2 << endl;
	return make_pair(make_pair(x1, y1), make_pair(x2, y2));
}

void moveOnto(int a, int b, int N) {
	if (a == b)
		return;
	pair<pair<int, int> , pair<int, int> > tmp = findPosition(a, b, N);
	if (tmp.first.first == tmp.second.first)
		return;
	while (block[tmp.first.first].empty() == false
			&& block[tmp.first.first].back() != a) {
		block[block[tmp.first.first].back()].push_back(
				block[tmp.first.first].back());
		block[tmp.first.first].pop_back();
	}
	while (block[tmp.second.first].empty() == false
			&& block[tmp.second.first].back() != b) {
		block[block[tmp.second.first].back()].push_back(
				block[tmp.second.first].back());
		block[tmp.second.first].pop_back();
	}
	block[tmp.first.first].pop_back();
	block[tmp.second.first].push_back(a);
}

void moveOver(int a, int b, int N) {
	if (a == b)
		return;
	pair<pair<int, int> , pair<int, int> > tmp = findPosition(a, b, N);
	if (tmp.first.first == tmp.second.first)
		return;
	while (block[tmp.first.first].empty() == false
			&& block[tmp.first.first].back() != a) {
		block[block[tmp.first.first].back()].push_back(
				block[tmp.first.first].back());
		block[tmp.first.first].pop_back();
	}
	block[tmp.first.first].pop_back();
	block[tmp.second.first].push_back(a);
}

void pileOnto(int a, int b, int N) {
	if (a == b)
		return;
	pair<pair<int, int> , pair<int, int> > tmp = findPosition(a, b, N);
	if (tmp.first.first == tmp.second.first)
		return;
	while (block[tmp.second.first].empty() == false
			&& block[tmp.second.first].back() != b) {
		block[block[tmp.second.first].back()].push_back(
				block[tmp.second.first].back());
		block[tmp.second.first].pop_back();
	}
	block[tmp.second.first].push_back(a);
	vector<int> temp;
	while (block[tmp.first.first].empty() == false
			&& block[tmp.first.first].back() != a) {
		temp.push_back(block[tmp.first.first].back());
		block[tmp.first.first].pop_back();
	}
	while (temp.empty() == false) {
		block[tmp.second.first].push_back(temp.back());
		temp.pop_back();
	}
	block[tmp.first.first].pop_back();
}

void pileOver(int a, int b, int N) {
	if (a == b)
		return;
	pair<pair<int, int> , pair<int, int> > tmp = findPosition(a, b, N);
	if (tmp.first.first == tmp.second.first)
		return;
	block[tmp.second.first].push_back(a);
	vector<int> temp;
	while (block[tmp.first.first].empty() == false
			&& block[tmp.first.first].back() != a) {
		temp.push_back(block[tmp.first.first].back());
		block[tmp.first.first].pop_back();
	}
	while (temp.empty() == false) {
		block[tmp.second.first].push_back(temp.back());
		temp.pop_back();
	}
	block[tmp.first.first].pop_back();
	//Version 2;
	//	for (int i = tmp.first.second; i < block[tmp.first.first].size(); i++)
	//		block[tmp.second.first].push_back(block[tmp.first.first][i]);
	//	block[tmp.first.first].erase(block[tmp.first.first].begin()
	//			+ tmp.first.second, block[tmp.first.first].end());
}

void print(int N) {
	for (int i = 0; i < N; i++) {
		cout << i << ":";
		for (int j = 0; j < block[i].size(); j++)
			cout << " " << block[i][j];
		cout << endl;
	}
}

void solve(int N) {
	string verb;
	int a, b;
	string s;
	while (cin >> verb && verb != "quit") {
		cin >> a >> s >> b;
		//		cout << verb << a << s << b << endl;
		if (verb == "move") {
			if (s == "onto")
				moveOnto(a, b, N);
			else
				moveOver(a, b, N);
		} else {
			if (s == "onto")
				pileOnto(a, b, N);
			else
				pileOver(a, b, N);
		}
		//		print(N);
	}
}

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	init(N);
	solve(N);
	print(N);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

