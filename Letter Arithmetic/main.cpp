#include <bits/stdc++.h>
typedef unsigned long long int ull;
typedef __int128_t bigint;
using namespace std;
int testcases;
string num1, num2, num3;
char result [21];
string n1, n2, n3;
int toInt (char c) {return c - 'A';}
char toChar (int i) {return char(i + 'A');}
bool inThem [26];
bool cantbeZero [26];
int numbers [26];
int chosen [10];
int last = 0;
void init ()
{
    memset (inThem, false, sizeof (inThem));
    memset (cantbeZero, false, sizeof (cantbeZero));
    memset (chosen, -1, sizeof (chosen));
    for (int x = 0; x < (int) num1.size(); x++)
    {
        inThem [toInt (num1 [x])] = true;
    }
    for (int x = 0; x < (int) num2.size(); x++)
    {
        inThem [toInt (num2 [x])] = true;
    }
    for (int x = 0; x < (int) num3.size(); x++)
    {
        inThem [toInt (num3 [x])] = true;
    }
    if (num1.size() > 1)
    {
        cantbeZero [toInt(num1[0])] = true;
    }
    if (num2.size() > 1)
    {
        cantbeZero [toInt(num2[0])] = true;
    }
    if (num3.size() > 1)
    {
        cantbeZero [toInt(num3[0])] = true;
    }
    for (int x = 0; x < 26; x++)
    {
        if (inThem [x])
        {
            last = x;
        }
    }
}
bigint toInteger (string str)
{
    bigint result = 0;
    bigint multiplier = 1;
    for (int x = (int)str.size() - 1; x >= 0; x--)
    {
        result += numbers [toInt(str [x])]*multiplier;
        multiplier *= 10;
    }
    return result;
}
bool check ()
{
    bigint n1 = toInteger (num1);
    bigint n2 = toInteger (num2);
    bigint n3 = toInteger (num3);
    if (n1 + n2 == n3)
    {
        bigint multiplier = 1;
        for (int x = 0; x < num1.size() - 1; x++)
        {
            multiplier *= 10;
        }
        for (int x = (int)num1.size() - 1; x >= 0; x--)
        {
            cout << (int)(n1/multiplier);
            n1 %= multiplier;
            multiplier /= 10;
        }
        cout << endl;
        multiplier = 1;
        for (int x = 0; x < num2.size() - 1; x++)
        {
            multiplier *= 10;
        }
        for (int x = (int)num2.size() - 1; x >= 0; x--)
        {
            cout << (int)(n2/multiplier);
            n2 %= multiplier;
            multiplier /= 10;
        }
        cout << endl;
        multiplier = 1;
        for (int x = 0; x < num3.size() - 1; x++)
        {
            multiplier *= 10;
        }
        for (int x = (int)num3.size() - 1; x >= 0; x--)
        {
            cout << (int)(n3/multiplier);
            n3 %= multiplier;
            multiplier /= 10;
        }
        cout << endl;
        return true;
    }
    return false;
}

bool solve (int n)
{
    if (n == last)
    {
        for (int x = (cantbeZero [n]? 1:0) ; x < 10; x++)
        {
            if (chosen [x] == -1)
            {
                chosen [x] = n;
                numbers [n] = x;
                if (check ())
                {
                    return true;
                }
                chosen [x] = -1;
            }
        }
        return false;
    }
    if (inThem [n])
    {
        for (int x = (cantbeZero [n]? 1:0) ; x < 10; x++)
        {
            if (chosen [x] == -1)
            {
                chosen [x] = n;
                numbers [n] = x;
                bool temp = solve (n + 1);
                chosen [x] = -1;
                if (temp)
                {
                    return true;
                }
            }
        }
        return false;
    }
    return solve (n + 1);
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> testcases;
    while (testcases--)
    {
        cin >> num1 >> num2 >> num3;
        init ();
        solve (0);
    }
    return 0;
}