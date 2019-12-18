#include <bits/stdc++.h>
using namespace std;
map <char, set <char>> adjacencyMatrix;
map <string, int> frequency;
vector <vector <char>> paths;
set <char> visited;
vector <char> path;
vector <string> answer;
void dfs (char start, char end)
{
    visited.insert (start);
    path.push_back (start);
    for (char each: adjacencyMatrix [start])
    {
        if (visited.find(each) == visited.end())
        {
            if (each == end)
            {
                path.push_back (each);
                paths.push_back(path);
                path.pop_back();
            }
            else
            {
                dfs (each, end);
            }
        }
    }
    path.pop_back();
    visited.erase(start);
}
int main ()
{
    string str;
    getline (cin, str);
    while (str != "**")
    {
        adjacencyMatrix [str[0]].insert(str[1]);
        adjacencyMatrix [str[1]].insert(str[0]);
        getline (cin, str);
    }
    dfs ('A', 'B');
    for (vector <char> each: paths)
    {
        for (int index = 0; index < (int)each.size() - 1; index++)
        {
            string hi = "  ";
            hi [0] = each [index];
            hi [1] = each [index + 1];
            frequency [hi]++;
            if (frequency [hi] == (int)paths.size())
            {
                answer.push_back(hi);
            }
        }
    }
    for (string each: answer)
    {
        cout << each << endl;
    }
    printf ("There are %d disconnecting roads.\n", (int)answer.size());
    return 0;
}
