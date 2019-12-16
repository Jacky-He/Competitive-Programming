#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> v;  //first: require, second: bonus
int n, strength;
int a, b;
bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return (p1.first < p2.first) || (p1.first == p2.first && p1.second > p2.second);
}
int main()
{
    scanf ("%d%d", &strength, &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%d%d", &a, &b);
        v.push_back ({a, b});
    }
    sort (v.begin(), v.end (), cmp);
    for (int x = 0; x < n; x++)
    {
        if (strength <= v [x].first)
        {
            printf ("NO\n");
            return 0;
        }
        strength += v [x].second;
    }
    printf ("YES\n");
    return 0;
}