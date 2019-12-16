#include <bits/stdc++.h>
using namespace std;
bool winMatrix [501][501];
int main ()
{
    int players;
    scanf ("%d\n", &players);
    string str;
    for (int x = 1; x <= players; x++)
    {
        getline (cin, str);
        for (int y = 1; y <= players; y++)
        {
            if (str[y - 1] == '1')
            {
                winMatrix [x][y] = 1;
            }
        }
    }
    for (int k = 1; k <= players; k++)
    {
        for (int i = 1; i <= players; i++)
        {
            for (int x = 1; x <= players; x++)
            {
                if (winMatrix [i][k] && winMatrix [k][x])
                {
                    winMatrix [i][x] = 1;
                }
            }
        }
    }
    int counter = 0;
    for (int i = 1; i <= players; i++)
    {
        for (int x = 1; x <= players; x++)
        {
            if (winMatrix [i][x])
            {
                counter++;
            }
        }
    }
    printf ("%d\n", (players - 1)*players/2 - counter);
    return 0;
}
