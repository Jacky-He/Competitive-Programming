#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string str;
int main ()
{
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        if (str == "cats")
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    if (c1 == c2)
    {
        cout << "equal" << endl;
    }
    else if (c1 < c2)
    {
        cout << "dogs" << endl;
    }
    else
    {
        cout << "cats" << endl;
    }
    return 0;
}
