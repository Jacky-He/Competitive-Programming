#include <bits/stdc++.h>
using namespace std;
string str, result;
int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> str;
    bool yes = true;
    for (int x = 0; x < (int) str.size(); x++)
    {
        if (str [x] == '0' && yes)
        {
            yes = false;
        }
        else
        {
            result += str [x];
        }
    }
    cout << (yes? result.substr (0, result.size() - 1) : result) << endl;
    return 0;
}