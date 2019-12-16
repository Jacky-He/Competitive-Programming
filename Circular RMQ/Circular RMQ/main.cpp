#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
using namespace std;
struct node
{
    int l, r;
    ll min, lazy;
};
int temps [3];
int n, q;
string line;
node tree [800004];
void push_down (int index)
{
    if (tree [index].l != tree [index].r)
    {
        tree [index<<1].lazy += tree [index].lazy;
        tree [index<<1|1].lazy += tree [index].lazy;
        tree [index<<1].min += tree [index].lazy;
        tree [index<<1|1].min += tree [index].lazy;
    }
    tree [index].lazy = 0;
}
void push_up (int index)
{
    tree [index].min = min (tree [index<<1].min, tree [index<<1|1].min);
}
void init (int left, int right, int index)
{
    tree [index].l = left;
    tree [index].r = right;
    tree [index].lazy = 0;
    if (left == right)
    {
        cin >> tree [index].min;
        return;
    }
    int mid = (left + right)>>1;
    init (left, mid, index<<1);
    init (mid + 1, right, index<<1|1);
    push_up (index);
}
void increment (int left, int right, int value, int index)
{
    if (left > right)
    {
        increment (left, n, value, index);
        increment (1, right, value, index);
        return;
    }
    if (tree [index].l == left && tree [index].r == right)
    {
        tree [index].lazy += value;
        tree [index].min += value;
        return;
    }
    if (tree [index].lazy)
    {
        push_down (index);
    }
    int mid = (tree [index].l + tree [index].r)/2;
    if (mid < left)
    {
        increment (left, right, value, index<<1|1);
    }
    else if (mid >= right)
    {
        increment (left, right, value, index <<1);
    }
    else
    {
        increment (mid + 1, right, value, index <<1|1);
        increment (left, mid, value, index<<1);
    }
    push_up (index);
}
ll rmq (int left, int right, int index)
{
    if (left > right)
    {
        return min (rmq (left, n, index), rmq (1, right, index));
    }
    if (tree [index].l == left && tree [index].r == right)
    {
        return tree [index].min;
    }
    if (tree[index].lazy)
    {
        push_down (index);
    }
    int mid = (tree [index].l + tree [index].r)/2;
    if (mid < left)
    {
        return rmq (left, right, index<<1|1);
    }
    else if (mid >= right)
    {
        return rmq (left, right, index<<1);
    }
    return min (rmq (mid + 1, right, index<<1|1), rmq (left, mid, index<<1));
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie(NULL);
    cin >> n;
    init (1, n, 1);
    cin >> q;
    getline (cin, line);
    for (int x = 0; x < q; x++)
    {
        getline (cin, line);
        int count = 0;
        int in = 0;
        string temp = "";
        for (int x = 0; x < (int)line.size(); x++)
        {
            if (line [x]!=' ')
            {
                temp += line [x];
            }
            else
            {
                temps [in] = stoi (temp);
                in++;
                temp = "";
                count++;
            }
        }
        temps [in] = stoi (temp);
        if (count + 1 == 2)
        {
            cout << rmq (temps [0] + 1, temps [1] + 1, 1) << endl;
        }
        else if (count + 1 == 3)
        {
            increment (temps [0] + 1, temps[1] + 1, temps [2], 1);
        }
    }
    return 0;
}
