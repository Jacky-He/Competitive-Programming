#include <bits/stdc++.h>

using namespace std;
string good = "abcdefghijklmnopqrstuvwxyz";
string bad;
int* dp1 = new int [55];
int* dp2 = new int [55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> bad;
    for (int x = 0; x < bad.size(); x++)
    {
        for (int y = 0; y < good.size(); y++)
        {
            dp2 [y + 1] = bad [x] == good [y]? dp1 [y] + 1 : max (dp2 [y], dp1 [y + 1]);
        }
        int* temp = dp1;
        dp1 = dp2;
        dp2 = temp;
    }
    cout << 26 - dp1 [26] << endl;
    return 0;
}