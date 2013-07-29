//Mon Apr  4 02:02:17 CDT 2011
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

long gcd(long p, long q, long *x, long *y)
{
    long x1, y1;
    long g;
    if (q > p) return (gcd(q, p, y, x));

    if (q == 0)
    {
        *x = 1;
        *y = 0;
        return (p);
    }

    g = gcd(q, p % q, &x1, &y1);

    //cout << x1 << "," << y1 << "," << g << endl;
    *x = y1;
    *y = (x1 - floor(p / q) * y1);

    return (g);
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    long x, y;
    long a, b;
    while (cin >> a >> b)
    {
        long g = gcd(a, b, &x, &y);
        cout << x << " " << y << " " << g << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
