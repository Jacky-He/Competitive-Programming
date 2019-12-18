#include <bits/stdc++.h>
using namespace std;
int n;
int num, sum;
double target;
vector <int> v;
bool cmp (int n1, int n2)
{
    return n1 > n2;
}
int main()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        v.push_back (num);
        sum += num;
    }
    target = sum/2.0;
    sort (v.begin(), v.end(), cmp);
    int cnt = 0;
    int curr = 0;
    for (int each: v)
    {
        curr += each;
        cnt++;
        if (curr > target)
        {
            break;
        }
    }
    printf ("%d\n", cnt);
    return 0;
}