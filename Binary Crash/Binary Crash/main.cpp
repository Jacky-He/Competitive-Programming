#include <bits/stdc++.h>
using namespace std;
string str;
int main ()
{
    cin >> str;
    int cntzero = 0;
    int cntone = 0;
    for (int x = 0; x < str.length(); x++)
    {
        if (str [x] == '0')
        {
            cntzero++;
        }
        else
        {
            cntone++;
        }
    }
    printf ("%d\n", min (cntzero, cntone)*2);
    return 0;
}
