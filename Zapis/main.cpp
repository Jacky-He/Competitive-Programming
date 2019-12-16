#include <bits/stdc++.h>
#define MOD 100000000
using namespace std;
typedef long long int ll;
int n;
string str;
ll dp [202][202];
bool leftbracket (char c)
{
    return c == '(' || c == '[' || c == '{' || c == '?';
}
bool rightbracket (char c)
{
    return c == ')' || c == ']' || c == '}' || c == '?';
}
bool isaset (char c1, char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || c1 == '?' || c2 == '?';
}
int compare (char c1, char c2)
{
    if (c1 == '?' && c2 == '?')
    {
        return 3;
    }
    if (c1 != '?' && c2 != '?')
    {
        if (isaset (c1, c2))
        {
            return 1;
        }
        return 0;
    }
    if (leftbracket (c2) || rightbracket (c1))
    {
        return 0;
    }
    return 1;
}
ll solve (int left, int right)
{
    if (dp [left][right] != -1)
    {
        return dp [left][right];
    }
    if (left > right)
    {
        return dp [left][right] = 1;
    }
    ll result = 0;
    for (int k = left + 1; k <= right; k++)
    {
        if (leftbracket (str [left - 1]) && rightbracket (str [k - 1]) && isaset (str [left - 1], str [k - 1]))
        {
            if (str [left - 1] == '?' && str [k - 1] == '?')
            {
                result = (result + 3*solve (left + 1, k - 1)%MOD*solve(k + 1, right)%MOD)%MOD;
            }
            else
            {
                result = (result + solve (left + 1, k - 1)%MOD*solve (k + 1, right)%MOD)%MOD;
            }
        }
    }
    return dp [left][right] = result;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie (nullptr);
    cin >> n;
    getline (cin, str);
    getline (cin, str);
    for (int x = 0; x < 202; x++)
    {
        memset (dp, -1, sizeof (dp));
    }
    ll output = solve (1, n);
    string temp = to_string(output);
    if (temp.length() > 5)
    {
        cout << temp.substr(temp.length() - 5, 5) << endl;
        return 0;
    }
    cout << temp << endl;
    return 0;
}

/*
10
(?([?)]?}?

16
???[???????]????


*/
