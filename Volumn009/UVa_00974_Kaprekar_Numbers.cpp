//Sat Mar 13 00:15:01 CST 2010
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
vector<bool> keystore(40001, false); //To record whether it's k number or not.
bool isK(int x)
{
	if (x < 4)
		return false;
	stringstream ss;
	ss << (x * x);
	string str = ss.str();
	//	cout << str << endl;
	for (int i = 1; i < (int) str.size(); i++)
	{
		string a = str.substr(0, i);
		string b = str.substr(i);
		stringstream s1(a);
		stringstream s2(b);
		int aa, bb;
		s1 >> aa;
		s2 >> bb;
		if (aa + bb == x && aa > 0 && bb > 0)
			return true;
	}
	return false;
}
void Cal()
{
	for (int i = 2; i <= 40000; i++)
	{
		keystore[i] = isK(i);
	}
}
int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Cal();
	int n;
	cin >> n;
	for (int ncase = 1; ncase <= n; ncase++)
	{
		int INF, SUP;
		cin >> INF >> SUP;
		cout << "case #" << ncase << endl;
		bool flag = false;
		for (int i = INF; i <= SUP; i++)
		{
			if (keystore[i])
			{
				flag = true;
				cout << i << endl;
			}
		}
		if (flag == false)
			cout << "no kaprekar numbers" << endl;
		if (ncase < n)	//Don't forget the blank lines only exist between tests.
			cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
