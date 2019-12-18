#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct s
{
    ll sum = 0, co = 0, dif = 0;
};
int n, q;
int operation;
int l, r, a;
ll tree [4000002];
int hi [4000002];
int lo [4000002];
s delta [4000002];
void init (int left, int right, int index)
{
    hi [index] = right;
    lo [index] = left;
    if (left == right)
    {
        return;
    }
    int mid = (left + right)/2;
    init (left, mid, index*2);
    init (mid + 1, right, index*2 + 1);
}
void prop (int index)
{
    ll coefficient = delta [index].co;
    ll difference = delta [index].dif;
    int midindex = (lo [index] + hi [index])/2;
    tree [index] += delta [index].sum;
    delta [index*2].sum += (coefficient + (midindex - lo [index])*difference)*(midindex - lo [index] + 1)/2;
    delta [index*2 + 1].sum += delta [index].sum - delta [index*2].sum;
    delta [index*2].co += coefficient;
    delta [index*2 + 1].co += coefficient + (midindex - lo [index] + 1)*difference;
    delta [index*2].dif += difference;
    delta [index*2 + 1].dif += difference;
    delta [index].sum = 0;
    delta [index].co = 0;
    delta [index].dif = 0;
}
void increment (int left, int right, int coefficient, int index)
{
    if (hi [index] < left || lo [index] > right)
    {
        return;
    }
    if (hi [index] <= right && lo [index] >= left)
    {
        ll first = (lo [index] - left + 1)*coefficient;
        ll last = (hi [index] - left + 1)*coefficient;
        ll sum = (first + last)*(hi [index] - lo[index] + 1)/2;
        delta [index].sum += sum;
        delta [index].co += first;
        delta [index].dif += coefficient;
        return;
    }
    prop (index);
    increment (left, right, coefficient, index*2);
    increment (left, right, coefficient, index*2 + 1);
}
ll sum (int left, int right, int index)
{
    if (hi [index] < left || lo [index] > right)
    {
        return 0;
    }
    if (hi [index] <= right && lo [index] >= left)
    {
        return tree [index]  + delta [index].sum;
    }
    prop (index);
    return sum (left, right, index*2) + sum (left, right, index*2 + 1);
}
int main ()
{
    scanf ("%d%d", &n, &q);
    init (1, n, 1);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &operation);
        if (operation == 1)
        {
            scanf ("%d%d%d", &l, &r, &a);
            increment (l, r, a, 1);
        }
        else if (operation == 2)
        {
            scanf ("%d%d", &l, &r);
            printf ("%lld\n", sum (l, r, 1));
        }
    }
    return 0;
}
