#include <bits/stdc++.h>
using namespace std;
int A, B;
int amounts [1001];
int main ()
{
    int C;
    scanf ("%d%d%d", &A, &B, &C);
    memset (amounts, -1, sizeof(amounts));
    amounts [A] = A;
    amounts [B] = B;
    for (int x = 0; x <= C; x++)
    {
        if (x < A && x < B)
        {
            amounts [x] = 0;
        }
        else if (x < A)
        {
            amounts [x] = B + amounts [x - B];
        }
        else if (x < B)
        {
            amounts [x] = A + amounts [x - A];
        }
        else
        {
            amounts [x] = max (A + amounts [x - A], B + amounts [x - B]);
        }
    }
    cout << amounts [C] << endl;
    return 0;
}
