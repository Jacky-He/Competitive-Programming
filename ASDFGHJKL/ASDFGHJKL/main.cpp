#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;

string str;
ll l, k;
ll psa [100005][30];
ll ssa [100005][30];
ll cnt [30];
ll result = INF;

ll toll (char c) {return c - 'a';}

bool check (ll maxcnt)
{
    ll removed = 0;
    ll maxn = maxcnt == 0 ? 1 : 0;
    for (ll y = 0; y < 26; y++)
    {
        if (maxcnt <= cnt [y])
        {
            removed += cnt [y] - maxcnt;
            if (maxcnt != 0)
            {
                maxn++;
            }
        }
    }
    return maxn != 0 && removed + (maxn - 1) >= k && removed <= k;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> str;
    cin >> l >> k;
    
    if (l + k >= str.size())
    {
        cout << 0 << endl;
        return 0;
    }
    
    for (ll x = 1; x <= (ll) str.size(); x++)
    {
        for (ll y = 0; y < 30; y++)
        {
            psa [x][y] = psa [x - 1][y];
        }
        psa [x][toll(str[x - 1])]++;
    }
    for (ll x = (ll) str.size(); x >= 1; x--)
    {
        for (ll y = 0; y < 30; y++)
        {
            ssa [x][y] = ssa [x + 1][y];
        }
        ssa [x][toll(str [x - 1])]++;
    }
    
    for (ll x = 1; x <= (ll)str.size() - l + 1; x++)
    {
        for (ll y = 0; y < 30; y++)
        {
            cnt[y] = psa [x - 1][y] + ssa [x + l][y];
        }
        ll hi = 100005;
        ll lo = 0;
        ll ans = 0;
        while (lo + 1 < hi)
        {
            ll maxcnt = (hi + lo)/2;
            ll removed = 0;
            ll maxn = maxcnt == 0 ? 1 : 0;
            for (ll y = 0; y < 26; y++)
            {
                if (maxcnt <= cnt [y])
                {
                    removed += cnt [y] - maxcnt;
                    if (maxcnt != 0)
                    {
                        maxn++;
                    }
                }
            }
            if (removed > k)
            {
                lo = maxcnt;
            }
            else if (maxn != 0 && removed + (maxn - 1) >= k)
            {
                ans = maxcnt;
                break;
            }
            else
            {
                hi = maxcnt;
            }
        }
        if (check (lo))
        {
            ans = lo;
        }
        else if (check (hi))
        {
            ans = hi;
        }
        ll removed = 0;
        for (ll y = 0; y < 26; y++)
        {
            if (ans < cnt [y])
            {
                removed += cnt [y] - ans;
                cnt [y] = ans;
            }
        }
        
        for (ll y = k - removed; y > 0; y--)
        {
            for (ll z = 0; z < 26; z++)
            {
                if (cnt [z] == ans)
                {
                    cnt[z]--;
                    break;
                }
            }
        }
        ll res = 0;
        for (ll y = 0; y < 26; y++)
        {
            res += cnt [y]*cnt [y];
        }
        result = min (result, res);
    }
    printf ("%lld\n", result);
    return 0;
}
