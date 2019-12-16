#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int psa [200001];
int numnum [50001];
int n, k;
int temp;
int cnt;
int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &temp);
        psa [x] = (temp + psa [x - 1])%k;
        numnum [psa[x]]++;
    }
    cnt = numnum [0];
    for (int x = 0; x < k; x++)
    {
        int temp = numnum [x];
        cnt += (1 + temp-1)*(temp-1)/2;
    }
    printf ("%d\n", cnt);
    return 0;
}
