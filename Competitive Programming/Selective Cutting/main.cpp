#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct FenwickTree
{
    ll* pt; int size;
    ll lowbit (ll a) {return a&(-a);}
    void add (int index, ll delta)
    {
        while (index <= size)
        {
            pt [index] += delta;
            index += lowbit (index);
        }
    }
    ll querie (int index)
    {
        ll sum = 0;
        while (index > 0)
        {
            sum += pt [index];
            index -= lowbit (index);
        }
        return sum;
    }
    ll querie (int left, int right)
    {
        return querie (right) - querie (left - 1);
    }
    void init (int size)
    {
        pt = new ll [size + 1];
        this -> size = size;
        for (int x = 0; x <= size; x++)
        {
            pt [x] = 0;
        }
    }
};
struct q
{
    int from, to, weight, number;
};
bool cmp (pair <int,int> p1, pair <int, int> p2)
{
    return p1.first > p2.first;
}
bool cmpq (q q1, q q2)
{
    return q1.weight > q2.weight;
}
q makeq (int from, int to, int weight, int number)
{
    q some; some.from = from; some.to = to; some.weight = weight; some.number = number;
    return some;
}
int n, tree, queries;
int a, b, c;
vector <q> todo;
ll output [100001];
int main ()
{
    scanf ("%d", &n);
    pair <int, int> trees [n + 1]; //first: tree height, second: index
    trees [0] = {0, 0};
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &tree);
        trees [x] = {tree, x};
    }
    sort (trees, trees + n + 1, cmp);
    scanf ("%d", &queries);
    for (int x = 0; x < queries; x++)
    {
        scanf ("%d%d%d", &a, &b, &c);
        todo.push_back (makeq (a, b, c, x));
    }
    sort (todo.begin(), todo.end(), cmpq);
    FenwickTree freq;
    freq.init (n);
    for (int x = 0, y = 0; y < queries; y++) //x: pointer = trees y: pointer to queries
    {
        while (trees [x].first >= todo [y].weight)
        {
            freq.add (trees [x].second, trees [x].first);
            x++;
        }
        output [todo [y].number] = freq.querie (todo [y].from + 1, todo [y].to + 1);
    }
    for (int x = 0; x < queries; x++)
    {
        printf ("%lld\n", output [x]);
    }
    return 0;
}
