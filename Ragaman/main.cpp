#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int a1 [256];
int a2 [256];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str1 >> str2;
    if (str1.size() != str2.size())
    {
        cout << "N" << endl;
        return 0;
    }
    for (int x = 0; x < str1.size(); x++)
    {
        a1 [str1[x]]++;
        a2 [str2[x]]++;
    }
    for (int x = 'a'; x <= 'z'; x++)
    {
        if (a1 [x] < a2 [x])
        {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "A" << endl;
    return 0;
}
