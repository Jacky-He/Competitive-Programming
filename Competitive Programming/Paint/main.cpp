#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
map <ll, ll> dp;
ll n, k, from, to;
vector <pair <ll, ll>> people;
bool cmp (pair <ll, ll> p1, pair <ll, ll> p2)
{
    return p1.second < p2.second;
}
vector <ll> things;
int main()
{
    scanf("%lld%lld", &n, &k);
    for (int x = 0; x < k; x++)
    {
        scanf("%lld%lld", &from, &to);
        people.push_back({from, to});
    }
    sort(people.begin(), people.end(), cmp);
    ll result = 0;
    for (int x = 0; x < people.size(); x++)
    {
        int index = (int)(lower_bound (things.begin(), things.end(), people [x].first - 1) - things.begin());
        if (index >= 1)
        {
            dp[people[x].second] = max(result, max(dp[people[x].second], people[x].second - people[x].first + 1 + dp[things[index - 1]]));
        }
        else
        {
            dp[people[x].second] = max(result, people[x].second - people[x].first + 1);
        }
        things.push_back(people[x].second);
        result = dp[people[x].second];
    }
    printf("%lld\n", n - result);
    return 0;
}