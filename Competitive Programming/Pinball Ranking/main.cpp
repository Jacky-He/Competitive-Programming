#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct FenwickTree
{
    ll* pt;
    int size;
    ll lowbit (ll n) {return n& (-n);}
    void add (int index, int delta)
    {
        while (index <= size)
        {
            pt [index] += delta;
            index += lowbit(index);
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
    void iniFenwickTree (int size)
    {
        pt = new ll [size + 1];
        this -> size = size;
        for (int x = 0; x <= size; x++)
        {
            pt [x] = 0;
        }
    }
};
bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return (p1.first > p2.first) || (p1.first == p2.first && p1.second < p2.second);
}
int turns, score;
ll rankings [100001];
int main ()
{
    scanf ("%d", &turns);
    pair <int, int> plays [turns];
    for (int x = 1; x <= turns; x++)
    {
        scanf ("%d", &score);
        plays [x - 1] = {score, x};
    }
    sort (plays, plays + turns, cmp);
    FenwickTree freq;
    freq.iniFenwickTree (turns + 1);
    ll sum = 0;
    int temp = 0;
    for (int x = 0; x < turns; x++)
    {
        freq.add (plays [x].second, 1);
        if (x > 0 && plays [x].first == plays [x - 1].first)
        {
            rankings [x] = freq.querie (plays [x].second - 1) - (x - temp) + 1;
        }
        else
        {
            temp = x;
            rankings [x] = freq.querie (plays [x].second - 1) + 1;
        }
        sum += rankings [x];
    }
    printf ("%.2f\n", double(sum)/turns);
    set <int> s;
    return 0;
}

