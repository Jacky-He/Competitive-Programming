#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair <int, int>> arr;
int* dp1 = new int [5000001];
int* dp2 = new int [5000001];
int first, second;
int sum = 0;

int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d%d", &first, &second);
        arr.push_back({second, first});
        sum += first*second;
    }
    int target = sum - sum/2;
    sort (arr.begin(), arr.end());
    for (int x = 1; x <= n; x++)
    {
        for (int i = 0; i <= target; i++)
        {
            int value = min(arr [x - 1].second*arr [x - 1].first, i/arr[x - 1].first*arr[x - 1].first);
            if (i - value >= 0)
            {
                dp2 [i] = max (dp1 [i], max (dp2 [i], dp1 [i - value] + value));
            }
            else
            {
                dp2 [i] = max (dp2 [i], dp1 [i]);
            }
        }
        int* temp = dp1;
        dp1 = dp2;
        dp2 = temp;
    }
    printf ("%d\n", abs(sum - 2*dp1 [target]));
    return 0;
}
/*
 4
 3 5
 3 3
 1 2
 3 100
 

*/

