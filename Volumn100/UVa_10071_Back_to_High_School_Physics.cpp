//Tue Mar  9 00:18:02 CST 2010
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
//The theory here can be proved by using geographic.

int main(int argc, const char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	while (cin >> a >> b)
	{
		cout << 2 * a * b << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
