#include <bits/stdc++.h>
#define MAX_N 10000000
typedef unsigned long long int ull;
using namespace std;
int n, k;
int post [MAX_N*2 + 1];
int f, s;
int main ()
{
    scanf ("%d%d", &n, &k);
    while (n--)
    {
        scanf ("%d%d", &f, &s);
        post [f + MAX_N] = s;
    }
    ull counter = 0;
    int avletters = k;
    int x = 0;
    while (post [x] == 0 && x < MAX_N)
    {
        x++;
    }
    counter += abs (x - MAX_N);
    while (x < MAX_N)
    {
        if (avletters == 0)
        {
            counter += 2*abs (x - MAX_N);
            avletters = k;
        }
        if (post [x] <= avletters)
        {
            avletters -= post [x];
            post [x] = 0;
        }
        else
        {
            post [x] -= avletters;
            avletters = 0;
            int left = post [x]%k;
            int goback = post [x]/k;
            post [x] = left;
            counter += (ull)goback*2*abs (x - MAX_N);
            if (post [x] != 0)
            {
                counter += 2*abs (x - MAX_N);
                avletters = k - post [x];
                post [x] = 0;
            }
        }
        while (post [x] == 0 && x < MAX_N)
        {
            x++;
            counter++;
        }
    }
    x = MAX_N*2;
    avletters = k;
    while (post [x] == 0 && x > MAX_N)
    {
        x--;
    }
    counter += abs (x - MAX_N);
    while (x > MAX_N)
    {
        if (avletters == 0)
        {
            counter += 2*abs (x - MAX_N);
            avletters = k;
        }
        if (post [x] <= avletters)
        {
            avletters -= post [x];
            post [x] = 0;
        }
        else
        {
            post [x] -= avletters;
            avletters = 0;
            int left = post [x]%k;
            int goback = post [x]/k;
            post [x] = left;
            counter += (ull)goback*2*abs (x - MAX_N);
            if (post [x] != 0)
            {
                counter += 2*abs (x - MAX_N);
                avletters = k - post [x];
                post [x] = 0;
            }
        }
        while (post [x] == 0 && x > MAX_N)
        {
            x--;
            counter++;
        }
    }
    printf ("%lld\n", counter);
    return 0;
}
