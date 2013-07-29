//Sat Apr 23 21:40:28 CDT 2011
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

void Calculate(string s, double a, double b) {
	if (s == "UI")
		printf("P=%.2fW\n", a * b);
	else if (s == "PU")
		printf("I=%.2fA\n", a / b);
	else if (s == "PI")
		printf("U=%.2fV\n", a / b);
}

double translate(char c, double a) {
	if (c == 'm')
		return a / 1000.0;
	if (c == 'k')
		return a * 1000.0;
	if (c == 'M')
		return a * 1000000.0;
	return a;
}

pair<string, pair<double, double> > processLine(string s) {
	string pattern = "";
	size_t found1 = s.find_first_of('=');
	size_t found2 = s.find_last_of('=');
	double a, b;
	string unitA, unitB;
	stringstream ss1(s.substr(found1 + 1));
	stringstream ss2(s.substr(found2 + 1));
	ss1 >> a >> unitA;
	ss2 >> b >> unitB;
	if (isalpha(unitA[unitA.size() - 1]) == false)
		unitA = unitA.substr(0, unitA.size() - 1);
	if (isalpha(unitB[unitB.size() - 1]) == false)
		unitB = unitB.substr(0, unitB.size() - 1);
	if (unitA.size() == 2)
		a = translate(unitA[0], a);
	if (unitB.size() == 2)
		b = translate(unitB[0], b);
	//	cout << a << ", " << unitA << endl;
	//	cout << b << ", " << unitB << endl;

	if (s[found1 - 1] == 'U' && s[found2 - 1] == 'I')
		pattern = "UI";
	else if (s[found1 - 1] == 'I' && s[found2 - 1] == 'U') {
		pattern = "UI";
		double tmp = a;
		a = b;
		b = tmp;
	} else if (s[found1 - 1] == 'P' && s[found2 - 1] == 'U')
		pattern = "PU";
	else if (s[found1 - 1] == 'U' && s[found2 - 1] == 'P') {
		pattern = "PU";
		double tmp = a;
		a = b;
		b = tmp;
	} else if (s[found1 - 1] == 'P' && s[found2 - 1] == 'I')
		pattern = "PI";
	else if (s[found1 - 1] == 'I' && s[found2 - 1] == 'P') {
		pattern = "PI";
		double tmp = a;
		a = b;
		b = tmp;
	}

	return make_pair(pattern, make_pair(a, b));
}

void solve() {
	string s;
	getline(cin, s, '\n');
	//	cout << s << endl;
	pair<string, pair<double, double> > ret = processLine(s);
	Calculate(ret.first, ret.second.first, ret.second.second);
	cout << endl;
}

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	getchar();
	for (int t = 1; t <= T; t++) {
		cout << "Problem #" << t << endl;
		solve();
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

