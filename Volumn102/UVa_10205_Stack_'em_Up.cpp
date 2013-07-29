//Mon Mar 14 16:17:01 CDT 2011
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

void initialize(int &N, vector<vector<int> > &v, vector<int> &src)
{
    cin >> N;
    for (int i = 0; i < 52; i++)
        src.push_back(i + 1);
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0, tmp; j < 52; j++)
        {
            cin >> tmp;
            temp.push_back(tmp);
        }
        v.push_back(temp);
    }

}

string matchValue(int value)
{
    switch (value)
    {
    case 1:
        return "2";
    case 2:
        return "3";
    case 3:
        return "4";
    case 4:
        return "5";
    case 5:
        return "6";
    case 6:
        return "7";
    case 7:
        return "8";
    case 8:
        return "9";
    case 9:
        return "10";
    case 10:
        return "Jack";
    case 11:
        return "Queen";
    case 12:
        return "King";
    case 0:
        return "Ace";
    }
    return "";
}

string matchSuit(int number)
{
    switch (number)
    {
    case 0:
        return "Clubs";
    case 1:
        return "Diamonds";
    case 2:
        return "Hearts";
    case 3:
        return "Spades";
    }
    return "";
}

string translate(int number)
{
    int suit = (number - 1) / 13;
    int value = number % 13;
    return matchValue(value) + " of " + matchSuit(suit);
}

vector<int> oneShuffle(vector<int> src, vector<int> crypt)
{
    vector<int> tmp(52, 0);
    for (int i = 0; i < src.size(); i++)
    {
        tmp[i] = src[crypt[i] - 1];
    }
    return tmp;
}

void solve(vector<int> &src, vector<vector<int> > shuffle)
{
    for (int i = 0; i < shuffle.size(); i++)
    {
        int value;
        cin >> value;
        src = oneShuffle(src, shuffle[value - 1]);
    }
}

void print(vector<int> src)
{
    for (int i = 0; i < 52; i++)
        cout << translate(src[i]) << endl;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    for (int ncase = 0; ncase < T; ncase++)
    {
        if (ncase > 0) cout << endl;
        int N;
        vector<vector<int> > shuffles;
        vector<int> src;
        initialize(N, shuffles, src);
        solve(src, shuffles);
        print(src);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
