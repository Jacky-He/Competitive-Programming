#include <utility>
#include <iostream>

using namespace std;

pair <int, int> values [17]; //first: row, second: col;
string line;
int toInt (char c)
{
    if (c == '.')
    {
        return 15;
    }
    return c - 'A';
}

int main ()
{
    for (int x = 0, j = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++, j++)
        {
            values [j] = {x, y};
        }
    }
    int result = 0;
    for (int x = 0; x < 4; x++)
    {
        cin >> line;
        for (int y = 0; y < 4; y++)
        {
            if (line [y] != '.')
            {
                result += abs(x - values [toInt(line[y])].first) + abs (y - values [toInt(line [y])].second);
            }
        }
    }
    cout << result << endl;
    return 0;
}