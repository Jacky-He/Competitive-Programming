#include <bits/stdc++.h>
#define MAX_N 2147483647
using namespace std;
struct peopletime
{
    string person;
    int t;
};
string people;
int t;
int m, p;
pair <int, string> dp [101];
vector <peopletime> arr;
int Max (int from, int length)
{
    int max = arr [from].t;
    for (int i = from; i > from - length && i > 0; i--)
    {
        if (arr[i].t > max)
        {
            max = arr [i].t;
        }
    }
    return max;
}
string conc (int from, int length)
{
    string something = "";
    int f;
    if (from - length + 1 < 0)
    {
        f = 0;
    }
    else
    {
        f = from - length + 1;
    }
    for (int x = f; x < from; x++)
    {
        something += arr [x].person + " ";
    }
    something += arr [from].person;
    return something;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> p;
    peopletime hi;
    arr.push_back (hi);
    for (int x = 1; x <= p; x++)
    {
        cin >> hi.person;
        cin >> hi.t;
        arr.push_back(hi);
    }
    dp [0].first = 0;
    dp [0].second = "";
    for (int x = 0; x <= p; x++)
    {
        pair <int, string> min;
        min.first = MAX_N;
        min.second = "";
        int current = 0;
        string tempstr = "";
        for (int y = 1; y <= m; y++)
        {
            if (x - y <= 0)
            {
                current = Max (x, y);
                if (current < min.first)
                {
                    min.first = current;
                    min.second = conc (x, y);
                }
            }
            else
            {
                current = Max (x, y) + dp [x - y].first;
                tempstr = dp [x - y].second + conc (x, y);
                if (current < min.first)
                {
                    min.first = current;
                    min.second = dp [x - y].second + conc (x, y);
                }
            }
        }
        dp [x].first = min.first;
        dp [x].second = min.second+ "\n";
    }
    cout << "Total Time: "<< dp [p].first << endl;
    cout << dp[p].second;
    return 0;
}
