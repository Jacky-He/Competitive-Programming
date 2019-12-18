#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
using namespace std;

int chap, grou;
ll temp, temp2;
vector <ll> groups;
vector <ll> chapters;
ll solve (int group, int left, int right)
{
    if (group == (int) groups.size() - 1)
    {
        return ll(ceil((chapters [right] - chapters [left - 1])/(long double)(groups [group])));
    }
    if (group == (int) groups.size() - 2)
    {
        ll result = INF;
        for (int x = left - 1; x <= right; x++)
        {
            result = min(result, max(ll(ceil((chapters[x] - chapters[left - 1])/(long double)(groups [group]))), solve(group + 1, x + 1, right)));
        }
        for (int x = left; x <= right + 1; x++)
        {
            result = min(result, max(ll(ceil((chapters[right] - chapters[x - 1])/(long double) (groups [group]))), solve(group + 1, left, x - 1)));
        }
        return result;
    }
    ll result = INF;
    for (int x = left; x <= right + 1; x++)
    {
        for (int y = left - 1; y <= right; y++)
        {
            result = min(result, max (ll(ceil((chapters [y] - chapters [x - 1])/(long double)(groups [group]))), max(solve (group + 1, left, x - 1), solve (group + 2, y + 1, right))));
            result = min(result, max (ll(ceil((chapters [y] - chapters [x - 1])/(long double)(groups [group]))), max(solve (group + 1, y + 1, right), solve (group + 2, left, x - 1))));
        }
    }
    return result;
}
int main ()
{
    scanf ("%d%d", &chap, &grou);
    chapters.push_back (0);
    for (int x = 1; x <= chap; x++)
    {
        scanf ("%lld", &temp);
        chapters.push_back (temp);
    }
    for (int x = 1; x <= chap; x++)
    {
        chapters [x] = chapters [x] + chapters [x - 1];
    }
    for (int x = 0; x < grou; x++)
    {
        scanf ("%lld", &temp2);
        groups.push_back (temp2);
    }
    printf ("%lld\n", solve (0, 1, chap));
    return 0;
}