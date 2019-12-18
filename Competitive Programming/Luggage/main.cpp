#include <bits/stdc++.h>
using namespace std;
int n, k, num;
vector <int> v;
bool check (int items)
{
    for (int x = 0; x + items - 1 < n; x++)
    {
        if (abs(v [x] - v [x + items - 1]) <= k)
        {
            return true;
        }
    }
    return false;
}
int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        v.push_back (num);
    }
    sort (v.begin(), v.end());
    int lo = 1;
    int hi = n;
    while (lo + 1 < hi)
    {
        
        int mid = (lo + hi)/2;
        if (check (mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    int result = 0;
    if (check (hi))
    {
        result = hi;
    }
    else if (check (lo))
    {
        result = lo;
    }
    printf ("%d\n", result);
    return 0;
}



