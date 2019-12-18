#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

int n;
string str1, str2;

bool check (string str1, string str2)
{
    int x = 0, y = 0;
    while (x < (int) str1.size() && y < (int) str2.size())
    {
        if (str1 [x] != str1 [x + 1])
        {
            if (str1 [x] != str2 [y])
            {
                return false;
            }
            else
            {
                while (str1 [x] == str2 [y] && y < str2.size())
                {
                    y++;
                }
            }
        }
        else
        {
            if (str1 [x] == str2 [y])
            {
                y++;
            }
            else
            {
                return false;
            }
        }
        x++;
    }

    return x == (int)str1.size() && y == (int)str2.size();
}


int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str1 >> str2;
        cout << (check (str1, str2)? "YES": "NO") << endl;
    }
    return 0;
}


