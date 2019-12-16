#include <bits/stdc++.h>
using namespace std;
typedef __uint128_t bigint;

bigint dp [205];


bigint fib (int num)
{
    if (dp [num] != 0)
    {
        return dp [num];
    }
    if (num == 1 || num == 2)
    {
        return dp [num] = 1;
    }
    return dp [num] = fib (num - 1) + fib (num - 2);
}

int num;
int main ()
{
    cin >> num;
    while (num != 0)
    {
        string str;
        bigint res = fib (num);
        while (res != 0)
        {
            str += res%10 + '0';
            res /= 10;
        }
        for (int x = (int)str.size() - 1; x >= 0; x--)
        {
            cout << str [x];
        }
        cout << endl;
        cin >> num;
    }
    return 0;
}
