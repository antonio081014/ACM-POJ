//Fri Mar 18 00:46:05 CDT 2011
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

void initialize(int n, vector<int> &v)
{
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

int solve(int n, vector<int> &v)
{
    sort(v.begin(), v.end());
    int mid = n / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(v[i] - v[mid]);
    return sum;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        initialize(n, v);
        cout << solve(n, v) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
