#include <bits/stdc++.h>
using namespace std;
struct CPair
{
    int r;
    int c;
    CPair (int x, int y)
    {
        r = x;
        c = y;
    }
};
int main ()
{
    int numMetres, rows, columns;
    string row;
    scanf ("%d%d%d\n", &numMetres, &rows, &columns);
    bool visited [rows + 2][columns + 2];
    vector <int> areas;
    queue <CPair> toDo;
    for (int y = 0; y <= columns + 1; y++)
    {
        visited [0][y] = true;
        visited [rows + 1][y] = true;
    }
    for (int x = 1; x <= rows; x++)
    {
        getline (cin, row);
        for (int y = 0; y <= columns + 1; y++)
        {
            if (y == 0 || y == columns + 1)
            {
                visited [x][y] = true;
            }
            else if (row [y - 1] == 'I')
            {
                visited [x][y] = true;
            }
            else
            {
                visited [x][y] = false;
            }
        }
    }
    for (int x = 0; x < rows + 2; x++)
    {
        for (int y = 0; y < columns + 2; y++)
        {
            if (!visited [x][y])
            {
                toDo.push(CPair (x, y));
                visited [x][y] = true;
                int area = 1;
                while (!toDo.empty())
                {
                    CPair temp = toDo.front();
                    toDo.pop();
                    if (!visited [temp.r + 1][temp.c])
                    {
                        toDo.push(CPair(temp.r + 1, temp.c));
                        visited [temp.r + 1][temp.c] = true;
                        area++;
                    }
                    if (!visited [temp.r - 1][temp.c])
                    {
                        toDo.push(CPair(temp.r - 1, temp.c));
                        visited [temp.r - 1][temp.c] = true;
                        area++;
                    }
                    if (!visited [temp.r][temp.c + 1])
                    {
                        toDo.push(CPair(temp.r, temp.c + 1));
                        visited [temp.r][temp.c + 1] = true;
                        area++;
                    }
                    if (!visited [temp.r][temp.c - 1])
                    {
                        toDo.push(CPair(temp.r, temp.c - 1));
                        visited [temp.r][temp.c - 1] = true;
                        area++;
                    }
                }
                areas.push_back(area);
            }
        }
    }
    sort(areas.begin(), areas.end());
    int counter = 0;
    for (int index = (int)areas.size() - 1; index >= 0; index--)
    {
        if (numMetres >= areas [index])
        {
            counter++;
            numMetres -= areas [index];
        }
        else
        {
            break;
        }
    }
    if (counter == 1)
    {
        printf ("%d room, %d square metre(s) left over\n", counter, numMetres);
    }
    else
    {
        printf ("%d rooms, %d square metre(s) left over\n", counter, numMetres);
    }
        
    return 0;
}
