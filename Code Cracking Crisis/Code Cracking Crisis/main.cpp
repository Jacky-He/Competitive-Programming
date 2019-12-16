#include <bits/stdc++.h>
using namespace std;
string arr [10];
string code;
string line;
string output;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    for (int x = 0; x < 10; x++)
    {
        cin >> line;
        arr [x] = line;
    }
    cin >> code;
    output = code [0];
    for (int x = 1; x < (int) code.length(); x++)
    {
        int temp = output [x - 1] - '0';
        for (int y = 0; y < 10; y++)
        {
            if (arr [temp][y] == code [x])
            {
                output += to_string(y);
                break;
            }
        }
    }
    cout << output << endl;
    return 0;
    
}


