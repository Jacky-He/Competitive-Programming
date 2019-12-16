#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
string line;
int numlines;
int size;
int counter;
int main ()
{
    cin >> numlines;
    getline (cin, line);
    for (int x = 0; x < numlines; x++)
    {
        counter = 0;
        getline (cin, line);
        size = (int) line.size();
        unordered_set<string> elements;
        for (int substringsize = 1; substringsize <= size; substringsize++)
        {
            for (int index = 0; index < size - substringsize + 1; index++)
            {
                elements.insert (line.substr(index, substringsize));
            }
            counter += elements.size();
            elements.clear();
        }
        cout << counter + 1 << endl;
    }
    return 0;
}
