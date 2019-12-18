#include <utility>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int cnt [5];
int n, num;
int result;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        cnt [num]++;
    }
    result += cnt [4];
    result += cnt [3];
    cnt [1] = cnt [3] > cnt [1]? 0: cnt [1] - cnt [3];
    result += cnt [2]/2;
    cnt [2] %= 2;
    result += cnt [1]/4;
    cnt [1] %= 4;
    if (cnt [2] == 1 && cnt [1] == 3)
    {
        result += 2;
    }
    else if (cnt [2] != 0 || cnt [1] != 0)
    {
        result++;
    }
    printf ("%d\n", result);
    return 0;
}