#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;
int microwaves, m, available;
ll t, a, b;

priority_queue <ll, vector <ll>, greater <ll>> PQ;
vector <pair <ll, ll>> people;

vector <pair <ll, ll>> microwaveusage;

int main ()
{
    scanf ("%d%d%lld", &microwaves, &m, &t);
    available = microwaves;
    for (int x = 0; x < m; x++)
    {
        scanf ("%lld%lld", &a, &b);
        people.push_back({a, b});
    }
    sort (people.begin(), people.end());
    ll currtime = 0;
    ll res = INF;
    for (pair <ll, ll> each: people)
    {
        if (!microwaves)
        {
            currtime = PQ.top();
        }
        if (currtime + t <= each.first)
        {
            res = min(res, currtime);
        }
        currtime = max (currtime, each.first);
        while (!PQ.empty() && PQ.top() <= currtime)
        {
            microwaveusage.push_back ({PQ.top(), -1});
            PQ.pop();
            microwaves++;
        }
        PQ.push (currtime + each.second);
        microwaves--;
        microwaveusage.push_back ({currtime, 1});
    }
    if (microwaves)
    {
        res = min (res, currtime);
    }
    else
    {
        res = min (PQ.top(), res);
    }
    sort (microwaveusage.begin(), microwaveusage.end());
    int small = 0, big = 0;
    for (pair <ll, ll> each: microwaveusage)
    {
        if (each.second == 1)
        {
            available++;
        }
        else if (each.second == -1)
        {
            available--;
        }
        if (available)
    }
    
    
    /*printf ("%lld\n", res);
    if (res == 8 && t!=3)
    {
        printf ("%d %d %lld\n", i, m, t);
        for (pair <ll, ll> each: people)
        {
            printf ("%lld %lld\n", each.first, each.second);
        }
    }*/
    return 0;
}
/*
3 5 20
0 3
1 3
2 3
8 2
9 1

*/
