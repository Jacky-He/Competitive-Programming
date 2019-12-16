#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int numSoldiers;
    string line;
    cin >> numSoldiers;
    cin >> line;
    int numR = 0;
    bool RPresent = false;
    int accumulate = 0;
    int lastLaccumulate = 0;
    int lastL = 0;
    for (int x = 0; x < line.length(); x++)
    {
        if (line [x] == 'R')
        {
            RPresent = true;
            if (accumulate > 0)
            {
                accumulate--;
            }
            numR++;
        }
        else if (line[x] == 'L'  && RPresent)
        {
            lastLaccumulate = accumulate;
            accumulate++;
            lastL = numR;
        }
    }
    cout << lastL + lastLaccumulate << endl;
    return 0;
}
