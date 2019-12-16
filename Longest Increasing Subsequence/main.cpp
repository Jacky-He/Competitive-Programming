#include <bits/stdc++.h>
using namespace std;
int n, num;
vector <int> v;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        if (v.empty() || num > v[v.size() - 1])
        {
            v.push_back (num);
        }
        else
        {
            v [lower_bound (v.begin(), v.end(), num) - v.begin()] = num;
        }
    }
    printf ("%d\n", (int)v.size());
    return 0;
}