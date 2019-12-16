#include <bits/stdc++.h>
using namespace std;
unordered_set <int> nums;
int n;
int input;
int main ()
{
    scanf ("%d", &n);
    while (n--)
    {
        scanf ("%d", &input);
        nums.insert (input);
    }
    printf ("%d\n", (int)nums.size());
    return 0;
}
