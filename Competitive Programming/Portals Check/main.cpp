#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;

string o, f, t;
unordered_map <string, string> parent;

void Union (string s1, string s2)
{
    parent [s1] = s2;
}
string Find (string child)
{
    if (child == parent [child])
    {
        return child;
    }
    return parent [child] = Find (parent [child]);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie (nullptr);
    for (int x = 0; x < 5; x++)
    {
        cin >> n;
        for (int y = 0; y < n; y++)
        {
            cin >> o >> f >> t;
            if (parent [f] == "")
            {
                parent [f] = f;
            }
            if (parent [t] == "")
            {
                parent [t] = t;
            }
            if (o == "p")
            {
                Union (Find (f), Find (t));
            }
            else if (o == "q")
            {
                if (Find (f) == Find (t))
                {
                    cout << "connected\n";
                }
                else
                {
                    cout << "not connected\n";
                }
            }
        }
        parent.clear();
    }
    return 0;
}











