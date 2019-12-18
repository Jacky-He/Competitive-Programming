#include <bits/stdc++.h>
using namespace std;

string str1, str2;
unordered_map <int, int> visited;
int number;

int main ()
{
    cin >> str1 >> str2;
    for (int x = (int)str1.size() - 1; x >= 0; x--)
    {
        number += ((str1 [x] == '1') << ((int)str1.size() - x - 1));
    }
    for (int x = 0; x < (int)str1.size(); x++)
    {
        visited [number^(1 << x)]++;
    }
    number = 0;
    for (int x = (int)str2.size() - 1, multiplier = 1; x >= 0; x--, multiplier *= 3)
    {
        number += (str2 [x] - '0')*multiplier;
    }
    for (int x = (int)str2.size() - 1, multiplier = 1; x >= 0; x--, multiplier *= 3)
    {
        int temp = number;
        temp -= (str2 [x] - '0')*multiplier;
        if (str2 [x] == '0')
        {
            visited [temp + multiplier]++;
            visited [temp + 2*multiplier]++;
        }
        else if (str2 [x] == '1')
        {
            visited [temp]++;
            visited [temp + 2*multiplier]++;
        }
        else if (str2 [x] == '2')
        {
            visited [temp]++;
            visited [temp + multiplier]++;
        }
    }
    for (auto const& each: visited)
    {
        if (each.second == 2)
        {
            printf ("%d\n", each.first);
            break;
        }
    }
    return 0;
}
