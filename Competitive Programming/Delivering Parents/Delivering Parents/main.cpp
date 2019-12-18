#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int>> sleep;
int start, ed;
bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first);
}
int main ()
{
    int n;
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d%d", &start, &ed);
        sleep.push_back ({start, ed});
    }
    sort (sleep.begin(), sleep.end(), cmp);
    int time = sleep [0].first;
    int gifts = 0;
    for (int x = 0; x < n; x++)
    {
        if (time < sleep [x].second && time >= sleep [x].first)
        {
            time++;
            gifts++;
        }
        else if (time < sleep [x].first)
        {
            time = sleep [x].first + 1;
            gifts++;
        }
    }
    printf ("%d\n", gifts);
    return 0;
}
