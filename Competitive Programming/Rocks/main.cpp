#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;

int c;
string operation;
string a, b;

ll fenwick [10004];
unordered_map <string, int> lookup;

ll lowbit (ll num)
{
    return num&(-num);
}

void add (int index, ll delta)
{
    while (index <= 10004)
    {
        fenwick [index] += delta;
        index += lowbit (index);
    }
}

ll sum (int index)
{
    ll sum = 0;
    while (index > 0)
    {
        sum += fenwick [index];
        index -= lowbit (index);
    }
    return sum;
}

ll value (string str)
{
    ll sum = 0;
    for (int x = 0; x < (int)str.size(); x++)
    {
        sum += str [x] - 'a' + 1;
    }
    return sum;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> c;
    for (int x = 0; x < c; x++)
    {
        cin >> operation;
        if (operation == "A")
        {
            cin >> a;
            int numele = (int)lookup.size() + 1;
            if (lookup.count(a))
            {
                cout << "Can't add " + a << endl;
            }
            else
            {
                lookup [a] = numele;
                add(numele, value (a));
            }
        }
        else if (operation == "S")
        {
            cin >> a >> b;
            int pos1 = lookup [a];
            int pos2 = lookup [b];
            ll val1 = value (a);
            ll val2 = value (b);
            lookup [a] = pos2;
            lookup [b] = pos1;
            add (pos1, val2 - val1);
            add (pos2, val1 - val2);
        }
        else if (operation == "M")
        {
            cin >> a >> b;
            int pos1 = lookup [a];
            int pos2 = lookup [b];
            cout << sum (max (pos1, pos2)) - sum (min (pos1, pos2) - 1) << endl;
        }
        else if (operation == "R")
        {
            cin >> a >> b;
            int pos1 = lookup [a];
            ll val1 = value (a);
            ll val2 = value (b);
            add (pos1, val2 - val1);
            lookup.erase(a);
            lookup [b] = pos1;
        }
        else if (operation == "N")
        {
            cout << lookup.size() << endl;
        }
    }
    return 0;
}

