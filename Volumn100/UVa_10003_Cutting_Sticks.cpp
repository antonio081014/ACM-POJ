//Sun Apr 10 20:35:42 CDT 2011
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
#define INT_MAX 2147483647

using namespace std;

int length;
int n;
int c[52];
int dp[52][52];

void init() {
	//add two end points to the cuts;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	c[n + 1] = length;
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < n + 2; j++)
			dp[i][j] = -1;
}

int stickcut(int s, int e) {
	if (s + 1 == e)
		return dp[s][e] = 0;
	if (dp[s][e] != -1)
		return dp[s][e];
	dp[s][e] = INT_MAX;
	for (int i = s + 1; i < e; i++) {
		int sum = stickcut(s, i) + stickcut(i, e) + c[e] - c[s];
		dp[s][e] = min(dp[s][e], sum);
	}
	return dp[s][e];
}

int main(int argc, char* argv[]) {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	while (cin >> length && length) {
		cin >> n;
		init();
		cout << "The minimum cutting is " << stickcut(0, n + 1) << "."
				<< endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

