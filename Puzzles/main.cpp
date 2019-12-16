#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
vector <int> v;
int n, m;
int num;
int main()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d", &num);
        v.push_back (num);
    }
    sort (v.begin(), v.end());
    int result = INF;
    for (int i = 0, j = n - 1; j < m; i++, j++)
    {
        result = min (result, v [j] - v [i]);
    }
    printf ("%d\n", result);
    return 0;
}