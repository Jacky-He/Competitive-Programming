#include <bits/stdc++.h>
using namespace std;
int wordsfirst, wordsecond;
string array1 [501];
string array2 [11];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int days;
    cin >> days;
    for (int x = 0; x < days; x++)
    {
        cin >> wordsfirst;
        for (int y = 0; y < wordsfirst; y++)
        {
            cin >> array1 [y];
        }
        cin >> wordsecond;
        for (int y = 0; y < wordsecond; y++)
        {
            cin>> array2[y];
        }
        bool match = false;
        for (int index = 0; index < wordsfirst; index++)
        {
            int counter = 0;
            for (int i2 = 0, another2 = index; i2 < wordsecond && another2 < wordsfirst; i2++, another2++)
            {
                if (array1 [another2] == array2 [i2] || array2[i2].find("na") != string::npos)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            if (counter == wordsecond)
            {
                match = true;
                break;
            }
        }
        if (match)
        {
            printf("Yes\n");
        }
        else
        {
            printf ("No\n");
        }
    }
    return 0;
}
