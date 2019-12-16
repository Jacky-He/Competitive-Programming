#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, k;

ll dp [12][1 << 10][103];

vector <int> path;

void helper (int length, int prev, vector <int>& v, vector<vector<int>>& combinations)
{
    if ((int)v.size() < length)
    {
        return;
    }
    if (length == 0)
    {
        combinations.push_back (path);
        return;
    }
    for (int x = prev + 1; x < (int)v.size(); x++)
    {
        if (prev == -1)
        {
            path.push_back (v[x]);
            helper (length - 1, x, v, combinations);
            path.pop_back ();
        }
        else if (v[x] > v[prev] + 1)
        {
            path.push_back (v[x]);
            helper (length - 1, x, v, combinations);
            path.pop_back ();
        }
    }
}

vector <vector<int>> allcombinations (int length, int prev, vector <int>& v)
{
    vector <vector<int>> result;
    helper (length, prev, v, result);
    return result;
}

ll solve (int row, int config, int numleft)
{
    if (dp [row][config][numleft] != -1)
    {
        return dp [row][config][numleft];
    }
    dp [row][config][numleft] = 0;
    vector <int> possible;
    for (int x = 0; x < n; x++)
    {
        if (n == 1)
        {
            if (!((config >> x)&1))
            {
                possible.push_back (x);
            }
        }
        else if (x == 0)
        {
            if (!((config >> x)&1) && !((config >> (x + 1))&1))
            {
                possible.push_back (x);
            }
        }
        else if (x == n)
        {
            if (!((config >> x)&1) && !((config >> (x - 1))&1))
            {
                possible.push_back (x);
            }
        }
        else
        {
            if (!((config >> x)&1) && !((config >> (x + 1))&1) && !((config >> (x - 1)&1)))
            {
                possible.push_back (x);
            }
        }
    }
    if (row == 1)
    {
        return dp [row][config][numleft] = allcombinations (numleft, -1, possible).size();
    }

    for (int length = 0 ; length <= numleft; length++)
    {
        for (vector <int> each: allcombinations (length, -1, possible))
        {
            int temp = 0;
            for (int each2: each)
            {
                temp |= (1 << each2);
            }
            dp [row][config][numleft] += solve (row - 1, temp, numleft - length);
        }
    }
    return dp [row][config][numleft];
}

int main ()
{
    scanf ("%d%d", &n, &k);
    memset (dp, -1, sizeof (dp));
    printf ("%lld\n", solve (n, 0, k));
    return 0;
}
