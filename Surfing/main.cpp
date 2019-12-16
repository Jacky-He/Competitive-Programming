#include <bits/stdc++.h>
#define MOD 1000007
using namespace std;
map <string, set <string>> connections;
bool found;
int main ()
{
    int numLinks;
    string lines;
    char fromLink [80];
    string toLink;
    int index;
    scanf ("%d\n", &numLinks);
    for (int x = 0; x < numLinks; x++)
    {
        scanf ("%s", fromLink);
        getline (cin, lines);
        while (lines != "</HTML>")
        {
            while ((int)lines.find ("<A HREF") != -1)
            {
                toLink = "";
                index = (int)lines.find ("<A HREF");
                for (int x = index + 9; lines [x] != '"'; x++)
                {
                    toLink += lines [x];
                }
                connections [fromLink].insert(toLink);
                cout << "Link from " << fromLink << " to " << toLink << endl;
                lines.replace(index, 7, "lllllll");
            }
            getline (cin, lines);
        }
    }
    string begins;
    string ends;
    getline (cin, begins);
    queue <string> tasks;
    unordered_set <string> reachedNodes;
    while (begins != "The End")
    {
        getline (cin, ends);
        tasks.push (begins);
        while (!tasks.empty())
        {
            string something = tasks.front();
            tasks.pop();
            if (something == ends)
            {
                found = true;
                continue;
            }
            for (string each: connections [something])
            {
                if (reachedNodes.find(each) == reachedNodes.end())
                {
                    tasks.push(each);
                    reachedNodes.insert(each);
                }
            }
        }
        if (found)
        {
            cout << "Can surf from " << begins << " to " << ends << "." << endl;
        }
        else
        {
            cout << "Can't surf from " << begins << " to " << ends << "." << endl;
        }
        found = false;
        reachedNodes.clear();
        getline (cin, begins);
    }
    return 0;
}
