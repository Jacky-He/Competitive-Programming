#include <bits/stdc++.h>
using namespace std;

struct triplet {int first, second, third;};
triplet maketriplet (int first, int second, int third)
{
    triplet t;
    t.first = first;
    t.second = second;
    t.third = third;
    return t;
}

int n, m, warm, cold, q, op, num;
int from, to, weight;
triplet edges [200004];
vector <triplet> adj [100004];
int warmdis [100004];
int colddis [100004];
queue <int> Q;


int main ()
{
    scanf ("%d%d%d%d", &n, &m, &warm, &cold);
    for (int x = 1; x <= m; x++)
    {
        scanf  ("%d%d%d", &from, &to, &weight);
        edges [x] = maketriplet (from, to, weight);
        adj [from].push_back (maketriplet(to, weight, x));
        adj [to].push_back (maketriplet (from, weight, x));
    }
    memset (warmdis, 0x3f, sizeof (warmdis));
    memset (colddis, 0x3f, sizeof (colddis));
    warmdis [warm] = 0;
    colddis [cold] = 0;
    Q.push (warm);
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (triplet each: adj [temp])
        {
            if (warmdis [temp] + each.second < warmdis [each.first])
            {
                warmdis [each.first] = warmdis [temp] + each.second;
                Q.push (each.first);
            }
        }
    }
    Q.push (cold);
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (triplet each: adj [temp])
        {
            if (colddis [temp] + each.second < colddis [each.first])
            {
                colddis [each.first] = colddis [temp] + each.second;

                Q.push (each.first);
            }
        }
    }
    scanf ("%d", &q);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d", &op, &num);
        if (op == 1)
        {
            if (warmdis [num] == colddis [num])
            {
                printf ("%d\n", warmdis [num]);
            }
            else
            {
                printf ("%d\n", -1);
            }
        }
        else
        {
            int from = edges [num].first;
            int to = edges [num].second;
            if (warmdis [from] == colddis [from] && warmdis [to] == colddis [to])
            {
                printf ("%d\n", min (colddis [to], warmdis [from]));
            }
            else if (warmdis [from] == colddis [from] && warmdis [to] != colddis [to])
            {
                if (min (warmdis [to], colddis [to]) + edges [num].third == warmdis [from])
                {
                    printf ("%d\n", -1);
                }
                else
                {
                    printf ("%d\n", warmdis [from]);
                }
            }
            else if (warmdis [from] != colddis [from] && warmdis [to] == colddis [to])
            {
                if (min (warmdis [from], colddis [from]) + edges [num].third == warmdis [to])
                {
                    printf ("%d\n", -1);
                }
                else
                {
                    printf ("%d\n", colddis [to]);
                }
            }
            else if ((warmdis [from] < colddis [from] && warmdis [to] > colddis [to]) || (warmdis [from] > colddis [from] && warmdis [to] < colddis [to]))
            {
                int temp = abs (min(warmdis [from], colddis [from]) - min (warmdis [to], colddis [to]));
                int mini = max (min (warmdis [from], colddis [from]), min (warmdis [to], colddis [to]));
                printf ("%.1f\n", (edges [num].third - temp)/2.0 + mini);
            }
            else
            {
                printf ("%d\n", -1);
            }
        }
        
    }
    return 0;
}





