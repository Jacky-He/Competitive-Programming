#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, k, a, b;
vector <int> adj [100001];
vector <int> sellGifts;
int temp;
int from, to;
bool visited [100001];
int disa [100001];
int disb [100001];
queue <int> Q;
int main ()
{
    scanf ("%d%d%d%d%d", &n, &m, &k, &a, &b);
    for (int x = 0; x < k; x++)
    {
        scanf ("%d", &temp);
        sellGifts.push_back (temp);
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    memset (disa, -1, sizeof (disa));
    memset (disb, -1, sizeof (disb));
    Q.push (a);
    visited [a] = true;
    disa [a] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for(int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                disa [each] = disa [temp] + 1;
                Q.push (each);
            }
        }
    }
    memset (visited, false, sizeof (visited));
    Q.push (b);
    visited [b] = true;
    disb [b] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for(int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                disb [each] = disb [temp] + 1;
                Q.push (each);
            }
        }
    }
    int min = INF;
    for (int each: sellGifts)
    {
        if (disa [each] != -1 && disb [each] != -1)
        {
            if (disa [each] + disb [each] < min)
            {
                min = disa [each] + disb[each];
            }
        }
    }
    printf ("%d\n", min);
    return 0;
}
