#include <bits/stdc++.h>
using namespace std;
int main ()
{
    char something [101];
    int a, b;
    scanf ("%d%d", &a, &b);
    for (int index = 0; index < 101; index++)
    {
        if (index <= 59)
        {
            something [index] = 'F';
        }
        else if (index <= 69)
        {
            something [index] = 'D';
        }
        else if (index <= 79)
        {
            something [index] = 'C';
        }
        else if (index <= 89)
        {
            something [index] = 'B';
        }
        else
        {
            something [index] = 'A';
        }
    }
    if (something [a] == something [b])
    {
        printf ("Same\n");
    }
    else
    {
        printf ("Different\n");
    }
    return 0;
}
