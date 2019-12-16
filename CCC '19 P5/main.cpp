#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, k, num;
int nums [3003][3003];
int numsflip [3003][3003];
int cpy [3003][3003];
stack <bool> s;

int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            scanf ("%d", &nums [x][y]);
            numsflip [x][y] = nums [x][y];
        }
    }
    
    //brute
    /*for (int ck = 1; ck < k; ck++)
    {
        for (int x = 1; x <= n - ck; x++)
        {
            for (int y = 1; y <= x; y++)
            {
                nums [x][y] = max(max (nums [x][y], nums [x + 1][y]), nums [x + 1][y + 1]);
            }
        }
    }
    
    ll res = 0;
    for (int x = 1; x <= n - k + 1; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            res += nums [x][y];
            cout << nums [x][y] << " ";
        }
        cout << endl;
    }
    printf ("%lld\n", res);*/
    
    
    int ck = k;
    while (ck != 1)
    {
        if (ck == 2)
        {
            s.push (true);
            ck--;
        }
        else if (ck % 2 == 0) //even
        {
            s.push(false);
            ck /= 2;
        }
        else
        {
            s.push (true);
            ck--;
        }
    }
    while (!s.empty())
    {
        if (s.top()) //add one thing
        {

            for (int x = 1; x <= n - ck; x++)
            {
                for (int y = 1; y <= x; y++)
                {
                    nums [x][y] = max(max (nums [x][y], nums [x + 1][y]), nums [x + 1][y + 1]);
                }
            }
            
            for (int x = n; x >= 2; x--)
            {
                for (int y = n; y >= 2; y--)
                {
                    numsflip [x][y] = max(max (numsflip [x][y], numsflip [x - 1][y]), numsflip [x - 1][y - 1]);
                }
            }
            ck++;
        }
        else //binary thing
        {
            for (int x = 1; x <= n - ck; x++)
            {
                for (int y = 1; y <= x; y++)
                {
                    cpy [x][y] = nums[x][y];
                }
            }
            for (int x = 1; x <= (n - 2*ck + 1); x++)
            {
                for (int y = 1; y <= x; y++)
                {
                    nums [x][y] = max(max(max(nums [x][y], nums [x + ck][y]), numsflip [x+2*ck-1][y+ck]), nums [x + ck][y + ck]);
                }
            }
            
            for (int x = n; x >= 2*ck - 1; x--)
            {
                for (int y = n; y >= 2*ck-1; y--)
                {
                    numsflip [x][y] = max (max(max(numsflip [x][y], numsflip [x - ck][y]), numsflip [x - ck][y - ck]), cpy [x-2*ck+1][y-ck]);
                }
            }
            ck *= 2;
        }
        s.pop();
    }
    ll res = 0;
    for (int x = 1; x <= n - ck + 1; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            res += nums [x][y];
        }
    }
    printf ("%lld\n", res);
    return 0;
}
/*
12 8
1
5 10
3 5 6
1 9 4 6
23 5 6 24 6
2 2 2 2 2 2
19 9 9 23 1 1 7
8 7 6 5 4 3 2 1
9 2 39 2 9 3 3 3 3
9 19 2 9 7 7 3 2 39 10
10 10 29 39 10 47 1 2 3 10 11
1 8 2 9 3 9 2 8 3 8 4 9


*/
/*
24
39 39
39 39 39
47 47 47 47
47 47 47 47 47

*/
