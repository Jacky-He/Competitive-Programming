#include <bits/stdc++.h>
#define INFINT 0x3f3f3f3f
const double INF = 9999999;
using namespace std;
int nodes, edges;
int from, to;
double dis, speed;
vector <pair <int, double>> adj [1001];
double t [1001];
int roads [1001];
//priority_queue <pair<double, int>, vector <pair<double, int>>, greater <pair<double, int>>> Q;
int main ()
{
    scanf ("%d%d", &nodes, &edges);
    for (int x = 0; x < edges; x++)
    {
        scanf ("%d%d%lf%lf", &from, &to, &dis, &speed);
        adj [from].push_back ({to, dis/speed*60});
        adj [to].push_back ({from, dis/speed*60});
    }
    memset (t, INF, sizeof (t));
    memset (roads, 0x3f, sizeof (roads));
  /*  Q.push ({0, 1}); //first distance, second node
    t [1] = 0;
    roads [1] = 0;
    while (!Q.empty())
    {
        double td = Q.top().first;
        int tn = Q.top().second;
        Q.pop();
        if (td > t [tn])
        {
            continue;
        }
        for (pair <int, double> each: adj [tn])
        {
            if (t [each.first] > t [tn] + each.second || (t [each.first] == t [tn] + each.second && roads [each.first] > roads [tn] + 1))
            {
                t [each.first] = t [tn] + each.second;
                roads [each.first] = roads [tn] + 1;
                Q.push ({t[each.first], each.first});
            }
        }
    }*/
    queue <int> Q;
    Q.push(1);
    t [1] = 0.0;
    roads [1] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, double> each: adj [temp])
        {
            if (t [each.first] > t [temp] + each.second)
            {
                t [each.first] = t [temp] + each.second;
                roads [each.first] = roads [temp] + 1;
                Q.push (each.first);
            }
            else if (t [each.first] == t [temp] + each.second)
            {
                if (roads [each.first] > roads [temp] + 1)
                {
                    roads [each.first] = roads [temp] + 1;
                }
            }
        }
    }
    printf ("%d\n", roads [nodes]);
    printf ("%.0lf\n", t [nodes]*(1.0/3));
    return 0;
}
