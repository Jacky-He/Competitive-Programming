#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, m;
    scanf ("%d%d", &n, &m);
    int sum = 1;
    int current;
    scanf ("%d", &current);
    int next = current;
    for (int x = 1; x < m; x++)
    {
        scanf ("%d", &next);
        if (current + 1 == next || current - 1 == next)
        {
            sum ++;
        }
        else
        {
            sum += 2;
        }
        current = next;
    }
    printf ("%d\n", sum + 1);
    return 0;
}
