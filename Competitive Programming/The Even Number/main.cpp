#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll n;
ll nex;
ll base3XOR (ll num1, ll num2)
{
    ll result = 0;
    ll multiplier = 1;
    while (num1 > 0 || num2 > 0)
    {
        result += (num1 + num2)%3*multiplier;
        num1 /= 3;
        num2 /= 3;
        multiplier *= 3;;
    }
    return result;
}
int main () //I'm too dumb
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie (NULL);
    cin >> n;
    ll number = 0;
    for (ll x = 0; x < n; x++)
    {
        cin >> nex;
        number = base3XOR (number, nex);
    }
    cout << base3XOR (number, number) << endl;
    return 0;
}
