#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, q;
string letter, word;
set <pair <int ,int>> visited;

char grid [30][30];

pair <int, int> directions [] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool inbound (pair <int, int> p)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n;
}

bool findhelper (pair <int, int> pos, int index)
{
    if (index >= (int) word.size())
    {
        return false;
    }
    if (index == (int) word.size() - 1 && grid [pos.first][pos.second] == word [index])
    {
        return true;
    }
    if (word [index] != grid [pos.first][pos.second])
    {
        return false;
    }
    visited.insert (pos);
    bool res = false;
    for (int x = 0; x < 8; x++)
    {
        pair <int, int> newpos = {pos.first + directions [x].first, pos.second + directions [x].second};
        if (inbound (newpos) && !visited.count(newpos))
        {
            res |= findhelper (newpos, index + 1);
        }
    }
    visited.erase (pos);
    return res;
}

bool find ()
{
    bool res = false;
    for (int x = 0; x < 25; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            res |= findhelper({x, y}, 0);
        }
    }
    return res;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie (0); cout.tie (0);
    cin >> n >> q;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cin >> letter;
            grid [x][y] = letter[0];
        }
    }
    for (int x = 0; x < q; x++)
    {
        cin >> word;
        cout << (find()? "good puzzle!" : "bad puzzle!") << endl;
    }
    return 0;
}



