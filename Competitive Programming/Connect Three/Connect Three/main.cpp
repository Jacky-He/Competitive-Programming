#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y;
};
int Ax, Ay, Bx, By, Cx, Cy;
queue <node> Q;
bool visited [1003][1003];
vector <node> A;
vector <node> B;
vector <node> C;
bool contains (vector <node> & v, node n)
{
    for (node each: v)
    {
        if (n.x == each.x && n.y == each.y)
        {
            return true;
        }
    }
    return false;
}
int main ()
{
    scanf ("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
    Q.push ({Ax, Ay});
    visited [Ax][Ay] = true;
    bool broke = false;
    A.push_back ({Ax, Ay});
    while (!Q.empty() && !broke)
    {
        node temp = Q.front();
        Q.pop();
        vector <node> t;
        t.push_back ({temp.x + 1, temp.y});
        t.push_back ({temp.x - 1, temp.y});
        t.push_back ({temp.x, temp.y + 1});
        t.push_back ({temp.x, temp.y - 1});
        for (node each: t)
        {
            if (each.x >= 0 && each.x <= 1000 && each.y >= 0 && each.y <= 1000)
            {
                if (!visited [each.x][each.y])
                {
                    Q.push (each);
                    visited [each.x][each.y] = true;
                    A.push_back (each);
                }
                if (visited [Bx][By] && visited [Cx][Cy])
                {
                    broke = true;
                    break;
                }
            }
        }
    }
    for (int x = 0; x < 1003; x++)
    {
        memset (visited [x], 0, sizeof (visited [x]));
    }
    while (!Q.empty())
    {
        Q.pop();
    }
    Q.push ({Bx, By});
    visited [Bx][By] = true;
    broke = false;
    B.push_back ({Bx, By});
    while (!Q.empty() && !broke)
    {
        node temp = Q.front();
        Q.pop();
        vector <node> t;
        t.push_back ({temp.x + 1, temp.y});
        t.push_back ({temp.x - 1, temp.y});
        t.push_back ({temp.x, temp.y + 1});
        t.push_back ({temp.x, temp.y - 1});
        for (node each: t)
        {
            if (each.x >= 0 && each.x <= 1000 && each.y >= 0 && each.y <= 1000)
            {
                if (!visited [each.x][each.y])
                {
                    Q.push (each);
                    visited [each.x][each.y] = true;
                    A.push_back (each);
                }
                if (visited [Ax][Ay] && visited [Cx][Cy])
                {
                    broke = true;
                    break;
                }
            }
            
        }
    }
    for (int x = 0; x < 1003; x++)
    {
        memset (visited [x], 0, sizeof (visited [x]));
    }
    while (!Q.empty())
    {
        Q.pop();
    }
    Q.push ({Cx, Cy});
    visited [Cx][Cy] = true;
    broke = false;
    C.push_back ({Cx, Cy});
    while (!Q.empty() && !broke)
    {
        node temp = Q.front();
        Q.pop();
        vector <node> t;
        t.push_back ({temp.x + 1, temp.y});
        t.push_back ({temp.x - 1, temp.y});
        t.push_back ({temp.x, temp.y + 1});
        t.push_back ({temp.x, temp.y - 1});
        for (node each: t)
        {
            if (each.x >= 0 && each.x <= 1000 && each.y >= 0 && each.y <= 1000)
            {
                if (!visited [each.x][each.y])
                {
                    Q.push (each);
                    visited [each.x][each.y] = true;
                    A.push_back (each);
                }
                if (visited [Ax][Ay] && visited [Bx][By])
                {
                    broke = true;
                    break;
                }
            }
            
        }
    }
    vector <node> eventual;
    for (node each: A)
    {
        if (each.x >= 0 && each.x <= 1000 && each.y >= 0 && each.y <= 1000)
        {
            if (contains (B, each) && contains (C, each))
            {
                eventual.push_back (each);
            }
        }
    }
    printf ("%d\n", (int)eventual.size());
    for (node each: eventual)
    {
        printf ("%d %d\n", each.x, each.y);
    }
    return 0;
}
