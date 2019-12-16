#include <bits/stdc++.h>
using namespace std;
int planets, start, a, b;
int cnt, cntvalue;
vector <pair <int, int>> values;      //first: gain, second: spend;
bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return (p1.second < p2.second) || (p1.second == p2.second && p1.first > p2.first);
}
int main ()
{
    scanf ("%d%d", &planets, &start);
    for (int x = 1; x <= planets; x++)
    {
        scanf ("%d%d", &a, &b);
        if (start == x)
        {
            cntvalue = a;
            cnt = 1;
        }
        else
        {
            values.push_back ({a - b, b});
        }
    }
    sort (values.begin(), values.end(), cmp);
    for (int x = 0; x < (int) values.size(); x++)
    {
        if (values [x].first >= 0 && cntvalue >= values [x].second)
        {
            cntvalue += values [x].first;
            cnt++;
        }
    }
    printf ("%d\n%d\n", cntvalue, cnt);
    return 0;
}