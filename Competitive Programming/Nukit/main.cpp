#include <bits/stdc++.h>
using namespace std;
struct reaction
{
    int a, b, c, d;
};
reaction maker (int a, int b, int c, int d)
{
    reaction r; r.a = a; r.b = b; r.c = c; r.d = d; return r;
}
int testcases, a, b, c, d;
bool dp [31][31][31][31]; //0: if who ever starts will lose 1: if who ever starts will win
vector <reaction> reactions;
int main ()
{
    scanf ("%d", &testcases);
    reactions.push_back (maker (1, 0, 0, 1));
    reactions.push_back (maker (0, 3, 0, 0));
    reactions.push_back (maker (0, 0, 2, 1));
    reactions.push_back (maker (1, 1, 1, 1));
    reactions.push_back (maker (2, 1, 0, 2));
    for (int x = 0; x < 31; x++)
    {
        for (int y = 0; y < 31; y++)
        {
            for (int i = 0; i < 31; i++)
            {
                for (int j = 0; j < 31; j++)
                {
                    for (reaction each: reactions)
                    {
                        if (x - each.a >= 0 && y - each.b >= 0 && i - each.c >= 0 && j - each.d >= 0)
                        {
                            if (dp [x - each.a][y - each.b][i - each.c][j - each.d] == 0)
                            {
                                dp [x][y][i][j] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    while (testcases--)
    {
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        printf (dp [a][b][c][d]? "Patrick\n":"Roland\n");
    }
    return 0;
}
