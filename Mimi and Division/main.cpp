#include <bits/stdc++.h>
#define blocksize 448
using namespace std;
typedef long long int ll;

int n, q, num;
int blocks [blocksize][200004];
int arr [200004];
int operation, a, b, c;

vector <int> factors (int num)
{
    vector <int> v;
    int root = (int)sqrt (num);
    for (int x = 1; x <= root; x++)
    {
        if (num%x == 0)
        {
            v.push_back (x);
            v.push_back (num/x);
        }
    }
    if (root*root == num)
    {
        v.pop_back();
    }
    return v;
}

void build ()
{
    for (int x = 0; x < n; x++)
    {
        for (int each: factors (arr [x]))
        {
            blocks [x/blocksize][each]++;
        }
    }
}

void update (int index, int value)
{
    for (int each: factors (arr [index]))
    {
        blocks [index/blocksize][each]--;
    }
    for (int each: factors (value))
    {
        blocks [index/blocksize][each]++;
    }
    arr [index] = value;
}

int query (int left, int right, int divisor)
{
    int cnt = 0;
    if (left/blocksize == right/blocksize)
    {
        for (int x = left; x <= right; x++)
        {
            cnt += arr [x]%divisor == 0;
        }
        return cnt;
    }
    for (int x = left; x < (left/blocksize + 1)*blocksize; x++)
    {
        cnt += arr [x]%divisor == 0;
    }
    for (int x = right/blocksize*blocksize; x <= right; x++)
    {
        cnt += arr [x]%divisor == 0;
    }
    for (int x = left/blocksize + 1; x < right/blocksize; x++)
    {
        cnt += blocks [x][divisor];
    }
    return cnt;
}

int main ()
{
    scanf ("%d%d", &n, &q);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        arr [x] = num;
    }
    build ();
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &operation);
        if (operation == 1)
        {
            scanf ("%d%d%d", &a, &b, &c);
            printf ("%d\n", query (a - 1, b - 1, c));
        }
        else if (operation == 2)
        {
            scanf ("%d%d", &a, &b);
            update (a - 1, b);
        }
    }
    return 0;
}


