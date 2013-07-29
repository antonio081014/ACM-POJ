//Tue Mar  9 00:24:02 CST 2010
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

int main(int argc, const char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int total = 0;
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			total += a * c;
		}
		cout << total << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
