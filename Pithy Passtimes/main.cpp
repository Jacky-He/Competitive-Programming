#include <bits/stdc++.h>
using namespace std;
int main ()
{
    string str;
    int n;
    int counter = 0;
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        if (str.size() <= 10)
        {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
