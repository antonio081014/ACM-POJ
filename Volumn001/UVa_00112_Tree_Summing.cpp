//Sun Apr 24 12:47:06 CDT 2011
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

int total;
bool flag;
bool mark;

int recursive(int sum) {
	char ch;
	int number;
	int leaf = 0;
	do {
		cin >> ch;
	} while (ch == ' ' || ch == '\n');
	//	cout << ch;
	if (isdigit(ch)) {
		mark = true;
		cin.unget();
		cin >> number;
		leaf += recursive(sum + number);
		leaf += recursive(sum + number);
		do {
			cin >> ch;
		} while (ch != ')');
		//		cout << number << ", " << leaf << endl;
		if (leaf == 2 && sum + number == total)
			flag = true;
		return 0;
	} else if (ch == '-') {
		mark = true;
		cin >> number;
		leaf += recursive(sum - number);
		leaf += recursive(sum - number);
		do {
			cin >> ch;
		} while (ch != ')');
		//		cout << number << ", " << leaf << endl;
		if (leaf == 2 && sum - number == total)
			flag = true;
		return 0;
	} else if (ch == '(')
		recursive(sum);
	else if (ch == ')') {
		return 1;
	}
}

int main() {
	//	freopen("input.in", "r", stdin);
	while (cin >> total) {
		flag = false;
		mark = false;
		recursive(0);
		if (flag && mark)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	//	fclose(stdin);
	return 0;
}

