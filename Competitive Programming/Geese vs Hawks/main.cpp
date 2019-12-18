#include <bits/stdc++.h>
using namespace std;
int n;
string str1, str2;
pair <bool, int> arr1 [1001];
pair <bool, int> arr2 [1001];
int dp [1001][1001];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    cin >> str1;
    for (int x = 1; x <= n; x++)
    {
        arr2 [x].first = (str1 [x - 1] == 'W');
        cin >> arr2 [x].second;
    }
    cin >> str2;
    for (int x = 1; x <= n; x++)
    {
        arr1 [x].first = (str2 [x - 1] == 'W');
        cin >> arr1 [x].second;
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if ((arr1 [x].first && !arr2 [y].first && arr1 [x].second > arr2 [y].second) || (!arr1 [x].first && arr2 [y].first && arr1 [x].second < arr2 [y].second))
            {
                dp [x][y] = max(max(dp [x - 1][y - 1] + arr1 [x].second + arr2 [y].second, dp [x - 1][y]), dp [x][y - 1]);
            }
            else
            {
                dp [x][y] = max (dp [x - 1][y], dp [x][y - 1]);
            }
        }
    }
    cout << dp [n][n] << endl;
    return 0;
}