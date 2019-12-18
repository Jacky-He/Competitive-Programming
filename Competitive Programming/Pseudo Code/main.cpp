#include <bits/stdc++.h>
using namespace std;
int n, num, diff;
vector <int> v;
unordered_map <int, int> frequency;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        v.push_back (num);
    }
    scanf ("%d", &diff);
    sort (v.begin(), v.end());
    for (int x = 0; x < (int)v.size(); x++)
    {
        frequency [v[x]]++;
    }
    int cnt = 0;
    for (int x = 0; x < (int)v.size(); x++)
    {
        cnt += frequency [v[x] + diff];
    }
    cout << cnt << endl;
    return 0;
}
