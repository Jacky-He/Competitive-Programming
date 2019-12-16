#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll res, num;
int n, m;
vector <ll> set1;
vector <ll> set2;
map <ll, ll> map1;
vector <ll> allnums;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> num;
        allnums.push_back (num);
    }
    for (int x = 0; x < m; x++)
    {
        cin >> num;
        allnums.push_back(0-num);
    }
    for (int x = 0; x < (n+m)/2; x++)
    {
        set1.push_back (allnums [x]);
    }
    for (int x = (n+m)/2; x < (int)allnums.size(); x++)
    {
        set2.push_back (allnums [x]);
    }
    for (int x = 0; x < (1 << (set1.size())); x++)
    {
        ll sum = 0;
        for (int i = 0; (x >> i); i++)
        {
            sum += (x >> i)&1 ? set1 [i] : 0;
        }
        map1 [sum]++;
    }
    ll res = 0;
    for (int x = 0; x < (1 << (set2.size())); x++)
    {
        ll sum = 0;
        for (int i = 0; (x >> i); i++)
        {
            sum += (x >> i)&1 ? set2 [i] : 0;
        }
        res += map1 [0-sum];
    }
    cout << res - 1 << endl;
    return 0;
}
