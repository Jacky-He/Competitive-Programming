#include <bits/stdc++.h>
using namespace std;
int h;
int main ()
{
    cin >> h;
    for (int x = 0; x < h; x++)
    {
        for (int y = 1; y <= h*2; y++)
        {
            int hello = h - abs (h - (1 + x*2));
            if (y <= hello || y > h*2 - (hello))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
