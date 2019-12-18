#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    string line;
    getline(cin,line);
    int charArray [26][line.size()];
    for (int index = 0; index < 26; index++)
    {
        fill_n (charArray [index], line.size(), 0);
    }
    for (unsigned int index = 0; index < line.size(); index++)
    {
        if (line.at(index) != ' ')
        {
            charArray [(int)line.at(index) - 97][index] = 1;
        }
    }
    for (int index = 0; index < 26; index++)
    {
        for (unsigned int index2 = 1; index2 < line.size(); index2++)
        {
            charArray [index][index2] += charArray [index][index2 - 1];
        }
    }
    int n;
    cin >> n;
    for (int count = 0; count < n; count++)
    {
        int i, j;
        char k;
        cin >> i;
        cin >> j;
        cin >> k;
        if (i == 1)
        {
            cout << charArray [(int)k - 97][j - 1] << endl;
        }
        else
        {
           cout << charArray [(int)k - 97][j - 1] - charArray [(int)k - 97][i - 2] << endl;
        }
    }
    return 0;
}
