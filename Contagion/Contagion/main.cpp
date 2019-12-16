#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
using namespace std;
int countries;
int x, y;
int X, q;
ll t;
vector <pair <int, int>> adj [3001];
pair <int, int> coordinates [3001];
ll dist [3001][3001];
queue <int> Q;
bool visited [3001];
int main ()
{
    scanf ("%d", &countries);
    ll dis [countries];
    for (int i = 1; i <= countries; i++)
    {
        scanf ("%d%d", &x, &y);
        coordinates [i].first = x;
        coordinates [i].second = y;
    }
    scanf ("%d%d", &X, &q);
    for (int x = 1; x <= countries; x++)
    {
        for (int y = x; y <= countries; y++)
        {
            ll deltax = coordinates [x].first - coordinates [y].first;
            ll deltay = coordinates [x].second - coordinates [y].second;
            dist [x][y] = deltax*deltax + deltay*deltay;
            dist [y][x] = dist [x][y];
        }
    }
    memset (dis, 0x3f, sizeof (dis));
    dis [X - 1] = 0;
    for (int i = 0; i < countries; i++)
    {
        ll min = INF;
        int node = -1;
        for (int temp = 0; temp < countries; temp++)
        {
            if (!visited [temp + 1] && dis [temp] < min)
            {
                min = dis [temp];
                node = temp + 1;
            }
        }
        if (node == -1)
        {
            break;
        }
        visited [node] = true;
        for (int x = 1; x <= countries; x++)
        {
            if (!visited [x])
            {
                if (dis [x - 1] > dis [node - 1] + dist [x][node])
                {
                    dis [x - 1] = dis [node - 1] + dist [x][node];
                }
            }
        }
    }
    sort (dis, dis + countries);
    for (int i = 0; i < q; i++)
    {
        scanf ("%lld", &t);
        printf ("%ld\n", upper_bound (dis, dis + countries, t) - dis);
    }
    //lower_bound finds the first element not less than the key
    //upper_bound finds the first element greater than the key
    //returns a pointer
   /* for (int i = 0; i < q; i++)
    {
        scanf ("%lld", &t);
        int high = countries - 1;
        int lo = 0;
        while (lo + 1 < high)
        {
            int mid = (high + lo)/2;
            if (dis [mid] > t)
            {
                high = mid;
            }
            else
            {
                lo = mid;
            }
        }
        if (dis [high] <= t)
        {
            printf ("%d\n", high + 1);
        }
        else
        {
            printf ("%d\n", lo + 1);
        }
    }*/
    return 0;
}
