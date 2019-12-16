#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, v;
int cost, num;
int arr [2002];
int dp [10003];
vector <pair <pair <int, int>, int>> input; //first: numavailable, second: cost, third: order
vector <pair <int, int>> output; //first: order, second: output;
int main ()
{
    memset (dp , 0x3f, sizeof (dp));
    dp [0] = 0;
    scanf ("%d%d", &n, &v);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    for (int x = 0; x < v; x++)
    {
        scanf ("%d%d", &cost, &num);
        input.push_back ({{num, cost}, x});
    }
    sort (input.begin(), input.end());
    int index = 0;
    for (int type = 1; type <= n; type++)
    {
        for (int x = 1; x < 10003; x++)
        {
            if (x - arr [type] >= 0)
            {
                dp [x] = min (dp [x], dp [x - arr [type]] + 1);
            }
            while (index < v && input [index].first.first == type && input [index].first.second == x)
            {
                output.push_back ({input [index].second, dp [x]});
                index++;
            }
        }
    }
    sort (output.begin(), output.end());
    for (int x = 0; x < (int)output.size(); x++)
    {
        printf ("%d\n", output [x].second == INF? -1:output[x].second);
    }
    return 0;
}
