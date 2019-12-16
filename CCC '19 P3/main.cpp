#include <bits/stdc++.h>
using namespace std;
bool visited [3][3];
int grid [3][3];
string input [3][3];
string str;
int cnt = 0;
int count (int x, int y)
{
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != x)
        {
            if (visited [i][y])
            {
                cnt1++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (i != y)
        {
            if (visited [x][i])
            {
                cnt2++;
            }
        }
    }
    return max (cnt1, cnt2);
}
void fill1 (int x, int y)
{
    pair <int, int> visited1 = {-1, -1};
    pair <int, int> visited2 = {-1, -1};
    bool times = true;
    for (int i = 0; i < 3; i++)
    {
        if (i != x)
        {
            if (visited [i][y] && times)
            {
                times = false;
                visited1 = {i, y};
            }
            else if (visited [i][y])
            {
                visited2 = {i, y};
            }
        }
    }
    if (visited2 == make_pair (-1, -1))
    {
        bool times = true;
        for (int i = 0; i < 3; i++)
        {
            if (i != y)
            {
                if (visited [x][i] && times)
                {
                    times = false;
                    visited1 = {x, i};
                }
                else if (visited [x][i])
                {
                    visited2 = {x, i};
                }
            }
        }
        if (visited2.second - visited1.second == 1)
        {
            if (y < visited1.second)
            {
                grid [x][y] = 2*grid [visited1.first][visited1.second] - grid [visited2.first][visited2.second];
            }
            else
            {
                grid [x][y] = 2*grid [visited2.first][visited2.second] - grid [visited1.first][visited1.second];
            }
        }
        else  //2
        {
            grid [x][y] = (grid [visited1.first][visited1.second] + grid [visited2.first][visited2.second])/2;
        }
        return;
    }
    if (visited2.first - visited1.first == 1)
    {
        if (x < visited1.first)
        {
            grid [x][y] = 2*grid [visited1.first][visited1.second] - grid [visited2.first][visited2.second];
        }
        else
        {
            grid [x][y] = 2*grid [visited2.first][visited2.second] - grid [visited1.first][visited1.second];
        }
    }
    else  //2
    {
        grid [x][y] = (grid [visited1.first][visited1.second] + grid [visited2.first][visited2.second])/2;
    }
}
bool checkCorner ()
{
    return grid [0][0]%2 == 1 || grid [0][2]%2 == 1 || grid [2][0]%2 == 1 || grid [2][2] % 2 == 1;
}
bool isCorner (int x, int y)
{
    return (x == 0 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 0) || (x == 2 && y == 2);
}
void fill3 (int x, int y)
{
    if (isCorner (x, y))
    {
        grid [x][y] = checkCorner ();
        return;
    }
    grid [x][y] = 0;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cin >> str;
            if (str != "X")
            {
                visited [x][y] = true;
                cnt++;
                grid [x][y] = stoi (str);
            }
            input [x][y] = str;
        }
    }

    bool liwi = true;
    while (liwi)
    {
        liwi = false;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (!visited [x][y])
                {
                    int curr = count (x, y);
                    if (curr == 2)
                    {
                        liwi = true;
                        fill1 (x, y);
                        visited [x][y] = true;
                    }
                }
            }
        }
    }
    if (!visited [1][1])
    {
        int temp = count (1, 1);
        if (temp == 2)
        {
            fill1 (1, 1);
        }
        else
        {
            fill3 (1, 1);
        }
        visited [1][1] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [1][0])
    {
        int temp = count (1, 0);
        if (temp == 2)
        {
            fill1 (1, 0);
        }
        else
        {
            fill3 (1, 0);
        }
        visited [1][0] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [1][2])
    {
        int temp = count (1, 2);
        if (temp == 2)
        {
            fill1 (1, 2);
        }
        else
        {
            fill3 (1, 2);
        }
        visited [1][2] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [0][1])
    {
        int temp = count (0, 1);
        if (temp == 2)
        {
            fill1 (0, 1);
        }
        else
        {
            fill3 (0, 1);
        }
        visited [0][1] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [2][1])
    {
        int temp = count (2, 1);
        if (temp == 2)
        {
            fill1 (2, 1);
        }
        else
        {
            fill3 (2, 1);
        }
        visited [2][1] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [0][0])
    {
        int temp = count (0, 0);
        if (temp == 2)
        {
            fill1 (0, 0);
        }
        else
        {
            fill3 (0, 0);
        }
        visited [0][0] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [0][2])
    {
        int temp = count (0, 2);
        if (temp == 2)
        {
            fill1 (0, 2);
        }
        else
        {
            fill3 (0, 2);
        }
        visited [0][2] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [2][0])
    {
        int temp = count (2, 0);
        if (temp == 2)
        {
            fill1 (2, 0);
        }
        else
        {
            fill3 (2, 0);
        }
        visited [2][0] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if (!visited [2][2])
    {
        int temp = count (2, 2);
        if (temp == 2)
        {
            fill1 (2, 2);
        }
        else
        {
            fill3 (2, 2);
        }
        visited [2][2] = true;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!visited [x][y])
                    {
                        int curr = count (x, y);
                        if (curr == 2)
                        {
                            flag = true;
                            fill1 (x, y);
                            visited [x][y] = true;
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (y < 2)
            {
                cout << grid [x][y] << " ";
            }
            else
            {
                cout << grid [x][y] << endl;
            }
        }
    }
    return 0;
}

/*
8 9 10
16 X 20
 24 X 30


 14 X X
 X X 18
 X 16 X
*/