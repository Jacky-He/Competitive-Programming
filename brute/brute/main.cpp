#include <bits/stdc++.h>
#define INFL 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;
typedef long long int ll;

int testcases;
vector <string> outputs;

int n, q, num, a, b;
string op;
ll elements [100005];

ll query (int from, int to)
{
    ll prev = 0;
    ll maxi = -INFL;
    for (int x = from; x <= to; x++)
    {
        prev = max (elements [x], elements [x] + prev);
        maxi = max (maxi, prev);
    }
    return maxi;
}


string solve ()
{
    string res = "";
    cin >> n >> q;
    for (int x = 0; x < n; x++)
    {
        cin >> num;
        elements [x] = num;
    }
    for (int x = 0; x < q; x++)
    {
        cin >> op >> a >> b;
        if (op == "S")
        {
            elements [a - 1] = b;
        }
        else if (op == "Q")
        {
            res += to_string(query (a - 1, (int)b - 1)) + endl;
        }
    }
    res += "___";
    res += endl;
    return res;
}

int main ()
{
    string dir = "/Users/jackyhe/Desktop/C++/DMOJ";
    freopen ((dir + "/testcases.txt").c_str(), "r", stdin);
    cin >> testcases;
    outputs.push_back (to_string(testcases) + endl);
    for (int x = 0; x < testcases; x++)
    {
        outputs.push_back ("Case: " + to_string(x + 1) + endl + solve());
    }
    fclose (stdin);
    freopen ((dir + "/brute.txt").c_str(), "w", stdout);
    for (string each: outputs)
    {
        cout << each;
    }
    fclose (stdout);
    return 0;
}
