#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;
typedef long long int ll;

struct info {ll start, end, sum, maxsum;};
int n, q, a;
string op;
ll num, b;
info* blocks;
int BSIZE;
ll elements [100200];
int testcases;
vector <string> outputs;

void build ()
{
    for (int x = 0; x < BSIZE && x*BSIZE < n; x++)
    {
        ll sum = 0;
        ll prev = 0;
        ll maxi = -INF;
        for (int y = x*BSIZE; y < n && y < (x + 1)*BSIZE; y++)
        {
            prev = max (elements [y], prev + elements [y]);
            maxi = max (maxi, prev);
            sum += elements [y];
        }
        blocks [x].end = prev;
        blocks [x].sum = sum;
        blocks [x].maxsum = maxi;
        prev = 0;
        for (int y = min ((n - 1), (x + 1)*BSIZE - 1); y >= x*BSIZE; y--)
        {
            prev = max (elements [y], prev + elements [y]);
        }
        blocks [x].start = prev;
    }
}

ll query (int left, int right)
{
    int leftblock = left/BSIZE;
    int rightblock = right/BSIZE;

    ll prev = 0;
    ll maxi = -INF;
    for (int x = left; x <= right && x < (leftblock + 1)*BSIZE; x++)
    {
        prev = max (elements [x], prev + elements [x]);
        maxi = max (maxi, prev);
    }
    for (int x = leftblock + 1; x < rightblock; x++)
    {
        maxi = max (maxi, prev + blocks [x].start);
        prev = max (prev + blocks [x].sum, blocks [x].end);
        maxi = max (maxi, prev);
        maxi = max (maxi, blocks [x].maxsum);
    }
    if (leftblock != rightblock)
    {
        for (int x = max(left, rightblock*BSIZE); x <= right; x++)
        {
            prev = max (elements [x], prev + elements [x]);
            maxi = max (maxi, prev);
        }
    }
    return maxi;
}

void update (int idx, ll value)
{
    int block = idx/BSIZE;
    blocks [block].sum += value - elements [idx];
    elements [idx] = value;
    ll prev = 0;
    ll maxi = -INF;
    for (int x = block*BSIZE; x < n && x < (block + 1)*BSIZE; x++)
    {
        prev = max (elements [x], prev + elements [x]);
        maxi = max (maxi, prev);
    }
    blocks [block].end = prev;
    blocks [block].maxsum = maxi;
    prev = 0;
    for (int x = min ((n - 1), (block + 1)*BSIZE - 1); x >= block*BSIZE; x--)
    {
        prev = max (elements [x], prev + elements [x]);
    }
    blocks [block].start = prev;
}

void solve ()
{
    string res = "";
    cin >> n >> q;
    BSIZE = (int)(ceil(sqrt (n)));
    blocks = new info [BSIZE];
    for (int x = 0; x < n; x++)
    {
        cin >> num;
        elements [x] = num;
    }
    build();
    for (int x = 0; x < q; x++)
    {
        cin >> op >> a >> b;
        if (op == "S")
        {
            update (a - 1, b);
        }
        else if (op == "Q")
        {
            cout << query (a - 1, (int) b - 1) << endl;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie (0); cout.tie (0);
    solve();
    return 0;
}

/*
 9 2
 -10 -9 1 4 -2 6 3 1 -10
 S 1 2
 Q 1 9
 
 45 1
 -5842 3161 9002 6894 -4895 -3444 -4908 -7059 -8702 -5559 4927 -2843 4745 9175 -3287 4545 5527 -7835 -4006 -5122 -1264 -8699 -2030 3952 5893 -6933 -9410 9916 -4557 -8541 5813 1238 -3150 5796 7825 -1803 3128 9804 -998 -1218 -4252 3388 9333 184 6714
 Q 7 42
 
 47 1
 -8 -83 -89 9 -23 -57 -29 60 -48 -40 -31 -85 91 -83 -37 |25 59 -94 -48 -5 -44 74 20 60 10 -44 -10 -6 -57 76 40| -49 52 24 49 43 -23 51 49 -21 -85 88 -42 -89 -43 93 -36
 Q 16 31
 
 47 1
 -8 -83 -89 9 -23 -57 -29 60 -48 -40 -31 -85 91 -83 -37 25 59 -94 -48 -5 -44 74 20 60 10 -44 -10 -6 -57 76 40 -49 52 24 49 43 -23 51 49 -21 -85 88 -42 -89 -43 93 -36
 Q 16 31
 
 
 
*/


