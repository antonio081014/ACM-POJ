//Wed Mar 10 05:23:36 CST 2010
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

char Ma[][10] =
{ "0", "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
		"yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu",
		"uayet" };
char Tz[][10] =
{ "ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
		"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
		"eznab", "canac" };

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a[262] =
	{ 0 }, j = 1, l = 0;
	for (int i = 1; i < 261; i++, j++)
	{
		a[i] = j;
		if (j == 13)
			j = 0;
	}
	scanf("%d", &n);
	while (n--)
	{
		int d, y, sum, k;
		char m[10];
		scanf("%d.%s%d", &d, m, &y);
		for (int i = 0; i <= 20; i++)
			if (strcmp(Ma[i], m) == 0)
			{
				k = i;
				break;
			}
		sum = y * 365 + (k - 1) * 20 + d + 1;
		y = sum / 260;
		sum = sum % 260;
		if (l++ == 0)
			printf("%d\n", n + 1);
		if (sum == 0)
			printf("13 ahau %d\n", y - 1);
		else
			printf("%d %s %d\n", a[sum], Tz[sum % 20], y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 * Test data;
 * 3
 * 10. zac 0
 * 0. pop 0
 * 10. zac 1995
 *
 */
