//Tue Mar 15 16:19:03 CDT 2011
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

class Contestant
{
public:
    int contestantID;
    vector<bool> correct;
    vector<int> penalty;
    bool participate;

    Contestant(int id, bool p)
    {
        contestantID = id;
        participate = p;
        for (int i = 1; i <= 9; i++)
        {
            correct.push_back(false);
            penalty.push_back(0);
        }
    }

    static bool cmp(const Contestant &A, const Contestant &B)
    {
        int count1 = 0;
        int sum1 = 0;
        for (int i = 0; i < A.correct.size(); i++)
        {
            if (A.correct[i] == true)
            {
                count1++;
                sum1 += A.penalty[i];
            }
        }
        int count2 = 0;
        int sum2 = 0;
        for (int i = 0; i < B.correct.size(); i++)
        {
            if (B.correct[i] == true)
            {
                count2++;
                sum2 += B.penalty[i];
            }
        }
        if (count1 > count2) return true;
        if (count1 == count2 && sum1 < sum2) return true;
        if (count1 == count2 && sum1 == sum2 && A.contestantID < B.contestantID) return true;
        return false;
    }
};

void initialize(vector<Contestant> &cont)
{
    for (int i = 0; i <= 100; i++)
    {
        cont.push_back(Contestant(i, false));
    }
}

void solve(vector<Contestant> &cont)
{
    string str;
    while (getline(cin, str) && str != "")
    {
        stringstream ss(str);
        int contestant, problem, time;
        char L;
        ss >> contestant >> problem >> time >> L;
        //cout << contestant << ", " << problem << ", " << time << ", " << L << endl;
        cont[contestant].participate = true;
        if (L != 'I' && L != 'C') continue;
        if (L == 'C')
        {
            if (cont[contestant].correct[problem] == false)
            {
                cont[contestant].penalty[problem] += time;
                cont[contestant].correct[problem] = true;
            }
        }
            // L == 'I'
        else
        {
            if (cont[contestant].correct[problem] == false)
            {
                cont[contestant].penalty[problem] += 20;
            }
        }
    }
}

void print(vector<Contestant> cont)
{
std:
    sort(cont.begin(), cont.end(), Contestant::cmp);
    for (int i = 0; i < cont.size(); i++)
    {
        if (cont[i].participate == true)
        {
            int count = 0;
            int sum = 0;
            for (int j = 0; j < cont[i].correct.size(); j++)
            {
                if (cont[i].correct[j] == true)
                {
                    count++;
                    sum += cont[i].penalty[j];
                }
            }
            cout << cont[i].contestantID << " " << count << " " << sum << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    getchar();
    getchar();
    for (int ncase = 1; ncase <= T; ncase++)
    {
        if (ncase > 1) cout << endl;
        vector<Contestant> cons;
        initialize(cons);
        solve(cons);
        print(cons);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
