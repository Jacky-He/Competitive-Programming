#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
pair <int, int> switches [1000002];
int newballs [1000002];
int prevballs [1000002];
bool inqueue [1000002];
queue <int> Q;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d%d", &a, &b);
        switches [x].first = a;
        switches [x].second = b;
    }
    newballs [1] = m;
    Q.push (1);
    inqueue [1] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        inqueue [temp] = false;
        if (temp == n + 1)
        {
            continue;
        }
        if (newballs [temp] % 2 == 0)
        {
            newballs [switches [temp].first] += newballs [temp]/2;
            newballs [switches [temp].second] += newballs [temp]/2;
        }
        else
        {
            if (prevballs [temp] % 2 == 0)
            {
                newballs [switches [temp].first] += newballs [temp]/2 + 1;
                newballs [switches [temp].second] += newballs [temp]/2;
            }
            else
            {
                newballs [switches [temp].first] += newballs [temp]/2;
                newballs [switches [temp].second] += newballs [temp]/2 + 1;
            }
        }
        prevballs [temp] += newballs [temp];
        newballs [temp] = 0;
        if (!inqueue[switches [temp].first] && newballs [switches [temp].first] != 0)
        {
            Q.push (switches [temp].first);
            inqueue [switches [temp].first] = true;
        }
        if (!inqueue [switches [temp].second] && newballs [switches [temp].second] != 0)
        {
            Q.push (switches [temp].second);
            inqueue [switches [temp].second] = true;
        }
    }
    for (int x = 1; x <= n; x++)
    {
        if (prevballs [x] % 2 == 0)
        {
            printf ("%d", 0);
        }
        else
        {
            printf ("%d", 1);
        }
    }
    printf ("\n");
    return 0;
}
