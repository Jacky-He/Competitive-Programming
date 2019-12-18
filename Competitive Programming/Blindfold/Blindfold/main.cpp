#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main (int nNumberofArgs, char* pszArgs [])
{
    int x, y;
    cin >> y;
    cin >> x;
    char map [x][y];
    for (int num = 0; num < y; num++)
    {
        string row;
        cin >> row;
        for (int num2 = 0; num2 < x; num2++)
        {
            map [num2][num] = row.at(num2);
        }
    }
    int numInstructions;
    cin >> numInstructions;
    char instructions [numInstructions];
    //1: right, 2: up, 3: left, 4: down
    int possibilities [4] = {1, 2, 3, 4};
    for (int instructionNumber = 0; instructionNumber < numInstructions; instructionNumber++)
    {
        cin >> instructions [instructionNumber];
    }
    for (int num = 0; num < y; num++)
    {
        for (int num2 = 0; num2 < x; num2++)
        {
            for (int each: possibilities)
            {
                int startX = num2;
                int startY = num;
                int orientation = each;
                int index = 0;
                bool possible = 1;
                while ((startX >= 0 && startX < x) && (startY >= 0 && startY < y) && (index < numInstructions))
                {
                    char instruction = instructions[index];
                    if (map[startX][startY] == 'X')
                    {
                        possible = 0;
                        break;
                    }
                    if (instruction == 'L')
                    {
                        if (orientation == 4)
                        {
                            orientation = 1;
                        }
                        else
                        {
                            orientation++;
                        }
                    }
                    else if (instruction == 'R')
                    {
                        if (orientation == 1)
                        {
                            orientation = 4;
                        }
                        else
                        {
                            orientation--;
                        }
                    }
                    else if (instruction == 'F')
                    {
                        if (orientation == 1)
                        {
                            startX++;
                        }
                        else if (orientation == 2)
                        {
                            startY--;
                        }
                        else if (orientation == 3)
                        {
                            startX--;
                        }
                        else if (orientation == 4)
                        {
                            startY++;
                        }
                    }
                    if (map[startX][startY] == 'X')
                    {
                        possible = 0;
                        break;
                    }
                    if (!(startX >= 0 && startX < x && startY >= 0 && startY < y))
                    {
                        possible = 0;
                    }
                    index++;
                }
                if (possible == 1)
                {
                    map[startX][startY] = '*';
                }
            }
        }
    }
    for (int indexY = 0; indexY < y; indexY++)
    {
        for (int indexX = 0; indexX < x; indexX++)
        {
            cout << map[indexX][indexY];
        }
        cout << endl;
    }
    return 0;
}
