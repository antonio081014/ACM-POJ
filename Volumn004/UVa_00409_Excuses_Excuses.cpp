//Fri Apr 22 18:19:01 CDT 2011
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

class Word {
public:
	string s;
	int sum;
	Word() {
		s = "";
		sum = 0;
	}

	static bool cmp(const Word &A, const Word &B) {
		return A.sum > B.sum;
	}
};

set<string> excuse;
vector<Word> occurs;

void init(int k, int e) {
	excuse.clear();
	occurs.clear();
	occurs.resize(e, Word());
	string s;
	for (int i = 0; i < k; i++) {
		cin >> s;
		excuse.insert(s);
	}
}

void processLine(int row) {
	string line = occurs[row].s;
	int sum = 0;
	string s = "";
	set<string>::iterator it;
	for (int i = 0; i < (int) line.size(); i++) {
		if (isalpha(line[i])) {
			s += tolower(line[i]);
		} else {
			if (s.empty() == false) {
				it = excuse.find(s);
				if (it != excuse.end())
					sum++;
			}
			s.clear();
		}
	}
	occurs[row].sum = sum;
}

void solve(int e) {
	getchar();
	for (int i = 0; i < e; i++) {
		getline(cin, occurs[i].s, '\n');
		processLine(i);
	}
	sort(occurs.begin(), occurs.end(), Word::cmp);
	int sum = occurs[0].sum;
	for (int i = 0; i < e; i++)
		if (occurs[i].sum == sum)
			cout << occurs[i].s << endl;
		else
			break;
}

int main(int argc, char* argv[]) {
	//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int K, E;
	int counter = 1;
	while (cin >> K >> E) {
		cout << "Excuse Set #" << counter++ << endl;
		init(K, E);
		solve(E);
		cout << endl;
	}
	//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

