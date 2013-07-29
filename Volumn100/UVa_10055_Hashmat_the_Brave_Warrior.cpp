//Tue Mar  9 00:02:53 CST 2010
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
	long long a, b;
	while (cin >> a >> b)
	{//Since we have two long long numbers here, we can't just use abs function, it's required to rewrite that function.
		cout << (a >= b ? a - b : b - a) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
