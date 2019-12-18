#include <bits/stdc++.h>
#define endl "\n"
#define seed1 31
#define seed2 131
typedef int8_t small;
typedef long long int ll;
using namespace std;

int n, temp;
ll dest, start;
queue <ll> Q;
int cnt = 0;
unordered_map <ll, int> dis;

void init ()
{
    dis.clear();
    while (!Q.empty())
    {
        Q.pop();
    }
}
int main ()
{
    while (true)
    {
        ll coins = 0;
        init();
        scanf ("%d", &n);
        
        if (n == 0)
        {
            break;
        }
        if (n == 1)
        {
            scanf ("%d", &temp);
            printf ("%d\n", 0);
            continue;
        }
        for (int x = 1; x <= n; x++)
        {
            coins |= ((ll)1 << (((ll)x - 1)*8 + x));
        }
        dest = coins;
        coins = 0;
        for (int x = 0; x < n; x++)
        {
            scanf ("%d", &temp);
            coins |= ((ll)1 << ((ll)x*8 + temp));
        }
        start = coins;
        
        dis [start] = 0;
        Q.push (coins);
        bool flag = false;
        while (!Q.empty() && !flag)
        {
            ll temp = Q.front();
            Q.pop();
            
            for (int x = 0; x < n && !flag; x++)
            {
                if ((((((ll)1 << (ll)8) - (ll)1) << (ll)x*8)&temp)) //0: empty
                {
                    int adj [] = {x + 1, x - 1};
                    for (int idx: adj)
                    {
                        if (idx >= 0 && idx <= n - 1)
                        {
                            int smaller = __builtin_ffsl (temp >> (ll)x*8) - 1;
                            if (!(((((ll)1 << (ll)8) - (ll)1) << (ll)idx*8)&temp) || __builtin_ffsl (temp >> (ll)idx*8) - 1 > smaller)
                            {
                                ll temp2 = temp;
                                temp2 |= ((ll)1 << ((ll)idx*8 + smaller));
                                temp2 &= (~((ll)1 << ((ll)x*8 + smaller)));
                                if (!dis.count (temp2))
                                {
                                    dis [temp2] = dis [temp] + 1;
                                    if (temp2 == dest)
                                    {
                                        flag = true;
                                        break;
                                    }
                                    Q.push (temp2);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (dis [dest] == 0 && dest != start)
        {
            printf ("IMPOSSIBLE\n");
        }
        else
        {
            printf ("%d\n", dis [dest]);
        }
    }
    return 0;
}
