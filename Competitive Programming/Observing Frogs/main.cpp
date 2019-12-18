#include <bits/stdc++.h>
using namespace std;
int main ()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int sum = 0;
    if (n % 2 == 0)
    {
        sum = ((((n - 1) + 1)*((n - 1)/2 + 1))/2)*2;
    }
    else
    {
        sum = ((((n - 1) + 0)*((n - 1)/2 + 1))/2)*2;
    }
    cout << sum << endl;
    return 0;
}
