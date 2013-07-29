//Mon Apr  4 16:35:28 CDT 2011
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
#define max_primes    31623 //That's the possible biggest prime number.

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

int sum(int n)
{
    int ret = 0;
    while (n > 0)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

bool isPrime(int n)
{
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(1.0 * n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

bool check(int n)
{
    int s = 0;
    int record = sum(n);
    while (n > 1 && n % 2 == 0)
    {
        s += sum(2);
        n /= 2;
    }
    //cout << "break one" << endl;
    for (int i = 3; i <= sqrt(1.0 * n) && n > 1; i += 2)
    {
        if (primes[i])
        {
            int ss = sum(i);
            while (n % i == 0 && n > 1)
            {
                s += ss;
                n /= i;
            }
        }
    }
    if (n > 1)
        s += sum(n);
    //cout << "break two" << endl;
    //cout << n << endl;
    //cout << s << endl;
    if (s == record)
        return true;
    return false;
}

void solve(int n)
{
    while (++n)
    {
        //cout << n << endl;
        if (!isPrime(n) && check(n))
        {
            cout << n << endl;
            return;
        }
    }
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int k;
    cin >> k;
    gen_primes();
    while (k--)
    {
        int n;
        cin >> n;
        //check(n + 1);
        solve(n);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
