//Fri Mar 25 01:41:16 CDT 2011
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

int solve(int n)
{
    int div = 1;
    int count = 1;
    while (div)
    {
        if (div < n)
        {
            count++;
            div = 10 * div + 1;
        }
        div %= n;
    }
    return count;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n)
        cout << solve(n) << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
