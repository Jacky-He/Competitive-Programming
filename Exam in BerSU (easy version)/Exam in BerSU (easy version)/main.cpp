#include <bits/stdc++.h>
using namespace std;

int n, m, num;
vector <int> students;

map <int, int, greater <int>> timespendcnt;

int main ()
{
    scanf ("%d%d", &n, &m);
    int sum = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        sum += num;
        int extra = sum - m;
        int result = 0;
        if (extra > 0)
        {
            for (auto const& each: timespendcnt)
            {
                int cnt = each.second;
                int t = each.first;
                
                int remainder = extra%t;
                int quotient = extra/t;
                
                if (remainder == 0)
                {
                    if (quotient <= cnt)
                    {
                        result += quotient;
                        break;
                    }
                    else
                    {
                        extra -= cnt*t;
                        result += cnt;
                    }
                }
                else
                {
                    if (quotient + 1 <= cnt)
                    {
                        result += quotient + 1;
                        break;
                    }
                    else
                    {
                        extra -= cnt*t;
                        result += cnt;
                    }
                }
            }
        }
        printf ("%d ", result);
        timespendcnt [num]++;
    }
    return 0;
}



