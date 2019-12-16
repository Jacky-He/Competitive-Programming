#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct FenwickTree
{
    ll* pt; int size;
    ll lowbit (ll n) {return n&(-n);}
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
struct querie
{
    int from, to, weight, number;
};
bool cmp (pair <int, int> p1, pair <int, int> p2) {return p1.first > p2.first;}
bool cmpq (querie q1, querie q2) {return q1.weight > q2.weight;}
querie makeq (int from, int to, int weight, int number) {querie some; some.from = from; some.to = to; some.weight = weight; some.number = number; return some;}
int n, q, num;
int a, b, c;
vector <pair <int, int>> nums;
vector <querie> queries;
ll psa [200001];
ll output [200001];
int main ()
{
    scanf ("%d%d", &n, &q);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        psa [x + 1] = psa [x] + num;
        nums.push_back ({num, x + 1});
    }
    nums.push_back ({0, 0});
    sort (nums.begin(), nums.end(), cmp);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d%d", &a, &b, &c);
        queries.push_back (makeq (a, b, c, x));
    }
    sort (queries.begin(), queries.end(), cmpq);
    FenwickTree freq;
    freq.init (n);
    for (int x = 0, y = 0; y < q; y++) //x: pointer to num, y: pointer to queries
    {
        while (nums [x].first >= queries [y].weight)
        {
            freq.add (nums [x].second, nums [x].first);
            x++;
        }
        ll numgreater = freq.querie (queries [y].from, queries [y].to);
        ll numsmaller = psa [queries [y].to] - psa [queries [y].from - 1] - numgreater;
        output [queries [y].number] = numgreater - numsmaller;
    }
    for (int x = 0; x < q; x++)
    {
        printf ("%lld\n", output [x]);
    }
    return 0;
}
