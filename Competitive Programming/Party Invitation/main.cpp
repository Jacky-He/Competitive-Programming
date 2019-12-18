#include <bits/stdc++.h>
using namespace std;
int k, m;
int rem;
vector <int> friends;
int main ()
{
    scanf ("%d%d", &k, &m);
    for (int x = 1; x <= k; x++)
    {
        friends.push_back (x);
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d", &rem);
        int temp = rem;
        int tempsize = (int) friends.size();
        int minus = 1;
        while (temp <= tempsize)
        {
            friends.erase(friends.begin() + temp - minus);
            temp += rem;
            minus++;
        }
    }
    for (int each: friends)
    {
        printf ("%d\n", each);
    }
    return 0;
}
