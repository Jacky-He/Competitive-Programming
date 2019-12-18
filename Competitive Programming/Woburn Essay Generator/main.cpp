#include <bits/stdc++.h>
using namespace std;
set <string> outputed [1001];
char toChar (int something)
{
    return something + 'a';
}
int main ()
{
    int w;
    scanf ("%d", &w);
    int length = 1;
    for (int y = 0; y < 26; y++)
    {
        if (w == 0)
        {
            break;
        }
        string something = " ";
        something [0]= toChar (y);
        cout << something << " ";
        outputed [1].insert (something);
        w--;
    }
    while (w > 0)
    {
            for (int x = 0; x < 26; x++)
            {
                if (w == 0)
                {
                    break;
                }
                for (string each: outputed [length - 1])
                {
                    if (w == 0)
                    {
                        break;
                    }
                    string hi = toChar (x) + each;
                    cout << hi << " ";
                    outputed [length].insert (hi);
                    w--;
                }
            }
        length++;
    }
    return 0;
}
