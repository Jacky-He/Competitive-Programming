#include <bits/stdc++.h>
using namespace std;
int dp [2][2001]; //maximum height triangle;
int consecutive [2001][2001];
int n;
string str;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int sum = 0;
    cin >> n;
    getline (cin, str);
    for (int x = 0; x < n; x++)
    {
        getline (cin, str);
        for (int y = 0; y < n; y++)
        {
            if (str [y] == '.')
            {
                consecutive [x][y] = 0;
            }
            else
            {
                consecutive [x][y] = consecutive [x][y - 1] + 1;
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (consecutive [x][y] != 0)
            {
                dp [1][y] = (dp [0][y - 1] + 1)*2 - 1 < consecutive [x][y]? dp [0][y - 1] + 1:(consecutive [x][y] + 1)/2;
            }
            sum += dp [1][y];
        }
        for (int y = 0; y < n; y++)
        {
            dp [0][y] = dp [1][y];
            dp [1][y] = 0;
        }
    }
    cout << sum << endl;
    return 0;
}