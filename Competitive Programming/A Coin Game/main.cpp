#include <bits/stdc++.h>
#define seed1 31
#define seed2 131
typedef int8_t small;
typedef long long int ll;
using namespace std;

int powers [8][8];
int n, temp;
int dest, start;
int cnt = 0;
queue <deque <small>*> Q;
unordered_map <int, int> dis;
unordered_map <int, bool> visited;
void initPower()
{
    powers [0][0] = 1;
    for (int x = 1; x < 8; x++)
    {
        powers [x][0] = powers [x - 1][0]*seed1;
    }
    for (int x = 1; x < 8; x++)
    {
        powers [0][x] = powers [0][x - 1]*seed2;
    }
    for (int x = 1; x < 8; x++)
    {
        for (int y = 1; y < 8; y++)
        {
            powers [x][y] = powers [x - 1][y]*seed2;
        }
    }
}
void init ()
{
    for (auto& some: dis)
    {
        some.second = 0;
    }
    for (auto& each: visited)
    {
        each.second = false;
    }
}

int Hash (deque <small>* coins)
{
    int result = 0;
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < (int) coins [x].size(); y++)
        {
            result += powers [x][y]*coins [x][y];
            //cout << coins [x][y] << " ";
        }
        //cout << endl;
    }
    //cout << result << endl;
    return result;
}

void equate (deque <small>* d1, deque <small>* d2)
{
    for(int x = 0; x < 8; x++)
    {
        for (char each: d2 [x])
        {
            d1 [x].push_back (each);
        }
    }
}
int main ()
{
    initPower();

    while (true)
    {
        deque <small>* coins = new deque <small> [8];
        init ();
        cnt = 0;
        scanf ("%d", &n);

        if (n == 0)
        {
            break;
        }
        if (n == 1)
        {
            scanf ("%d", &temp);
            printf ("%d\n", 0);
            continue;
        }
        for (int x = 1; x <= n; x++)
        {
            coins [x - 1].push_back (x);
        }
        dest = Hash(coins);

        for (int x = 0; x < n; x++)
        {
            coins [x].clear ();
            scanf ("%d", &temp);
            coins [x].push_front(temp);
        }
        start = Hash (coins);

        dis [start] = 0;
        visited [start] = true;
        Q.push (coins);
        while (!Q.empty())
        {
            deque <small>* temp = Q.front();
            int curr = Hash (temp);
            Q.pop();
            cnt++;
            for (int x = 0; x < n; x++)
            {
                if (!temp [x].empty())
                {
                    //cout << "hi " << x << endl;
                    if (x == 0)
                    {
                        if (temp [x + 1].empty() || temp [x + 1][0] > temp [x][0])
                        {
                            deque <small>* each = new deque <small> [8];
                            equate (each, temp);
                            each [x + 1].push_front (each [x][0]);
                            each [x].pop_front();
                            int hash = Hash (each);
                            if (!visited [hash])
                            {
                                visited[hash] = true;
                                dis[hash] = dis[curr] + 1;
                                Q.push (each);
                            }
                        }
                    }
                    else if (x == n - 1)
                    {
                        if (temp [x - 1].empty() || temp [x - 1][0] > temp [x][0])
                        {
                            deque <small>* each = new deque <small> [8];
                            equate (each, temp);
                            each [x - 1].push_front (each [x][0]);
                            each [x].pop_front();
                            int hash = Hash (each);
                            if (!visited [hash])
                            {
                                visited [hash] = true;
                                dis [hash] = dis [curr] + 1;
                                Q.push (each);
                            }
                        }
                    }
                    else if (x > 0 && x < n - 1)
                    {
                        if (temp [x + 1].empty() || temp [x + 1][0] > temp [x][0])
                        {
                            deque <small>* each = new deque <small> [8];
                            equate (each, temp);
                            each [x + 1].push_front (each [x][0]);
                            each [x].pop_front();
                            int hash = Hash (each);
                            if (!visited [hash])
                            {
                                visited [hash] = true;
                                dis [hash] = dis[curr] + 1;
                                Q.push (each);
                            }
                        }
                        if (temp [x - 1].empty() || temp [x - 1][0] > temp [x][0])
                        {
                            deque <small>* each = new deque <small> [8];
                            equate (each, temp);
                            each [x - 1].push_front (each [x][0]);
                            each [x].pop_front();
                            int hash = Hash (each);
                            if (!visited [hash])
                            {
                                visited [hash] = true;
                                dis [hash] = dis [curr] + 1;
                                Q.push (each);
                            }
                        }
                    }
                }
            }
            delete [] temp;
        }
        if (dis [dest] == 0 && dest != start)
        {
            printf ("IMPOSSIBLE\n");
        }
        else
        {
            printf ("%d\n", dis [dest]);
        }
    }
    return 0;
}