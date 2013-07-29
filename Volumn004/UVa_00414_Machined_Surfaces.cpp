//Tue Mar  9 02:04:56 CST 2010
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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n;
	while (cin >> n && n != 0)
	{
		string str;
		int count = 0;
		int localMin = -1;
		for (int i = 0; i < n; i++)
		{
			getchar();
			int cnt = 0;
			getline(cin, str);
			for (int idx = 0; idx < (int) str.size(); idx++)
				cnt += (str[idx] == ' ' ? 1 : 0);
			count += cnt;
			localMin = (localMin > cnt || localMin == -1 ? cnt : localMin);
		}
		cout << count - n * localMin << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
