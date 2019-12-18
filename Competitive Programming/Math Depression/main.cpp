#include <cstdlib>
#include <cstdio>
#include <iostream>
#define MOD 1000000007
typedef long long int ll;

using namespace std;

int n;
int main ()
{
    cin >> n;
    int numThrees = n/3;
    ll result = 1;
    if (n % 3 == 0)
    {
        for (int x = 0; x < numThrees; x++)
        {
            result = (result * 3) % MOD;
        }
    }
    else if (n % 3 == 1)
    {
        for (int x = 0; x < numThrees - 1; x++)
        {
            result = (result * 3) % MOD;
        }
        result = (result * 4) % MOD;
    }
    else if (n % 3== 2)
    {
        for (int x = 0; x < numThrees; x++)
        {
            result = (result * 3) % MOD;
        }
        result = (result * 2) % MOD;
    }
    cout << result << endl;
}
