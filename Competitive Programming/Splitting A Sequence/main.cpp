#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, m;
    scanf ("%d%d", &n, &m);
    int array [n];
    int input;
    int min = 0;
    int max = 0;
    int check = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &input);
        if (input > min)
        {
            min = input;
        }
        array [x] = input;
        max += input;
    }
    while (min != max)
    {
        check = (min + max)/2;
        int index = 0;
        int copym = m;
        int counter = 0;
        while (copym != 0)
        {
            int sum = 0;
            while (sum <= check && index < n)
            {
                if (array [index] + sum <= check)
                {
                    counter++;
                    sum += array [index];
                    index++;
                }
                else
                {
                    break;
                }
            }
            copym--;
        }
        if (counter < n)
        {
            if (min == check)
            {
                min = max;
            }
            else
            {
                min = check;
            }
        }
        else
        {
            max = check;
        }
    }
    printf ("%d\n", min);
    return 0;
}
