#include <bits/stdc++.h>
using namespace std;
int n, t, k, v;
int num;
bool filled [1000006];
int main ()
{
    scanf ("%d%d%d%d", &n, &t, &k, &v);
    for (int x = 0; x < v; x++)
    {
        scanf ("%d", &num);
        filled [num] = true;
    }
    int curr = 0;
    int cnt = 0;
    for (int x = 0; x < t; x++)
    {
        curr += filled [x];
    }
    for (int i = 1, j = t; j <= n; i++, j++)
    {
        curr -= filled [i - 1];
        curr += filled [j];
        int index = j;
        while (curr < k)
        {
            if (!filled [index])
            {
                filled [index] = true;
                cnt++;
                curr++;
            }
            index--;
        }
    }
    printf ("%d\n", cnt);
    return 0;
}




