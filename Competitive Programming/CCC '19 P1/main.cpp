#include <bits/stdc++.h>
using namespace std;
string line;
int grid [2][2] = {{1, 2}, {3, 4}};
void horizontal ()
{
    int n1, n2, n3, n4;
    n1 = grid [0][0];
    n2 = grid [0][1];
    n3 = grid [1][0];
    n4 = grid [1][1];
    grid [0][0] = n3;
    grid [0][1] = n4;
    grid [1][0] = n1;
    grid [1][1] = n2;
}
void vertical ()
{
    int n1, n2, n3, n4;
    n1 = grid [0][0];
    n2 = grid [0][1];
    n3 = grid [1][0];
    n4 = grid [1][1];
    grid [0][0] = n2;
    grid [0][1] = n1;
    grid [1][0] = n4;
    grid [1][1] = n3;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie (nullptr);
    cin >> line;
    for (int x = 0; x < (int) line.size(); x++)
    {
        if (line [x] == 'H')
        {
            horizontal();
        }
        else
        {
            vertical();
        }
    }
    cout << grid [0][0] << " " << grid [0][1] << endl;
    cout << grid [1][0] << " " << grid [1][1] << endl;
    return 0;
}