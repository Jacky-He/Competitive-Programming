#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 150004
#define BSIZE 388
using namespace std;

int n, m, q, num, op, l, r;
vector <int> lines [MAXN];
vector <pair <int, pair <int, int>>> blocknum [MAXN];
//pair <int, int> blocknum [MAXN][BSIZE];
int people [MAXN];
pair <int, int> line [MAXN]; //first: line num, second: index in line;
int shifts [MAXN];
vector <int> psa [MAXN];

int blocks [BSIZE]; //0-indexed

void build ()
{
    for (int x = 1; x <= n; x++)
    {
        blocks [(x - 1)/BSIZE] += people [x];
    }
    for (int x = 1; x <= m; x++)
    {
        int block = -1;
        pair <int, int> p = {-1, -1};
        for (int y = 0; y < (int) lines [x].size(); y++)
        {
            if (block != (lines [x][y] - 1)/BSIZE)
            {
                blocknum [x].push_back ({block, p});
                block = (lines [x][y] - 1)/BSIZE;
                p = {y, y};
            }
            else
            {
                p.second = y;
            }
        }
        if (p.first != -1 && p.second != -1)
        {
            blocknum [x].push_back ({block, p});
        }
    }
}

int getPeopleAt (int x)
{
    int idx = line [x + 1].second;
    int linenum = line [x + 1].first;
    int shift = shifts [linenum];
    int size = (int) lines [linenum].size();
    idx = (idx - shift + size)%size;
    return people [lines [linenum][idx]];
}

int query (int left, int right)
{
    int leftblock = left/BSIZE;
    int rightblock = right/BSIZE;
    int res = 0;
    if (leftblock == rightblock)
    {
        for (int x = left; x <= right; x++)
        {
            res += getPeopleAt(x);
        }
        return res;
    }
    for (int x = left; x < (leftblock + 1)*BSIZE; x++)
    {
        res += getPeopleAt (x);
    }
    for (int x = leftblock + 1; x < rightblock; x++)
    {
        res += blocks [x];
    }
    for (int x = rightblock*BSIZE; x <= right; x++)
    {
        res += getPeopleAt (x);
    }
    return res;
}

int crsq (int left, int right, int linenum)
{
    if (left > right)
    {
        int size = (int) lines [linenum].size();
        return psa [linenum][right] + psa [linenum][size] - psa [linenum][left - 1];
    }
    return psa [linenum][right] - psa [linenum][left - 1];
}

void update (int linenum)
{
    int size = (int)lines [linenum].size();
    int shift1 = shifts [linenum];
    shifts [linenum] = (shifts [linenum] + 1)%size;
    int shift2 = shifts [linenum];
    for (pair <int, pair <int, int>> each: blocknum [linenum])
    {
        int x = each.first;
        int index1 = each.second.first;
        int index2 = each.second.second;
        if (index1 == -1  && index2 == -1)
        {
            continue;
        }
        int oldsum = crsq ((index1 - shift1 + size)%size + 1, (index2 - shift1 + size)%size + 1, linenum);
        int newsum = crsq ((index1 - shift2 + size)%size + 1, (index2 - shift2 + size)%size + 1, linenum);
        blocks [x] += (newsum - oldsum);
    }
}

int main ()
{
    auto startt = std::chrono::system_clock::now();
    scanf ("%d%d%d", &n, &m, &q);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        line [x] = {num, (int)lines [num].size()};
        lines [num].push_back (x);
    }
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        people [x] = num;
    }
    for (int x = 1; x <= m; x++)
    {
        shifts [x] = 0;
        int temp = 0;
        psa [x].push_back(temp);
        for (int each: lines [x])
        {
            temp += people [each];
            psa [x].push_back (temp);
        }
    }
    build();
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &op);
        if (op == 1)
        {
            scanf ("%d%d", &l, &r);
            int ans = query (l - 1, r - 1);
            printf ("%d\n", ans);
        }
        else if (op == 2)
        {
            scanf ("%d", &num);
            update (num);
        }
    }
    //std::this_thread::sleep_until (startt + chrono::milliseconds (6910));
    return 0;
}

/*
5 2 5
1 2 1 2 2
1 2 3 4 5
1 1 5
2 1
1 3 5
2 2
1 1 3




3 1 7
1 1 1
114 101 109
1 1 1
2 1
1 1 1
2 1
1 1 1
2 1
1 1 1




*/
