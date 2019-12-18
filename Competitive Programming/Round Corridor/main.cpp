#include <bits/stdc++.h>
using namespace std;

int n, k;
bool white [2003][2003];
int sumcols [2003][2003];
int sumrows [2003][2003];
string line;
int numwhitelines = 0;

int rowspsa [2003][2003];
int colspsa [2003][2003];

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int x = 0; x < n; x++)
    {
        cin >> line;
        for (int y = 0; y < n; y++)
        {
            white [x + 1][y + 1] = line [y] == 'W';
        }
    }
    
    
    for(int row = 1; row <= n; row++)
    {
        int cnt = 0;
        int cnt2 = 0;
        for (int col = 1; col <= n; col++)
        {
            cnt += white [row][col];
            cnt2 += white [col][row];
        }
        if (cnt == n)
        {
            numwhitelines++;
        }
        if (cnt2 == n)
        {
            numwhitelines++;
        }
    }
    
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            rowspsa [row][col] = rowspsa[row][col - 1] + white [row][col];
        }
    }
    for (int col = 1; col <= n; col++)
    {
        for (int row = 1; row <= n; row++)
        {
            colspsa [col][row] = colspsa [col][row - 1] + white [row][col];
        }
    }
    
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (col + k - 1 <= n)
            {
                int totalblack = n - rowspsa[row][n];
                int hereblack = k - (rowspsa [row][col + k - 1] - rowspsa [row][col - 1]);
                if (totalblack == hereblack && totalblack != 0)
                {
                    sumrows [col][row] = sumrows [col][row - 1] + 1;
                }
                else
                {
                    sumrows [col][row] = sumrows [col][row - 1];
                }
            }
        }
    }
    
    for (int col = 1; col <= n; col++)
    {
        for (int row = 1; row <= n; row++)
        {
            if (row + k - 1 <= n)
            {
                int totalblack = n - colspsa [col][n];
                int hereblack = k - (colspsa [col][row + k - 1] - colspsa [col][row - 1]);
                if (totalblack == hereblack && totalblack != 0)
                {
                    sumcols [row][col] = sumcols [row][col - 1] + 1;
                }
                else
                {
                    sumcols [row][col] = sumcols [row][col - 1];
                }
            }
        }
    }
    
    int add = 0;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        for (int j = 1; j + k - 1 <= n; j++)
        {
            int addd = sumcols [i][j + k - 1] - sumcols [i][j - 1] + sumrows [j][i + k - 1] - sumrows [j][i - 1];
            add = max (add, addd);
        }
    }
    cout << numwhitelines + add << endl;
    return 0;
}
