//Mon Apr  4 00:46:13 CDT 2011
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
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    unsigned int n;
    while (cin >> n && n)
    {
        int m = sqrt(n);
        if (m * m == n)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
