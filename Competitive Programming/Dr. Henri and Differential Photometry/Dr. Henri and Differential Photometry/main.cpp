#include <bits/stdc++.h>
using namespace std;
int K;
double current;
int num;
double temp;
int main ()
{
    cin >> K;
    cin >> current;
    double totalSum = 0;
    double currentSum = current;
    for (int x = 0; x < K; x++)
    {
        currentSum = current;
        cin >> num;
        for (int y = 0; y < num; y++)
        {
            cin >> temp;
            currentSum += temp;
        }
        totalSum += currentSum;
    }
    printf ("%f\n", totalSum/K);
    return 0;
}
