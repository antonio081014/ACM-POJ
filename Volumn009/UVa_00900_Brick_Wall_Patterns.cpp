//Sat Mar 13 00:57:16 CST 2010
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

int Fibonacci(int x)
{
	if(x == 1) return 1;
	if(x == 2) return 2;
	else return Fibonacci(x-1) + Fibonacci(x-2);
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while(cin >> n && n != 0)
		cout << Fibonacci(n) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
