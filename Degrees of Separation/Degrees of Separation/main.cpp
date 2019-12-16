#include <bits/stdc++.h>
using namespace std;
set <int> friends [50];
bool visited [50];
int dis [50];
void initialize (int x, int y)
{
    friends [x].insert (y);
    friends [y].insert (x);
}
void start ()
{
    initialize (2, 6);
    initialize (1, 6);
    initialize (6, 7);
    initialize (3, 4);
    initialize (4, 5);
    initialize (3, 5);
    initialize (3, 6);
    initialize (4, 6);
    initialize (5, 6);
    initialize (7, 8);
    initialize (8, 9);
    initialize (3, 15);
    initialize (9, 12);
    initialize (9, 10);
    initialize (11, 10);
    initialize (12, 11);
    initialize (15, 13);
    initialize (13, 14);
    initialize (12, 13);
    initialize (18, 16);
    initialize (18, 17);
    initialize (16, 17);
}
void i ()
{
    int x, y;
    cin >> x >> y;
    initialize (x, y);
}
void d ()
{
    int x, y;
    cin >> x >> y;
    friends [x].erase (y);
    friends [y].erase (x);
}
void n ()
{
    int x;
    cin >> x;
    printf ("%d\n", (int)friends [x].size());
}
void f ()
{
    int x;
    cin >> x;
    memset (visited, 0, sizeof (visited));
    visited [x] = true;
    int counter = 0;
    for (int each: friends [x])
    {
        visited [each] = true;
    }
    for (int each: friends [x])
    {
        for (int each2 : friends [each])
        {
            if (!visited [each2])
            {
                visited [each2] = true;
                counter++;
            }
        }
    }
    printf ("%d\n", counter);
}
void s ()
{
    memset (visited, 0, sizeof (visited));
    memset (dis, 0, sizeof (dis));
    queue <int> something;
    int x, y;
    cin >> x >> y;
    something.push (x);
    visited [x] = true;
    bool connected = false;
    while (!something.empty())
    {
        int temp = something.front();
        something.pop();
        if (temp == y)
        {
            connected = true;
            break;
        }
        for (int each: friends [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                dis [each] = dis [temp] + 1;
                something.push (each);
            }
        }
    }
    if (connected)
    {
        printf ("%d\n", dis [y]);
    }
    else
    {
        printf ("Not connected\n");
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    start ();
    char command;
    for (int x = 0; x < 6; x++)
    {
        cin >> command;
        if (command == 'q')
        {
            break;
        }
        else
        {
            switch (command)
            {
                case 'i':
                    i ();
                    break;
                case 'd':
                    d ();
                    break;
                case 'n':
                    n ();
                    break;
                case 'f':
                    f ();
                    break;
                case 's':
                    s ();
                    break;
            }
        }
    }
    return 0;
}
