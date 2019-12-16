#include <bits/stdc++.h>
using namespace std;
string str;
string str1 = "pusheen";
int main ()
{
    int counter = 0;
    cin >> str;
    for (int x = 0; x < str.size(); x++)
    {
        if (str [x] == str1[x])
        {
            counter++;
        }
    }
    cout << 7 - counter << endl;
    return 0;
}
