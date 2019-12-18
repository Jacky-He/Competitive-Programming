#include <bits/stdc++.h>
using namespace std;

int n, num;
vector <int> arr;
int main ()
{
    scanf ("%d", &n);
    int sum = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        sum += num;
        arr.push_back (num);
    }
    sum /= n;
    int result  = 0;
    for (int each: arr)
    {
        if (each < sum)
        {
            result += sum - each;
        }
    }
    printf ("%d\n", result);
    return 0;
}
