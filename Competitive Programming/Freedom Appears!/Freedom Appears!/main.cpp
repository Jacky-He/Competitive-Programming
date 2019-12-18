#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct triplet {
    ll first; ll second; ll third;
};
triplet mt (ll first, ll second, ll third) {triplet t; t.first = first; t.second = second; t.third = third; return t;}

triplet origin;

ll a, b, c;
int n;

map <pair <double, double>, int> cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    origin = mt (a, b, c);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b >> c;
        double d1, d2;
        if (b - origin.second == 0)
        {
            d1 = INFINITY;
        }
        else
        {
            d1 = (a - origin.first)/(b - origin.second);
        }
        if (c - origin.third == 0)
        {
            d2 = INFINITY;
        }
        else
        {
            d2 = (a - origin.first)/(c - origin.third);
        }
        pair <double, double> p = {d1, d2};
        cnt [p]++;
    }
    cout << cnt.size() << endl;
    return 0;
}
