#include <utility>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <unordered_set>
#define INF 0x3f3f3f3f
typedef long long int ll;
using namespace std;

int n;
string str;
unordered_set <string> dictionary;
int dp [2010];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        dictionary.insert (str);
    }
    for (int x = 0; x < 10; x++)
    {
        memset (dp, 0x3f, sizeof (dp));
        dp [0] = 0;
        cin >> str;
        for (int i = 1; i <= (int) str.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp [j] != INF && dictionary.count(str.substr (j, i - j)))
                {
                    dp [i] = min (dp [j] + 1, dp [i]);
                }
            }
        }
        cout << dp [str.size()] - 1 << endl;
    }
    return 0;
}