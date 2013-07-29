//Sat Mar 13 12:15:03 CST 2010
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

bool check(vector<bool> v) //To check if it's all true or not.
{
	for (int i = 0; i < (int) v.size(); i++)
		if (v[i] == false)
			return true;
	return false;
}

bool circle(vector<bool> v, int start, int period)
{
//	cout << "Period" << period << endl;
	while (check(v) == true)
	{
//		for(int i=0; i<(int)v.size(); i++) cout << v[i];
//		cout << endl;
		start = (start + period - 1) % v.size();
		if (v[start] == false)
			v.erase(v.begin() + start);
		else
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<bool> member;
	int k;
	while (cin >> k && k != 0)
	{
		member.clear();
		for (int i = 0; i < k; i++)
			member.push_back(true); //Good Guy;
		for (int i = 0; i < k; i++)
			member.push_back(false); //Bad Guy;

		for (int period = 1;; period++)
		{
			if (circle(member, 0, period))
			{
				cout << period << endl;
				break;
			}
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
