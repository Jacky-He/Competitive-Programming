#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n = 0;
string sub;
ll powers [2000001];
ll hashes [2000001];
unordered_map <ll, ll> numbers;
void computePowers ()
{
    powers [1] = 1;
    for (int x = 2; x < 2000001; x++)
    {
        powers [x] = powers [x - 1]*131;
    }
}
void computeHashes (string substring)
{
    hashes [0] = 0;
    for (int index = 1; index <= (int)substring.size(); index++)
    {
        hashes [index] = substring [index - 1]*powers [index] + hashes [index - 1];
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    computePowers();
    ll result = 0;
    for (int x = 0; x < n; x++)
    {
        cin >> sub;
        computeHashes (sub);
        ll m = 0;
        for (int i = 1; i <= (int)sub.size(); i++)
        {
            if (hashes [i]*powers [(int)sub.size() - i + 1] == hashes [(int)sub.size()] - hashes [(int)sub.size() - i])
            {
                m = max(m, numbers [hashes [i]]);
            }
        }
        numbers [hashes [(int)sub.size()]] = m + 1;
        result = max (result, numbers [hashes [(int)sub.size()]]);
    }
    cout << result << endl;
    return 0;
}
