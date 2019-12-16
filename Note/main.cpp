#include <bits/stdc++.h>
using namespace std;
int n;
int nPrevious;
int main ()
{
    scanf ("%d", &nPrevious);
    int counter1 = 0;
    int counter2 = 0;
    for (int x = 1; x < 8; x++)
    {
        scanf ("%d", &n);
        if (n < nPrevious)
        {
            counter2++;
        }
        else if (n > nPrevious)
        {
            counter1++;
        }
        nPrevious = n;
    }
    if (counter2 == 7)
    {
        cout << "descending" << endl;
    }
    else if (counter1 == 7)
    {
        cout << "ascending" << endl;
    }
    else
    {
        cout << "mixed" << endl;
    }
    return 0;
}
