#include <iostream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
using namespace std;
int n;
ll numbers [11][7];
string str;
bool picked [11];
ll value [11];
bool notzero [11];
ll minimum = INF;
ll evaluate ()
{
    ll multiplier = 1;
    ll result = 0;
    for (int x = 6; x >= 0; x--)
    {
        for (int y = 0; y < 11; y++)
        {
            result += value [y]*numbers [y][x]*multiplier;
        }
        multiplier *= 10;
    }
    return result;
}
void solve (int n)
{
    if (n == 10)
    {
        minimum = min (minimum, evaluate ());
        return;
    }
    for (int x = notzero [n]? 1: 0; x < 10; x++)
    {
        if (!picked [x])
        {
            picked [x] = true;
            value [n] = x;
            solve (n + 1);
            picked [x] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie (nullptr);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        for (int y = (int)str.length() - 1, i = 6; y >= 0; y--, i--)
        {
            numbers [str [y] - 'a'][i]++;
            if (y == 0)
            {
                notzero [str [y] - 'a'] = true;
            }
        }
    }
    solve (0);
    cout << minimum << endl;
    return 0;
}