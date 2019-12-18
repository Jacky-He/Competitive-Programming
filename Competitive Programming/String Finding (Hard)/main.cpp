#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string str1;
int sizestr1;
string str2;
ll hashes [1000001];
ll powers [1000001];
void computePowers ()
{
    powers [1] = 1;
    for (int index = 2; index < sizestr1; index++)
    {
        powers [index] = powers [index - 1]*31;
    }
    return;
}
ll gethash (string str)
{
    ll hash = 0;
    for (int index = 0; index < (int) str.length(); index++)
    {
        hash += str [index]*powers[index + 1];
    }
    return hash;
}
void gethashes ()
{
    for (int index = 1; index < sizestr1; index++)
    {
        hashes [index] = str1 [index]*powers [index] + hashes [index - 1];
    }
}
int main ()
{
    getline (cin, str1);
    getline (cin, str2);
    str1 = "#" + str1;
    sizestr1 = (int) str1.size();
    computePowers();
    ll hashstr2 = gethash (str2);
    gethashes();
    int sublength = (int) str2.size();
    int result = -1;
    for (int index = 1, j = sublength; index < sizestr1 && j < sizestr1; index++, j++)
    {
        ll subhash = hashes [j] - hashes [index - 1];
        ll subhash2 = hashstr2*powers [index];
        if (subhash == subhash2)
        {
            result = index - 1;
            break;
        }
    }
    cout << result << endl;
    return 0;
}
