#include <bits/stdc++.h>
using namespace std;
int queries;
int from, to;
string str;
int dp [100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> str;
    for (int x = 0; x < str.size() - 1; x++)
    {
        dp [x + 1] = dp [x] + (str [x] == str [x + 1]);
    }
    cin >> queries;
    for (int x = 0; x < queries; x++)
    {
        cin >> from >> to;
        cout << dp [to - 1] - dp [from - 1] << endl;
    }
    return 0;
}