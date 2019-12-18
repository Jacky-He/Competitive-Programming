#include <bits/stdc++.h>
using namespace std;
int n;
int counter;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie(NULL);
    cin >> n;
    char student [n];
    char teacher [n];
    for (int x = 0; x < n; x++)
    {
        cin >> student [x];
    }
    for (int x = 0; x < n; x++)
    {
        cin >> teacher [x];
        if (student [x] == teacher [x])
        {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
