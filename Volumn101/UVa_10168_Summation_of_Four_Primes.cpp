//Mon Apr  4 13:07:11 CDT 2011
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
#define max_primes    10000001

using namespace std;

bool primes[max_primes];

void gen_primes()
{
    primes[0] = primes[1] = false;
    for (int i = 2; i < max_primes; ++i)
        primes[i] = true;
    for (int i = 2; i < max_primes; ++i)
    {
        if (primes[i])
            for (int j = 2; i * j < max_primes; ++j)
                primes[i * j] = false;
    }
}

void solve(int n)
{
    if (primes[n - 2])
    {
        cout << " 2 " << n - 2 << endl;
        return;
    }
    for (int i = 3; i <= n / 2; i += 2)
        if (primes[i] && primes[n - i])
        {
            cout << " " << i << " " << n - i << endl;
            return;
        }
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    gen_primes();
    while (cin >> n)
    {
        if (n < 8)
            cout << "Impossible." << endl;
        else if (n % 2 == 0)
        {
            cout << "2 2";
            solve(n - 4);
        }
        else
        {
            cout << "2 3";
            solve(n - 5);
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;

}
