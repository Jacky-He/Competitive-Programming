#include <bits/stdc++.h>
using namespace std;
unsigned int n;
string str1, str2;
bitset <2001>* nu1;
bitset <2001>* nu2;
bitset <2001>* original;
bool solve ()
{
    bool flipped = true;
    while (flipped)
    {
        flipped = false;
        for (unsigned int x = n - 1; x > 0; x--)
        {
            if (nu1 -> test (x) != nu2 -> test (x))
            {
                for (unsigned int y = x; y > 0; y--)
                {
                    if (nu1 -> test (y) == nu1 -> test (y - 1))
                    {
                        nu1 -> flip (y);
                        nu1 -> flip (y - 1);
                        flipped = true;
                    }
                }
            }
        }
    }
    return (*nu1) == (*nu2);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> str1 >> str2;
    for (unsigned int x = 0; x < n; x++)
    {
        str1 [x] = char((str1 [x] == 'A') + '0');
        str2 [x] = char((str2 [x] == 'A') + '0');
    }
    nu1 = new bitset <2001> (str1);
    original = new bitset <2001> (str1);
    nu2 = new bitset <2001> (str2);
    cout << (solve () ? "YES" : "NO");
    return 0;
}