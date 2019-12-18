#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
int width;
int height;
bool bit;
int main ()
{
    scanf ("%d", &width);
    scanf ("%d", &height);
    for (int x = 0; x < height; x++)
    {
        if (x % 2 == 0)
        {
            bit = 0;
        }
        else
        {
            bit = 1;
        }
        for (int y = 0; y < width; y++)
        {
            cout << bit;
            bit = !bit;
        }
        printf("\n");
    }
    return 0;
}
