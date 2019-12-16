#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int motelLocation [14] {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
vector <int> motelList;
int A, B, numAdditionalMotels;
int temp;
map <int, ll> dp;
ll numWays (int finish)
{
    if (dp [finish] != -1)
    {
        return dp [finish];
    }
    if (finish == 0)
    {
        return 1;
    }
    ll totalways = 0;
    for (int each: motelList)
    {
        if (each + A <= finish && each + B >= finish)
        {
            totalways += numWays (each);
        }
    }
    return dp [finish] = totalways;
}
int main ()
{
    for (int x = 0; x < 14; x++)
    {
        motelList.push_back (motelLocation [x]);
    }
    scanf ("%d%d%d", &A, &B, &numAdditionalMotels);
    for (int x = 0; x < numAdditionalMotels; x++)
    {
        scanf ("%d", &temp);
        motelList.push_back (temp);
    }
    for (int each: motelList)
    {
        dp [each] = -1;
    }
    printf ("%lld\n", numWays (7000));
    return 0;
}
