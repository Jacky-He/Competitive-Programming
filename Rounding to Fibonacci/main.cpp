#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll fib [1000];
ll input;
int main ()
{
    fib [1] = 1;
    for (int i = 2; i < 1000; i++)
    {
        fib [i] = fib [i - 1] + fib [i - 2];
    }
    for (int x = 0; x < 5; x++)
    {
        cin >> input;
        for (int index = 0; index < 1000; index++)
        {
            if (input == fib [index])
            {
                cout << input << endl;
                break;
            }
            else if (input < fib [index])
            {
                ll dif1 = input - fib [index - 1];
                ll dif2 = fib [index] - input;
                if (dif1 < dif2)
                {
                    cout << fib [index - 1] << endl;
                }
                else
                {
                    cout << fib [index] << endl;
                }
                break;
            }
        }
    }
    return 0;
}
