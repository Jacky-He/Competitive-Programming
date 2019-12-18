#include <bits/stdc++.h>
using namespace std;
string line;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline (cin, line);
    if (line [0] - 'a' >= 0 && line [0] - 'a' <= 25)
    {
        line [0] = line [0] - 'a' + 'A';
    }
    for (int x = 1; x < (int)line.size(); x++)
    {
        if (line [x] == '.' && x + 2 < (int)line.size())
        {
            if (line [x + 2] - 'a' >= 0 && line [x + 2] - 'a' <= 25)
            {
                line [x + 2] = line [x + 2] - 'a' + 'A';
            }
        }
    }
    cout << line << endl;
    return 0;
}
