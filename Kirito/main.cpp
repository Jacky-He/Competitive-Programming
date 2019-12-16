#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f
#define seed 31
using namespace std;
typedef long long int ll;

struct s
{
    int max; int number; int l; int r;
};

int n, m, q, i, j;
string line;

ll powers [5005];
ll hashes [2002][5005];
s tree [2002*4 + 4];
int nums [2002];

void computepower ()
{
    powers [0] = 1;
    for (int x = 1; x < 5005; x++)
    {
        powers [x] = powers [x - 1]*seed;
    }
}

void computehash (string str, int number)
{
    for (int x = 0; x < (int) str.length(); x++)
    {
        hashes [number][x + 1] = hashes [number][x] + str [x]*powers [x];
    }
}

bool check (int index, int number1, int number2)
{
    return hashes [number1][index] == hashes [number2][index];
}

int bsearch (pair <int, int> p1, pair <int, int> p2)
{
    int length = min (p1.first, p2.first);
    int hi = length;
    int lo = 0;
    while (lo + 1 < hi)
    {
        int mid = (hi + lo)/2;
        if (check (mid, p1.second, p2.second))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if (check (hi, p1.second, p2.second))
    {
        return hi;
    }
    return lo;
}

void push_up (int index)
{
    if (tree [index].l == tree [index].r) {return;}
    if (tree [index*2].number == 0)
    {
        tree [index].number = tree [index*2 + 1].number;
        tree [index].max = tree [index*2 + 1].max;
        return;
    }
    if (tree [index*2 + 1].number == 0)
    {
        tree [index].number = tree [index*2].number;
        tree [index].max = tree [index*2].max;
        return;
    }
    tree [index].number = tree [index*2].number;
    tree [index].max = bsearch ({tree [index*2].max, tree[index*2].number}, {tree [index*2 + 1].max, tree [index*2 + 1].number});
}

void init (int index, int left, int right)
{
    tree [index].l = left;
    tree [index].r = right;
    if (left == right)
    {
        tree [index].number = left;
        tree [index].max = m;
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
    push_up (index);
}

void update (int index, int left, int right, int newnum)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return;
    }
    if (tree [index].r <= right && tree [index].l >= left)
    {
        tree [index].max = m;
        tree [index].number = newnum;
        return;
    }
    update (index*2, left, right, newnum);
    update (index*2 + 1, left, right, newnum);
    push_up (index);
}

pair <int, int> query (int index, int left, int right)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return {INF, 0};
    }
    if (tree [index].r <= right && tree [index].l >= left)
    {
        return {tree [index].max, tree [index].number};
    }
    pair <int, int> le = query (index*2, left, right);
    pair <int, int> ri = query (index*2 + 1, left, right);
    //cout << le.first << " " << le.second << " " << ri.first << " " << ri.second << endl;
    if (le.second != 0 && ri.second != 0)
    {
        return {bsearch (le, ri), le.second};
    }
    if (le.second != 0)
    {
        return le;
    }
    return ri;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    computepower();
    for (int x = 1; x <= n; x++)
    {
        cin >> line;
        computehash (line, x);
        nums [x] = x;
    }
    cin >> q;
    init (1, 1, n);
    for (int x = 0; x < q; x++)
    {
        cin >> i >> j;
        cout << query (1, i, j).first*(j - i + 1) << endl;
        int temp = nums [i];
        nums [i] = nums [j];
        nums [j] = temp;
        update (1, i, i, nums [i]);
        update (1, j, j, nums [j]);
    }
    return 0;
}
