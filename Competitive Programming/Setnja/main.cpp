#include <bits/stdc++.h>
typedef unsigned long long int ull;
using namespace std;
int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    string input;
    cin >> input;
    ull value = 1;
    ull numbranches = 1;
    for (int x = 0; x < (int)input.size(); x++)
    {
        if (input [x] == 'L')
        {
            value *= 2;
        }
        else if (input [x] == 'R')
        {
            value = value*2 + numbranches;
        }
        else if (input [x] == '*')
        {
            value = value + value*2 + value*2 + numbranches;
            numbranches *= 3;
        }
    }
    printf ("%lld\n", value);
}
