#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, v, num;
vector <int> horizontals;
vector <int> verticals;
map <int, int> horidiffcnt;
ll res;

int main ()
{
    scanf ("%d%d", &h, &v);
    for (int x = 0; x < h; x++)
    {
        scanf ("%d", &num);
        for (int each: horizontals)
        {
            horidiffcnt [num-each]++;
        }
        horizontals.push_back(num);
    }
    for (int x = 0; x < v; x++)
    {
        scanf ("%d", &num);
        for (int each: verticals)
        {
            res += horidiffcnt [num - each];
        }
        verticals.push_back(num);
    }
    printf ("%lld\n", res);
    return 0;
}
