#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int length, parts, jump;
int temp, temp2;
int currTime, currInch, currIndex;
vector <pair <int, int>> inch; //first: inch, second: time taken to dry

bool work (int timetaken)
{
    currInch = 0;
    for (int x = 1; x < (int) inch.size(); x++)
    {
        if (inch [x].first - currInch <= jump && inch [x].second <= timetaken)
        {
            currInch = inch [x].first;
        }
    }
    return currInch == length + 1;
}

int main ()
{
    scanf ("%d%d%d", &length, &parts, &jump);
    inch.push_back ({0, 0});
    inch.push_back ({length + 1, 0});
    for (int x = 0; x < parts; x++)
    {
        scanf ("%d%d", &temp, &temp2);
        inch.push_back ({temp, temp2});
    }
    sort (inch.begin(), inch.end());
    for (int x = 0; x < (int) inch.size(); x++)
    {
        if (inch [x + 1].first - inch [x].first > jump)
        {
            printf ("%d\n", -1);
            return 0;
        }
    }
    int hi = 1000001;
    int lo = 0;
    while (lo + 1 < hi)
    {
        currTime = (lo + hi)/2;
        if (work (currTime))
        {
            hi = currTime;
        }
        else
        {
            lo = currTime;
        }
    }
    int result = 0;
    if (work (lo))
    {
        result = lo;
    }
    else if (work (hi))
    {
        result = hi;
    }
    printf ("%d\n", result);
    return 0;
}