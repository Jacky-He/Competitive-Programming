#include <bits/stdc++.h>
using namespace std;
int pies, people;
int dp [251][251]; //pies, people
int main ()
{
    scanf ("%d%d", &pies, &people);
    for (int x = 1; x <= pies; x++)
    {
        dp [x][1] = 1;
    }
    for (int x = 1; x <= people; x++)
    {
        dp [x][x] = 1;
    }
    for (int col = 2; col <= people; col++)
    {
        for (int row = col + 1; row <= pies; row++)
        {
            int sum = 0;
            for (int i = row - 1; i > 0; i-= col)
            {
                sum += dp [i][col - 1];
            }
            dp [row][col] = sum;
        }
    }
    printf ("%d", dp [pies][people]);
    return 0;
}
