#include <bits/stdc++.h>
using namespace std;

deque <char> chars;
int n, l, k;
string line;
string arr [1004];

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> l >> k;
    cin >> line;
    for (int x = 0; x < n*l; x++)
    {
        chars.push_back (line [x]);
    }
    sort (chars.begin(), chars.end());
    string kth = "";
    

    return 0;
}
