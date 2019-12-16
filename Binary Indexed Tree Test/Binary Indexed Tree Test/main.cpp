#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct FenwickTree
{
    ll* pt;
    int size;
    ll lowbit (ll n)
    {
        return n&(-n);
    }
    void add (int index, int delta)
    {
        while (index <= size)
        {
            *(pt+index) += delta;
            index += lowbit (index);
        }
    }
    ll querie (int index)
    {
        ll sum = 0;
        while (index > 0)
        {
            sum += *(pt+index);
            index -= lowbit (index);
        }
        return sum;
    }
    void iniFenwickTree (int size, int elements [])
    {
        pt = new ll [size + 1];
        for (int x = 0; x <= size; x++)
        {
            pt [x] = 0;
        }
        this -> size = size;
        for (int x = 1; x <= size; x++)
        {
            add (x, elements [x - 1]);
        }
    }
};
int n, m;
int frequencies [100001];

int main ()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie (NULL);
    cin >> n >> m;*/
    scanf ("%d %d\n", &n, &m);
    int arr [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d ", &arr [x]);
        //cin >> arr [x];
        frequencies [arr [x] - 1]++;
    }
    FenwickTree tree, freq;
    tree.iniFenwickTree (n, arr);
    freq.iniFenwickTree (100001, frequencies);
    char temp;
    for (int x = 0; x < m; x++)
    {
        scanf ("\n%c", &temp);
        //cin >> temp;
        if (temp == 'C')
        {
            int y, v;
            scanf ("%d%d", &y, &v);
            //cin >> y >> v;
            int delta = v - arr [y - 1];
            freq.add (arr[y - 1], -1);
            freq.add (v, 1);
            arr [y - 1] = v;
            tree.add (y, delta);
        }
        else if (temp == 'S')
        {
            int l, r;
            scanf ("%d%d", &l, &r);
            //cin >> l >> r;
            printf ("%lld\n", tree.querie (r) - tree.querie (l - 1));
            //cout << tree.querie (r) - tree.querie (l - 1) << endl;
        }
        else if (temp == 'Q')
        {
            int s;
            scanf ("%d", &s);
            //cin >> s;
            printf ("%lld\n", freq.querie (s));
            //cout << freq.querie (s) << endl;
        }
    }
    return 0;
}

