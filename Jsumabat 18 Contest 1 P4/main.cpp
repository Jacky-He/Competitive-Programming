#include <bits/stdc++.h>
using namespace std;
string input;
int n;
bool sieve [10000];
void init ()
{
    sieve [0] = 1;
    sieve [1] = 1;
    for (int x = 2; x < 10000; x++)
    {
        if (!sieve [x])
        {
            for (int j = 2*x; j < 10000; j += x)
            {
                sieve [j] = 1;
            }
        }
    }
}
bool prime (int i) {return !sieve [i];}
bool primeIn (string str)
{
    int sum = 0;
    for (int index = 0; index < (int)str.size(); index++)
    {
        sum += str [index] - '0';
    }
    return prime (sum);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    getline (cin, input);
    init ();
    for (int x = 0; x < n; x++)
    {
        getline (cin, input);
        if (prime ((int)input.size()) && primeIn (input))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
