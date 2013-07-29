//Fri Mar 18 17:39:50 CDT 2011
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <climits>

using namespace std;

int main()
{
    //freopen("input.in", "r", stdin);
    int testCase, eachOfCase;
    string name;
    cin >> testCase;
    vector<string> totalyOfValue;
    vector<string> arrayOfBefore;
    vector<string> arrayOfAfter;
    int i;
    for (int T = 0; T < testCase; T++)
    {
        cin >> eachOfCase;
        totalyOfValue.clear();
        arrayOfAfter.clear();
        arrayOfBefore.clear();
        int k;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        for (k = 0; k < eachOfCase; k++)
        {
            getline(cin, name);
            arrayOfBefore.push_back(name);
        }
        for (k = 0; k < eachOfCase; k++)
        {
            getline(cin, name);
            arrayOfAfter.push_back(name);
        }
        int compareToBefore = eachOfCase;
        int compareToAfter;
        for (k = eachOfCase - 1; k >= 0; k--)
        {
            for (int j = 0; j < eachOfCase; j++)
                if (arrayOfAfter[k] == arrayOfBefore[j])
                    compareToAfter = j;
            if (compareToAfter < compareToBefore)
                compareToBefore = compareToAfter;
            else
                break;

        }
        for (k; k >= 0; k--)
            totalyOfValue.push_back(arrayOfAfter[k]);
        totalyOfValue.push_back("0");

        for (i = 0; i < totalyOfValue.size(); i++)
        {
            if (totalyOfValue[i] == "0")
                cout << endl;
            else
                cout << totalyOfValue[i] << endl;
        }
    }
    return 0;
}
