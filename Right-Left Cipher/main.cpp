#include <bits/stdc++.h>
using namespace std;
string line;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline (cin, line);
    string result = "";
    string actual = "";
    bool righ = 0;
    if (line.size()%2 == 0)
    {
        righ = 1;
        int right = (int)line.size() - 1;
        int left = 0;
        while (result.size() != line.size())
        {
            if (righ)
            {
                result += line [right];
                right--;
            }
            else
            {
                result += line [left];
                left++;
            }
            righ = !righ;
        }
    }
    else
    {
        righ = 0;
        int right = (int)line.size() - 1;
        int left = 0;
        while (result.size() != line.size())
        {
            if (righ)
            {
                result += line [right];
                right--;
            }
            else
            {
                result += line [left];
                left++;
            }
            righ = !righ;
        }
    }
    for (int y = (int)line.size() - 1; y>=0; y--)
    {
        actual += result [y];
    }
    cout << actual << endl;
    return 0;
}
