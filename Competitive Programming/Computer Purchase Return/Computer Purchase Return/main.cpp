#include <bits/stdc++.h>
using namespace std;
int types, N, budget;
int cost, value, tp;
int dp [6][3001];
vector <pair <int, int>> type [6]; //first: cost, second: value;
int main ()
{
    scanf ("%d%d", &types, &N);
    for (int x = 0; x < N; x++)
    {
        scanf ("%d%d%d", &cost, &value, &tp);
        type [tp].push_back ({cost, value});
    }
    scanf ("%d", &budget);
    for (int y = 1; y <= types; y++)
    {
        for (pair <int, int> each: type [y])
        {
            for (int x = each.first; x <= budget; x++)
            {
                dp [y][x] = max (dp [y][x], dp [y - 1][x - each.first] + each.second);
            }
        }
    }
    printf ("%d\n", dp [types][budget] == 0? -1:dp [types][budget]);
    return 0;
}
