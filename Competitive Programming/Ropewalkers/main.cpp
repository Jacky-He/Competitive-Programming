#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector <int> v;
int a, b, c, d;

int main ()
{
    scanf ("%d%d%d%d", &a, &b, &c, &d);
    v.pb (a);
    v.pb (b);
    v.pb (c);
    sort (v.begin(), v.end());
    
    int sum = 0;
    sum += d - (v[1] - v[0]) < 0? 0 : d - (v[1] - v[0]);
    sum += (d - (v [2] - v[1])) < 0? 0: (d - (v [2] - v[1]));
    
    printf ("%d\n", sum);
    return 0;
}
