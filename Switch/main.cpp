#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int k, n;
int config = 0;
unordered_map <int, int> dis;
queue <int> Q;

int main ()
{
    scanf ("%d", &k);
    for (int x = 0; x < k; x++)
    {
        scanf ("%d", &n);
        config += (n << x);
    }
    Q.push(config);
    dis [config] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        int consecutive = 0;
        for (int x = 0; x < k; x++)
        {
            if ((temp >> x)&1)
            {
                consecutive++;
            }
            else
            {
                consecutive = 0;
            }
            if (consecutive >= 4)
            {
                temp &= (~(((1 << consecutive) - 1) << (x - consecutive + 1)));
            }
        }
        for (int x = 0; x < k; x++)
        {
            if (!((temp >> x)&1))
            {
                int next = temp|(1 << x);
                consecutive = 0;
                for (int x = 0; x < k; x++)
                {
                    if ((next >> x)&1)
                    {
                        consecutive++;
                    }
                    else
                    {
                        consecutive = 0;
                    }
                    if (consecutive >= 4)
                    {
                        next &= (~(((1 << consecutive) - 1) << (x - consecutive + 1)));
                    }
                }
                if (!dis.count (next) || dis [next] > dis [temp] + 1)
                {
                    dis [next] = dis [temp] + 1;
                    if (next == 0)
                    {
                        printf ("%d\n", dis [next]);
                        return 0;
                    }
                    Q.push (next);
                }
            }
        }
    }
    return 0;
}
