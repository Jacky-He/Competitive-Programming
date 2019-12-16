#include <bits/stdc++.h>
using namespace std;
bool possible [5][2];
void check (char c1, char c2, int index)
{
    if (c1 - 'a' >= 0 && c2 - 'a' >= 0)
    {
        possible [index][1] = true; //homozygous recessive
    }
    else
    {
        possible [index][0] = true; //dominant
    }
}
bool see (string str)
{
    for (int x = 0; x < 5; x++)
    {
        if (str [x] - 'a' >= 0) //lowercase
        {
            if (!possible [x][1])
            {
                return false;
            }
        }
        else //uppercase
        {
            if (!possible [x][0])
            {
                return false;
            }
        }
    }
    return true;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string father, mother;
    int testcase;
    cin >> father >> mother;
    for (int x = 0; x < 10; x += 2)
    {
        check (father [x], mother [x], x/2);
        check (father [x], mother [x + 1], x/2);
        check (father [x + 1], mother [x], x/2);
        check (father [x + 1], mother [x + 1], x/2);
    }
    cin >> testcase;
    string str;
    for (int x = 0; x < testcase; x++)
    {
        cin >> str;
        if (see (str))
        {
            printf ("Possible baby.\n");
        }
        else
        {
            printf ("Not their baby!\n");
        }
    }
    return 0;
}
