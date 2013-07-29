//Tue Mar  9 03:19:00 CST 2010
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
	long long A, L;
	int ncase = 0;
	while (cin >> A >> L && A >= 0 && L >= 0)
	{
		ncase++;
		long long term = A;
		long long count = 1;
		while (term != 1 && term <= L)
		{
			count++;
			if (term % 2 == 0)
				term /= 2;
			else
				term = term * 3 + 1;
		}
		if (term != 1)
			count--;
		cout << "Case " << ncase << ": A = " << A << ", limit = " << L
				<< ", number of terms = " << count << endl;

	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
