#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int arr [505];
int dp [505][505];
int main()
{
    scanf ("%d%d", &n, &k);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &arr [x]);
        for (int y = 0; y <= k; y++)
        {
            dp [x][y] = dp [x - 1][k - y] + (y > arr [x]? y - arr [x] : 0);
        }
    }
    pair <int, int> mini = {INF, INF};
    for (int x = 0; x <= k; x++)
    {
        if (dp [n][x] < mini.first)
        {
            mini = {dp [n][x], x};
        }
    }
    printf ("%d\n", mini.first);
    for (int x = 1, start = n%2 == 0? k - mini.second: mini.second; x <= n; x++, start = k - start)
    {
        printf ("%d ", start < arr [x]? arr [x]: start);
    }
    return 0;
}
