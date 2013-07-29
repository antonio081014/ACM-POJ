//Sat Apr 23 23:52:30 CDT 2011
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

void processLine(string a, string b) {
	string s1 = "";
	string s2 = "";
	string s3 = "";
	string s4 = "";
	string s5 = "";
	size_t found1 = a.find('<', 0);
	s1 = a.substr(0, found1);
	size_t found2 = a.find('>', 0);
	s2 = a.substr(found1 + 1, found2 - found1 - 1);
	found1 = a.find('<', found1 + 1);
	s3 = a.substr(found2 + 1, found1 - found2 - 1);
	found2 = a.find('>', found2 + 1);
	s4 = a.substr(found1 + 1, found2 - found1 - 1);
	s5 = a.substr(found2 + 1);
	cout << s1 << s2 << s3 << s4 << s5 << endl;
	b = b.substr(0, b.size() - 3);
	cout << b << s4 << s3 << s2 << s5 << endl;
}

void solve() {
	string a, b;
	getline(cin, a, '\n');
	getline(cin, b, '\n');
	processLine(a, b);
}

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	getchar();
	while (T--) {
		solve();
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

