//Fri Apr 22 18:01:49 CDT 2011
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

set<string> words;

void init() {
	words.clear();
}

void processWord(string s) {
	string ss = "";
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i]))
			ss += tolower(s[i]);
		else {
			if (ss.empty() == false)
				words.insert(ss);
			ss.clear();
		}
	}
	if (ss.empty() == false)
		words.insert(ss);
	ss.clear();
}

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	init();
	while (cin >> s)
		processWord(s);
	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
		cout << (*it) << endl;
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

