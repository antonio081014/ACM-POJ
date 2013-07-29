//Tue Apr 26 01:15:40 CDT 2011
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

bool check(string s) {
	int N = s.size();
	if (N % 2 == 1)
		return false;
	stack<char> list;
	for (int i = 0; i < N; i++) {
		if (s[i] == '(' || s[i] == '[')
			list.push(s[i]);
		else if (s[i] == ')') {
			if (list.size() > 0 && list.top() == '(')
				list.pop();
			else
				return false;
		} else if (s[i] == ']') {
			if (list.size() > 0 && list.top() == '[')
				list.pop();
			else
				return false;
		}
	}
	if (list.size() != 0)
		return false;
	return true;
}

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	getchar();
	while (N--) {
		string s;
		getline(cin, s, '\n');
		if (check(s))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

