//Tue Mar 22 18:11:01 CDT 2011
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

long double solve(long double number)
{
    long double lower = log2l(number);
    long double upper = log2l(number + 1);
    long double f = log2l(10);
    long double inc = ceill(log10l(number + 0.5)) + 1;
    for (; ceill(lower + inc * f) != floorl(upper + inc * f); inc += 1);
    return ceill(lower + inc * f);
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    long double str;
    while (cin >> str)
    {
        cout << (long long) solve(str) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
