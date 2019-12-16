#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string line;
ll hashes1 [1000001];
ll hashes2 [1000001];
ll powers [1000001];
string str1;
string str2;
void computePowers()
{
    powers [1] = 1;
    for (int i = 2; i < 1000001; i++)
    {
        powers [i] = powers [i - 1]*131;
    }
}
int main ()
{
    computePowers();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin >> str1;
    for (int x = 1; x < n; x++)
    {
        cin >> str2;
        
        for (int i = 0; i <= (int)str1.size(); i++)
        {
            hashes1 [i + 1] = str1[i]*powers [i + 1] + hashes1 [i];
        }
        
        int str2size = (int)str2.size();
        char str20 = str2 [0];
        
        for (int i = 0; i <= (int)str2.size(); i++)
        {
            hashes2 [i + 1] = str2[i]*powers [i + 1] + hashes2 [i];
        }
        int resulti = -1;
        for (int index = 0; index < (int)str1.size(); index++)
        {
            if (str1 [index] == str20 && ((int)str1.size() - index) <= str2size)
            {
                ll hash1 = hashes1 [str1.size()] - hashes1 [index];
                ll hash2 = hashes2 [str1.size() - index]*powers [index + 1];
                if (hash1 == hash2)
                {
                    resulti = index;
                    break;
                }
            }
        }
        if (resulti == -1)
        {
            str1 += str2;
        }
        else
        {
            for (int x = (int)str1.size() - resulti + 1; x < (int)str2.size(); x++)
            {
                str1 += str2[x];
            }
        }
    }
    cout << str1 << endl;
    
    return 0;
}
