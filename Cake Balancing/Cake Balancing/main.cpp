#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int l, r, w, num;
vector <int> lcakes;
vector <int> rcakes;
int psal [15], psar [15];
int dp [15][15][15][15][2]; //0: this pick left, 1: this pick right

int solve (int ll, int lr, int rl, int rr, bool pick)
{
    int& ret = dp [ll][lr][rl][rr][pick];
    if (ret != INF)
    {
        return ret;
    }
    if (ll == 14 && lr == 14 && rl == 14 && rr == 14)
    {
        return ret = 0;
    }
    if (pick)
    {
        for (int x = rl; x <= rr; x++)
        {
            for (int y = x; y <= rr; y++)
            {
                if (!(x == rl && y == rr))
                {
                    int dif = abs ((psal [lr] - psal [ll - 1]) - (psar [y] - psar [x - 1]));
                    if (dif <= w)
                    {
                        ret = min (ret, solve (ll, lr, x, y, !pick) + 1);
                    }
                }
            }
        }
        int dif = abs (psal [lr] - psal [ll - 1]);
        if (dif <= w)
        {
            ret = min (ret, solve (ll, lr, 14, 14, !pick) + 1);
        }
        return ret;
    }
    for (int x = ll; x <= lr; x++)
    {
        for (int y = x; y <= lr; y++)
        {
            if (!(x == ll && y == lr))
            {
                int dif = abs ((psal [y] - psal [x - 1]) - (psar [rr] - psar [rl - 1]));
                if (dif <= w)
                {
                    ret = min (ret, solve (x, y, rl, rr, !pick) + 1);
                }
            }
        }
    }
    int dif = abs (psar [rr] - psar [rl - 1]);
    if (dif <= w)
    {
        ret = min (ret, solve (14, 14, rl, rr, !pick) + 1);
    }
    return ret;
}
int main ()
{
    scanf ("%d%d%d", &l, &r, &w);
    for (int x = 0; x < 15; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            for (int a = 0; a < 15; a++)
            {
                for (int b = 0; b < 15; b++)
                {
                    dp [x][y][a][b][0] = INF;
                    dp [x][y][a][b][1] = INF;
                }
            }
        }
    }
    for (int x = 0; x < l; x++)
    {
        scanf ("%d", &num);
        lcakes.push_back (num);
    }
    sort (lcakes.begin(), lcakes.end());
    for (int x = 0; x < l; x++)
    {
        psal [x + 1] = psal [x] + lcakes [x];
    }
    for (int x = 0; x < r; x++)
    {
        scanf ("%d", &num);
        rcakes.push_back (num);
    }
    sort (rcakes.begin(), rcakes.end());
    for(int x = 0; x < r; x++)
    {
        psar [x + 1] = psar [x] + rcakes [x];
    }
    printf ("%d\n", min (solve (1, l, 1, r, 0), solve (1, l, 1, r, 1)));
    return 0;
}
