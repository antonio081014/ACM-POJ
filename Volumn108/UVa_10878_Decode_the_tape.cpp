//Sun Apr 24 00:32:14 CDT 2011
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

int main(int argc, char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	while (getline(cin, s, '\n')) {
		if (s[0] != '|')
			continue;
		int sum = 0;
		for (int i = 2; i < s.size() - 1; i++) {
			if (s[i] == '.')
				continue;
			sum *= 2;
			sum += (s[i] == 'o' ? 1 : 0);
		}
		cout << char(sum);
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

