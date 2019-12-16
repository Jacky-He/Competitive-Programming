#include <bits/stdc++.H>
typedef long long int ll;
using namespace std;
int n;
string line;
ll powers [200001];
ll hashes [200001];
void computePowers ()
{
    powers [1] = 1;
    for (int x = 2; x < 200001; x++)
    {
        powers [x] = powers [x - 1]*131;
    }
}
void computeHashes (string substring)
{
    for (int index = 1; index <= (int)substring.size(); index++)
    {
        hashes [index] = substring [index - 1]*powers [index] + hashes [index - 1];
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> line;
    computePowers();
    computeHashes (line);
    int count = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = x; y <= n; y++)
        {
            int templength = y - x + 1;
            ll temphash = (hashes [y] - hashes [x - 1])*powers [n - templength - x + 2];
            ll hash1 = hashes [templength]*powers [n - templength + 1];
            ll hash2 = hashes [n] - hashes [n - templength];
            if (temphash == hash1 && temphash == hash2)
            {
                count++;
            }
        }
    }
    printf ("%d\n", count);
    return 0;
}
