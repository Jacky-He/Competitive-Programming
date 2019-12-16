#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n, k, num;
int arr [1000006];
int elecnt [1000006];

int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        arr [x] = num;
    }
    ll total = 0;
    int i = 0, j = 0;
    int numdistinct = 1;
    elecnt [arr[0]]++;
    while (j < n && i < n)
    {
        if (numdistinct < k)
        {
            j++;
            if (j == n)
            {
                continue;
            }
            if (elecnt [arr[j]] == 0)
            {
                numdistinct++;
            }
            elecnt [arr [j]]++;
        }
        else if (numdistinct == k)
        {
            elecnt [arr[i]]--;
            if (elecnt [arr[i]] == 0)
            {
                numdistinct--;
            }
            i++;
            total += n - j;
        }
    }
    printf ("%lld\n", total);
    return 0;
}
