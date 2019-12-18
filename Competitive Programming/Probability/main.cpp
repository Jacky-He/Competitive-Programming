#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

map <ll, ll> sums;
ll cnt = 0;

void solve (int n, ll sum)
{
    if (n == 1)
    {
        for (int x = 1; x <= 6; x++)
        {
            sums [sum + x]++;
            cnt++;
        }
        return;
    }
    for (int x = 1; x<= 6; x++)
    {
        solve (n - 1, sum + x);
    }
}

int main()
{
    solve (10, 0);
    ll res = 0;
    ll res2 = 0;
    for (auto const& each: sums)
    {
        res += each.second*each.second;
        for (auto const& each2: sums)
        {
            res2 += each2.second*each.second;
        }
    }
    
    cout << res << endl;
    cout << res2 << endl;
    cout << double(res)/double(res2) << endl;
    //cout << sums.size()*sums.size() << endl;
    return 0;
}
