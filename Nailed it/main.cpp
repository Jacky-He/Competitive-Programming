#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int min (int a, int b)
{
    return (a < b)? a : b;
}
int main ()
{
    int N;
    scanf ("%d", &N);
    int num = 0;
    int frequencies [2001];
    fill_n (frequencies, 2001, 0);
    int sum [4001];
    fill_n (sum, 4001, 0);
    for (int x = 0; x < N; x++)
    {
        scanf ("%d", &num);
        frequencies [num] += 1;
    }
    for (int x = 1; x < 2001; x++)
    {
        if (frequencies [x] != 0)
        {
            for (int y = x; y < 2001; y++)
            {
                if (x == y)
                {
                    sum [x + y] += frequencies [x] / 2;
                }
                else if (frequencies [y] != 0)
                {
                    int times = min (frequencies [x], frequencies [y]);
                    sum [x + y] += times;
                }
            }
        }
    }
    int max = 0;
    int numHeights = 0;
    for (int x = 0; x < 4001; x++)
    {
        if (sum [x] == max)
        {
            numHeights++;
        }
        if (sum [x] > max)
        {
            numHeights = 1;
            max = sum [x];
        }
    }
    cout << max << " " << numHeights << endl;
    return 0;
}
