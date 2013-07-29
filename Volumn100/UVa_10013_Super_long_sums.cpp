//Fri Apr 29 03:18:34 CDT 2011
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

string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int N = a.size();
	int flag = 0;
	for (int i = 0; i < N; i++) {
		int sum = (a[i] - '0') + (b[i] - '0') + flag;
		if (sum > 9)
			flag = 1;
		else
			flag = 0;
		a[i] = sum % 10 + '0';
	}
	if (flag)
		a += '0' + flag;
	reverse(a.begin(), a.end());
	while (a[0] == '0' && a.size() > 1)
		a = a.substr(1);
	return a;
}

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t > 0)
			cout << endl;
		int N;
		cin >> N;
		string a = "";
		string b = "";
		int num1, num2;
		for (int i = 0; i < N; i++) {
			cin >> num1 >> num2;
			a += ('0' + num1);
			b += ('0' + num2);
		}
		//		cout << a << endl;
		//		cout << b << endl;
		cout << add(a, b) << endl;
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

