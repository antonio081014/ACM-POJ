//Tue Jun  1 00:10:10 CDT 2010
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

int Phone(char ch) {
	switch (ch) {
	case 'A':
		return 2;
	case 'B':
		return 2;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 3;
	case 'F':
		return 3;
	case 'G':
		return 4;
	case 'H':
		return 4;
	case 'I':
		return 4;
	case 'J':
		return 5;
	case 'K':
		return 5;
	case 'L':
		return 5;
	case 'M':
		return 6;
	case 'N':
		return 6;
	case 'O':
		return 6;
	case 'P':
		return 7;
	case 'R':
		return 7;
	case 'S':
		return 7;
	case 'T':
		return 8;
	case 'U':
		return 8;
	case 'V':
		return 8;
	case 'W':
		return 9;
	case 'X':
		return 9;
	case 'Y':
		return 9;
	}
	return 0;
}

int main(int argc, const char* argv[]) {
	//	freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		if (t != 1)
			cout << endl;
		int N;
		cin >> N;
		map<string, int> list;
		set<string> v;
		while (N--) {
			string str1;
			cin >> str1;
			string str2;
			for (int i = 0; i < (int) str1.size(); i++) {
				if (isdigit(str1[i])) {
					str2 += str1[i];
				} else if (isalpha(str1[i])) {
					int temp = Phone(str1[i]);
					if (temp > 1 && temp < 10) {
						str2 += '0' + temp;
					}
				}
			}
			//		cout << str2 << endl;
			v.insert(str2);
			list[str2]++;
		}
		bool flag = false;
		set<string>::iterator it;
		for (it = v.begin(); it != v.end(); it++) {
			string temp = (*it);
			if (list[temp] > 1) {
				flag = true;
				cout << temp.substr(0, 3) << "-" << temp.substr(3) << " "
						<< list[(*it)] << endl;
			}
		}
		if (flag == false) {
			cout << "No duplicates." << endl;
		}
	}
	//	fclose(stdin);
	//	fclose(stdout);
	return 0;
}

