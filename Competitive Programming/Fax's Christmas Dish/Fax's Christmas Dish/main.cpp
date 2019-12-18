#include <bits/stdc++.h>
using namespace std;
int items, recipes, days;
int target, num;
int i;
vector <int> adj [300001];
int daysitems [300001];
int dfs (int node)
{
    int ma = 0;
    for (int each: adj [node])
    {
        ma = max(ma, dfs (each));
    }
    if (ma != 0)
    {
        return min (daysitems [node], ma);
    }
    return daysitems [node];
}
int main ()
{
    memset (daysitems, 0x3f, sizeof (daysitems));
    scanf ("%d%d%d", &items, &recipes, &days);
    for (int x = 0; x < recipes; x++)
    {
        scanf ("%d%d", &target, &num);
        for (int y = 0; y < num; y++)
        {
            scanf ("%d", &i);
            adj [target].push_back (i);
        }
    }
    for (int x = 1; x <= days; x++)
    {
        int something;
        scanf ("%d", &something);
        daysitems [something] = min (daysitems [something], x);
    }
    int answer = dfs (1);
    printf ("%d\n", answer == 0x3f3f3f3f? -1: answer);
    return 0;
}
