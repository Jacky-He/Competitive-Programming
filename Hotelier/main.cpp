#include <bits/stdc++.h>
using namespace std;

int n;
string str;
bool rooms [10];

int main ()
{
    cin >> n;
    cin >> str;
    for (int x = 0; x < n; x++)
    {
        if (str [x] == 'L')
        {
            int i = 0;
            while(rooms [i])
            {
                i++;
            }
            rooms [i] = true;
        }
        else if (str [x] == 'R')
        {
            int i = 9;
            while (rooms [i])
            {
                i--;
            }
            rooms [i] = true;
        }
        else
        {
            rooms [str[x]-'0'] = false;
        }
    }
    for (int x = 0; x < 10; x++)
    {
        cout << (rooms [x]? 1: 0);
    }
    cout << endl;
    return 0;
}
