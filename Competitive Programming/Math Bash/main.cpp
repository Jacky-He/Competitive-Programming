#include <bits/stdc++.h>
#define MAXN 808
using namespace std;
typedef long long int ll;

int bit [MAXN][MAXN];

int n, num;
priority_queue<pair <int, pair <int, int>>, vector<pair <int, pair <int, int>>>, greater<pair <int, pair<int, int>>>> unchecked;
priority_queue<pair <int, pair <int, int>>, vector<pair <int, pair <int, int>>>, greater<pair <int, pair<int, int>>>> checked;

int lowbit (int n) {return n&(-n);}

int query (int index, int index2)
{
    int sum = 0;
    while (index > 0)
    {
        int temp = index2;
        while (temp > 0)
        {
            sum += bit [index][temp];
            temp -= lowbit(temp);
        }
        index -= lowbit (index);
    }
    return sum;
}

void update (int index, int index2, int increment)
{
    while (index <= n)
    {
        int temp = index2;
        while (temp <= n)
        {
            bit [index][temp] += increment;
            temp += lowbit (temp);
        }
        index += lowbit(index);
    }
}



int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            cin >> num;
            unchecked.push ({num, {x, y}});
        }
    }
    
    ll res = 0;
    while (!checked.empty() || !unchecked.empty())
    {
        while (unchecked.empty() || (!checked.empty() && checked.top().first < unchecked.top().first))
        {
            if (checked.empty() && unchecked.empty()) break;
            pair <int, pair <int, int>> temp = checked.top();
            checked.pop();
            update(temp.second.first, temp.second.second, 1);
        }
        
        while (checked.empty() || (!unchecked.empty() && unchecked.top().first <= checked.top().first))
        {
            if (checked.empty() && unchecked.empty()) break;
            pair <int, pair <int, int>> temp = unchecked.top();
            unchecked.pop();
            ll increase = (temp.second.first - 1)*(temp.second.second - 1) - query (temp.second.first - 1, temp.second.second  - 1);
            res += increase;
            temp.first += increase;
            checked.push (temp);
        }
    }
    cout << res << endl;
    return 0;
}
