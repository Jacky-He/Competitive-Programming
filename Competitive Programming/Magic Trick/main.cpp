#include <bits/stdc++.h>
using namespace std;
int n, num;
vector <int> remains;
queue <int> output;
int main ()
{
    for (int x = 0; x < 5; x++)
    {
        scanf ("%d", &n);
        remains.clear();
        bool yes = true;
        int arr [101];
        while (!output.empty())
        {
            output.pop();
        }
        for (int y = 1; y <= n; y++)
        {
            remains.push_back (y);
        }
        for (int y = 0; y < n; y++)
        {
            scanf ("%d", &num);
            arr [y] = num;
        }
        for (int y = 0; y < n; y++)
        {
            if (((int)remains.size()) - 1 - arr[y] >= 0)
            {
                output.push (remains [remains.size() - 1 - arr[y]]);
                remains.erase(remains.end() - 1 - arr[y]);
            }
            else
            {
                printf ("IMPOSSIBLE");
                yes = false;
                break;
            }
        }
        if (yes)
        {
            while (!output.empty())
            {
                printf ("%d ", output.front());
                output.pop();
            }
        }
        printf ("\n");
    }
    return 0;
}
