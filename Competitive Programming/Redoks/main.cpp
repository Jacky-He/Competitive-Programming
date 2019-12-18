#include <bits/stdc++.h>
#define MAXN 250000
using namespace std;
typedef long long int ll;
int n, m, a, b;
string str;
int lo [4*MAXN + 6];
int hi [4*MAXN + 6];
int lazy [4*MAXN + 6];
int arr [4*MAXN + 6][10];

void push_up (int index)
{
    for (int x = 0; x < 10; x++)
    {
        arr [index][x] = arr [index*2][x] + arr [index*2 + 1][x];
    }
}
int push_down (int index)
{
    int cnt = 0;
    int temparr [10];
    for (int x = 0; x < 10; x++)
    {
        temparr [(x + lazy [index])%10] = arr [index][x];
    }
    for (int x = 0; x < 10; x++)
    {
        arr [index][x] = temparr [x];
        cnt += x*temparr [x];
    }
    lazy [index*2] += lazy [index];
    lazy [index*2 + 1] += lazy [index];
    lazy [index] = 0;
    return cnt;
}

void update (int index, int left, int right)
{
    if (lo [index] > right || hi [index] < left)
    {
        push_down (index);
        return;
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        lazy [index]++;
        push_down (index);
        return;
    }
    push_down (index);
    update (index*2, left, right);
    update (index*2 + 1, left, right);
    push_up (index);
}

int query (int index, int left, int right)
{
    if (lo [index] > right || hi [index] < left)
    {
        return 0;
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        return  push_down (index);
    }
    push_down (index);
    return query (index*2, left, right) + query (index*2 + 1, left, right);
}

void init (int index, int left, int right)
{
    lo [index] = left;
    hi [index] = right;
    if (left == right)
    {
        memset (arr [index], 0, sizeof (arr [index]));
        arr [index][str [left - 1] - '0'] = 1;
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
    push_up (index);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie (nullptr);
    cin >> n >> m;
    cin >> str;
    init (1, 1, n);
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        cout << query (1, a, b) << endl;
        update (1, a, b);
    }
    return 0;
}
