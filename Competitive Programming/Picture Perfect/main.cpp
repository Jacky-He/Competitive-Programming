#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int area = 1;
int smallerlength;
int biggerlength;
int perimeter;
int main ()
{
    for (;;)
    {
        scanf ("%d", &area);
        if (area == 0)
        {
            break;
        }
        smallerlength = (int) sqrt (area);
        while (area % smallerlength != 0)
        {
            smallerlength --;
        }
        biggerlength = area / smallerlength;
        perimeter = (biggerlength + smallerlength)*2;
        cout << "Minimum perimeter is " << perimeter << " with dimensions " << smallerlength << " x " << biggerlength << endl;
    }
    return 0;
}
