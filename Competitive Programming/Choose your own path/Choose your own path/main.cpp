#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int pages;
int numOptions;
int connectedNodes;
vector <int> connections [10001];
vector <int> levels [10002];
bool reached [10001];

int main ()
{
    scanf ("%d", &pages);
    for (int x = 1; x <= pages; x++)
    {
        scanf ("%d", &numOptions);
        for (int something = numOptions; something> 0; something--)
        {
            scanf ("%d", &connectedNodes);
            connections [x].push_back(connectedNodes);
        }
    }
    levels [1].push_back (1);
    reached [1] = true;
    int index = 1;
    bool added = true;
    while (added)
    {
        added = false;
        for (int each: levels [index])
        {
            for (int each2: connections [each])
            {
                if (!(reached [each2]))
                {
                    added = true;
                    levels [index + 1].push_back (each2);
                    reached [each2] = true;
                }
            }
        }
        index++;
    }
    bool yes = true;
    for (int anotherindex = 1; anotherindex <= pages; anotherindex++)
    {
        if (!(reached [anotherindex]))
        {
            yes = false;
            break;
        }
    }
    if (yes)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    bool finish = false;
    for (int index2 = 1; index2 <= index; index2++)
    {
        for (int each: levels [index2])
        {
            if (connections [each].size() == 0)
            {
                finish = true;
                cout << index2 << endl;
                break;
            }
        }
        if (finish)
        {
            break;
        }
    }
    return 0;
}
