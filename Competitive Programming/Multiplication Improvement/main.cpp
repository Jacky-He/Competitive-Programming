#include <bits/stdc++.h>
using namespace std;
string str;
vector <int> numbers;
int main ()
{
    cin >> str;
    for (int x = 0; x < str.size(); x++)
    {
        if (str [x] - '0' >= 0 && str [x] - '0' <= 9)
        {
            numbers.push_back (str [x] - '0');
        }
    }
    sort (numbers.begin(), numbers.end());
    long long int result = 1;
    for (int x = 0; x < numbers.size(); x++)
    {
        if (x < numbers.size() - 1)
        {
            cout << numbers [x] << "x";
        }
        else
        {
            cout << numbers [x] << endl;
        }
        result *= numbers [x];
    }
    cout << result << endl;
    return 0;
}


