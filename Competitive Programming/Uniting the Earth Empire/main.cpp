#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
ll num;

ll res;

deque <pair <ll, ll>> monostack; //first: height, second: num same

void push (ll height)
{
    while (!monostack.empty() && monostack.back().first < height)
    {
        res++;
        monostack.pop_back();
    }
    ll numsame = 1;
    if (!monostack.empty() && monostack.back().first == height)
    {
        numsame += monostack.back().second;
    }
    monostack.push_back ({height, numsame});
    res += monostack.front().first != height? numsame : numsame - 1;
}

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        push (num);
    }
    printf ("%lld\n", res);
    return 0;
}

