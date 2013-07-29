//Fri Mar 18 01:34:43 CDT 2011
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

class Time
{
public:
    int start;
    int end;

    Time(int s, int m)
    {
        this->start = s;
        this->end = m;
    }

    static bool cmp(const Time &A, const Time &B)
    {
        if (A.start < B.start) return true;
        if (A.start == B.start && A.end > B.end) return true;
        return false;
    }
};

void initialize(int N, vector<Time> &v)
{
    int a, b, c, d;
    char ch;
    string str;
    for (int i = 0; i < N; i++)
    {
        getline(cin, str);
        stringstream s(str);
        s >> a >> ch >> b >> c >> ch >> d >> str;
        //cout << a << b << c << d << str << endl;
        v.push_back(Time((a - 10)*60 + b, (c - 10)*60 + d));
    }
    v.push_back(Time(480, 480));
}

Time solve(vector<Time> v)
{
    int N = v.size();
    //for (int i = 0; i < N; i++)
    //    cout << v[i].start << ":" << v[i].end << endl;
    std::sort(v.begin(), v.end(), Time::cmp);
    int mmax = 0;
    int last = 0;
    int mark = -1;
    for (int i = 0; i < N; i++)
    {
        if (v[i].start > last)
        {
            if (v[i].start - last > mmax)
            {
                mmax = v[i].start - last;
                mark = i - 1;
            }
            last = v[i].end;
        }
        else if (v[i].end > last)
            last = v[i].end;
    }
    return Time(v[mark].end, mmax);
}

void print(int T, vector<Time> v)
{
    Time t = solve(v);
    int h = t.start / 60 + 10;
    int m = t.start % 60;
    cout << "Day #" << T << ": the longest nap starts at ";
    cout << h << ":" << setw(2) << setfill('0') << m << " and will last for ";
    int hh = t.end / 60;
    int mm = t.end % 60;
    if (hh > 0)
        cout << hh << " hours and ";
    cout << mm << " minutes." << endl;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T = 1;
    int N;
    while (cin >> N)
    {
        getchar();
        vector<Time> schedule;
        initialize(N, schedule);
        print(T++, schedule);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
