#include <bits/stdc++.h>
using namespace std;
int freq [10001];
int n, temp;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &temp);
        freq [temp]++;
    }
    int greatest = 0;
    for (int x = 0; x < 10001; x++)
    {
        if (freq [x] > greatest)
        {
            greatest = freq [x];
        }
    }
    for (int x = 0; x < 10001; x++)
    {
        if (freq [x] == greatest)
        {
            printf ("%d\n", x);
            break;
        }
    }
    return 0;
}
