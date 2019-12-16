#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, k, layer;
vector <int> layers;
int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &layer);
        layers.push_back (layer);
    }
    sort (layers.begin(), layers.end());
    int cnt = 1;
    int lastcardwidth = layers [0];
    for (int x = 1; x < (int)layers.size(); x++)
    {
        if (lastcardwidth + k <= layers [x])
        {
            lastcardwidth = layers [x];
            cnt++;
        }
    }
    printf ("%d\n", cnt);
    return 0;
}
