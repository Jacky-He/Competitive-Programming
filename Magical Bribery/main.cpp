#include <bits/stdc++.h>
using namespace std;
int dp [1001];
int costs [1001];
int cards, card;
int main ()
{
    scanf ("%d", &cards);
    for (int x = 1; x <= cards; x++)
    {
        scanf ("%d", &card);
        costs [x] = card;
    }
    for (int x = 1; x <= cards; x++)
    {
        for (int y = 1; y <= cards; y++)
        {
            if (x - y >= 0)
            {
                dp [x] = max (dp [x - y] + costs [y], dp [x]);
            }
        }
    }
    printf ("%d\n", dp [cards]);
    return 0;
}
