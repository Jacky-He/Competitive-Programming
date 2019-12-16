#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;
bool contains (vector <int> vector, int num)
{
    for (int each: vector)
    {
        if (each == num)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    for (int x = 0; x < 5; x++)
    {
        int numEdges;
        cin >> numEdges;
        vector <int> startNodes;
        vector <int> endNodes;
        vector <int> results;
        for (int y = 0; y < numEdges; y++)
        {
            int s;
            int e;
            cin >> s;
            cin >> e;
            startNodes.push_back (s);
            endNodes.push_back (e);
        }
        for (;;)
        {
            unsigned int counter = 0;
            bool valid = true;
            for (unsigned int index = 0; index < endNodes.size(); index++)
            {
                if (contains (startNodes, endNodes.at(index)))
                {
                    counter++;
                }
                else
                {
                    valid = false;
                    endNodes.erase(endNodes.begin() + index);
                    startNodes.erase(startNodes.begin() + index);
                    break;
                }
            }
            if (valid && counter == endNodes.size())
            {
                break;
            }
        }
        for (;;)
        {
            unsigned int counter = 0;
            bool valid = true;
            for (unsigned int index = 0; index < startNodes.size(); index++)
            {
                if (contains (endNodes, startNodes.at(index)))
                {
                    counter++;
                }
                else
                {
                    valid = false;
                    endNodes.erase(endNodes.begin() + index);
                    startNodes.erase(startNodes.begin() + index);
                    break;
                }
            }
            if (valid && counter == startNodes.size())
            {
                break;
            }
        }
        cout << startNodes.size() << endl;
    }
    return 0;
}
