#include <bits/stdc++.h>
using namespace std;
int rows, cols;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> rows >> cols;
    bool graph [rows][cols];
    bool temp [cols];
    unordered_set <string> results;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            cin >> graph [x][y];
        }
    }
    string str = "";
    for (int x = 0; x < cols; x++)
    {
        str += (char)graph [rows - 1][x];
    }
    results.insert (str);
    for (int start = 1; start < rows; start++)
    {
        for (int l = 0; l < cols; l++)
        {
            temp [l] = graph [start - 1][l];
        }
        for (int y = start; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                temp [x] = temp [x]^graph [y][x];
            }
        }
        string str = "";
        for (int x = 0; x < cols; x++)
        {
            str += (char)temp [x];
        }
        results.insert (str);
    }
    cout << results.size() << endl;
    return 0;
}
