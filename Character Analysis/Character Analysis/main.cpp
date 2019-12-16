#include <bits/stdc++.h>
using namespace std;
string str1;
string str2;
int main ()
{
    cin >> str1 >> str2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    bool d = true;
    for (int i = 0; i < (int) str1.size(); i++)
    {
        if (str1 [i] != str2[i])
        {
            cout << str1 [i] << endl;
            d = false;
            break;
        }
    }
    if (d)
    {
        cout << str1 [(int)str1.size() - 1] << endl;
    }
    return 0;
}
