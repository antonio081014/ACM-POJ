//Wed Mar 30 15:42:25 CDT 2011
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

int solve(int x, int y)
{
    if (y - x == 0) return 0;
    int k = sqrt(1.0 * (y - x));
    if (k * k == y - x) // odd steps;
    {
        return 2 * k - 1;
    }
    else if ((1 + k) * k < y - x) //even steps + one more, which is less then k.
    {
        return 2 * k + 1;
    }
    else //even steps;
        return 2 * k;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
