#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
ll num;
vector <pair <ll, int>> numbers; //first: value, second: index;
vector <ll> differences;
unordered_map <ll, int> diffcnt;

bool check ()
{
    return diffcnt.size() == 1;
}

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        numbers.push_back ({num, x + 1});
    }
    sort (numbers.begin(), numbers.end());
    if (n == 2 || n == 3)
    {
        printf ("1\n");
        return 0;
    }
    
    for (int x = 0; x < (int)numbers.size() - 1; x++)
    {
        ll diff = numbers [x + 1].first - numbers [x].first;
        differences.push_back (diff);
        diffcnt [diff]++;
    }
    
    int ans = -1;
    for (int x = 0; x < (int)differences.size(); x++)
    {
        if (x == 0)
        {
            diffcnt [differences [x]]--;
            if (diffcnt [differences [x]] == 0)
            {
                diffcnt.erase (differences [x]);
            }
            if (check())
            {
                ans = numbers [0].second;
                break;
            }
            diffcnt [differences [x]]++;
        }
        else if (x == (int)differences.size() - 1)
        {
            diffcnt [differences [x]]--;
            if (diffcnt [differences [x]] == 0)
            {
                diffcnt.erase (differences [x]);
            }
            if (check())
            {
                ans = numbers.back().second;
                break;
            }
            diffcnt [differences [x]]++;
        }
        
        if (x < (int)differences.size() - 1)
        {
            int sum = differences [x] + differences [x + 1];
            
            diffcnt [sum]++;
            diffcnt [differences [x]]--;
            if (diffcnt [differences [x]] == 0)
            {
                diffcnt.erase (differences [x]);
            }
            diffcnt [differences [x + 1]]--;
            if (diffcnt [differences [x + 1]] == 0)
            {
                diffcnt.erase (differences [x + 1]);
            }
            if (check ())
            {
                ans = numbers [x + 1].second;
                break;
            }
            diffcnt [differences [x]]++;
            diffcnt [differences [x + 1]]++;
            diffcnt [sum]--;
            if (diffcnt [sum] == 0)
            {
                diffcnt.erase (sum);
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}


