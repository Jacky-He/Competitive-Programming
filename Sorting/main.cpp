#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
int main ()
{
    int a, b, c;
    scanf ("%d%d%d", &a, &b, &c);
    if (a <= b && b <= c)
    {
        cout << "Good job!" << endl;
    }
    else
    {
        cout << "Try again!" << endl;
    }
    return 0;
}
