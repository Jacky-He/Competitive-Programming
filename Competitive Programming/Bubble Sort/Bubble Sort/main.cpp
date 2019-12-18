#include <bits/stdc++.h>
using namespace std;
int n;
void print (int blocks [])
{
    for (int x = 0; x < n; x++)
    {
        cout << blocks [x] << " ";
    }
    cout << endl;
}
void swap (int blocks [], int i, int j)
{
    int temp = blocks [i];
    blocks [i] = blocks [j];
    blocks [j] = temp;
}
void bubbleSort (int blocks [])
{
    for (int max = n; max > 0; max--)
    {
        for (int x = 0; x < max - 1; x++)
        {
            if (blocks [x] > blocks [x + 1])
            {
                swap (blocks, x, x + 1);
                print (blocks);
            }
        }
    }
}
int main ()
{
    scanf ("%d", &n);
    int blocks [n];
    for (int index = 0; index < n; index++)
    {
        scanf ("%d", &blocks [index]);
    }
    print (blocks);
    bubbleSort (blocks);
    return 0;
}
