#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
string str;
int dp [304][304];
bool rightbracket (char c)
{
    return c == ')' || c == ']';
}
bool leftbracket (char c)
{
    return c == '(' || c == '[';
}
bool match (char c1, char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']');
}
int solve (int left, int right)
{
    if (dp [left][right] != INF)
    {
        return dp [left][right];
    }
    if (left == right)
    {
        return dp [left][right] = 1;
    }
    if (left > right)
    {
        return dp [left][right] = 0;
    }
    int result = INF;
    if (rightbracket(str [right - 1]))
    {
        result = min (result, solve (left, right - 1) + 1);
    }
    if (leftbracket (str [left + 1]))
    {
        result = min (result, solve (left + 1, right) + 1);
    }
    if (match (str [left - 1], str [right - 1]))
    {
        result = min (result, solve (left + 1, right - 1));
    }
    for (int k = left; k < right; k++)
    {
        result = min (result, solve (left, k) + solve (k + 1, right));
    }
    return dp [left][right] = result;
}
int main ()
{
    cin >> str;
    for (int x = 0; x < 304; x++)
    {
        memset (dp, 0x3f, sizeof (dp));
    }
    cout << solve (1, (int)str.size()) << endl;
    return 0;
}



