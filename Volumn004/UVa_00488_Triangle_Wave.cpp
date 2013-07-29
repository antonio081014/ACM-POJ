//Tue Mar  9 00:59:08 CST 2010
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
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j + 1 < 2 * a; j++)
			{
				if (j < a)
				{
					for (int k = 0; k <= j; k++)
						cout << j + 1;
					cout << endl;
				}
				else
				{
					for (int k = 2 * a - 1 - j; k > 0; k--)
						cout << 2 * a - 1 - j;
					cout << endl;
				}
			}
			//Take care of the blank line between cases.
			if (i + 1 < b)
				cout << endl;
		}
		if (n > 0)
			cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
