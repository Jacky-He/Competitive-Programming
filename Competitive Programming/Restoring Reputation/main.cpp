#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int D, I, R;
int dp [1001][1001];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> D >> I >> R >> str1 >> str2;
    for (int x = 1; x <= (int) str2.length(); x++)
    {
        dp [0][x] = dp [0][x - 1] + I;
    }
    for (int x = 1; x <= (int) str1.length(); x++)
    {
        dp [x][0] = dp [x - 1][0] + D;
    }
    for (int x = 1; x <= (int) str1.length(); x++)
    {
        for (int y = 1; y <= (int) str2.length(); y++)
        {
            if (str1 [x - 1] != str2 [y - 1])
            {
                dp [x][y] = min(min(min (dp [x - 1][y - 1] + R, dp [x - 1][y - 1] + D + I), dp [x][y - 1] + I), dp [x - 1][y] + D);
            }
            else
            {
                dp [x][y] = min(min (dp [x - 1][y - 1], dp [x][y - 1] + I), dp [x - 1][y] + D);
            }
        }
    }
    cout << dp [(int)str1.length()][(int)str2.length()] << endl;
    return 0;
}