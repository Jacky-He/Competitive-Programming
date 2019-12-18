#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
using namespace std;

int va, vb, m;
bool visited [1004][1004];
pair <pair <int, int>, pair <int, int>> previ [1004][1004]; //1: fill A, 2: fill B, 3: pour A B, 4: pour B A, 5: chug A, 6: chug B
queue <pair <int, int>> Q;

string kinds [] = {"fill A", "fill B", "pour A B", "pour B A", "chug A", "chug B"};

vector <pair <int, int>> adj (pair <int, int> p)
{
    vector <pair <int, int>> v;
    //fill A
    v.push_back ({va, p.second});
    //fill B
    v.push_back ({p.first, vb});
    //pour A B
    if (p.first + p.second <= vb)
    {
        v.push_back ({0, p.first + p.second});
    }
    else
    {
        v.push_back ({p.first - (vb - p.second), vb});
    }
    //pour B A
    if (p.first + p.second <= va)
    {
        v.push_back ({p.first + p.second, 0});
    }
    else
    {
        v.push_back ({va, p.second - (va - p.first)});
    }
    //chug A
    v.push_back ({0, p.second});
    //chug B
    v.push_back ({p.first, 0});
    return v;
}

int main ()
{
    cin >> va >> vb >> m;
    Q.push ({0, 0});
    visited [0][0] = true;
    while (!Q.empty())
    {
        pair <int, int> temp = Q.front();
        Q.pop();
        vector <pair <int, int>> v = adj (temp);
        for (int i = 0; i < (int)v.size(); i++)
        {
            pair <int, int> each = v [i];
            if (!visited [each.first][each.second])
            {
                visited [each.first][each.second] = true;
                previ [each.first][each.second].first = temp;
                previ [each.first][each.second].second.first = i;
                previ [each.first][each.second].second.second = previ [temp.first][temp.second].second.second + 1;
                Q.push (each);
            }
        }
    }
    pair <int, pair <int, int>> result = {INF, {-1, -1}};
    for (int x = 0; x <= va; x++)
    {
        if (visited [x][m])
        {
            if (previ [x][m].second.second < result.first)
            {
                result = {previ [x][m].second.second, {x, m}};
            }
        }
        
    }
    for (int x = 0; x <= vb; x++)
    {
        if (visited [m][x])
        {
            if (previ [m][x].second.second < result.first)
            {
                result = {previ [m][x].second.second, {m, x}};
            }
        }
    }
    if (result.first == INF)
    {
        cout << "Not possible" << endl;
        return 0;
    }
    vector <string> output;
    while (result.second.first != 0 || result.second.second != 0)
    {
        output.push_back (kinds [previ [result.second.first][result.second.second].second.first]);
        result.second = previ [result.second.first][result.second.second].first;
    }
    for (int x = (int)output.size() - 1; x >= 0; x--)
    {
        cout << output [x] << endl;
    }
    return 0;
}
