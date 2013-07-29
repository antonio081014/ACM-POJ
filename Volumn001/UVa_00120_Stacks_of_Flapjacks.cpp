//Wed Jun  2 11:09:06 EDT 2010
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

int main(int argc, char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int diameter;
	while (cin >> diameter)
	{
		vector<int> pancakes;
		pancakes.push_back(diameter);
		while (cin.peek() != '\n')
		{
			cout << diameter << " ";
			cin >> diameter;
			pancakes.push_back(diameter);
		}
		cout << diameter << endl;
		int sorted = pancakes.size();
		while (sorted > 0)
		{
			vector<int>::iterator mmax = max_element(pancakes.begin(),
					pancakes.begin() + sorted);
			if (mmax != pancakes.begin() + sorted - 1)
			{
				if (mmax != pancakes.begin())
				{
					reverse(pancakes.begin(), mmax + 1);
					cout << pancakes.end() - mmax<< " ";
				}
				reverse(pancakes.begin(), pancakes.begin() + sorted);
				cout << pancakes.size() - sorted + 1 << " ";
			}
			sorted--;
		}
		cout << 0 << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
