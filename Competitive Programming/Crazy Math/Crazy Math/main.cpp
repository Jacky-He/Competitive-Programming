#include <bits/stdc++.h>
using namespace std;
long long int matrix [2][2] = {{1, 0}, {0, 1}};
void findValue (long long int n)
{
    if (n > 0)
    {
        findValue (n/2);
        long long int a = (matrix [0][0] * matrix [0][0] + matrix [0][1] * matrix [1][0]) % 1000000007;
        long long int b = (matrix [0][0] * matrix [0][1] + matrix [0][1] * matrix [1][1]) % 1000000007;
        long long int c = (matrix [1][0] * matrix [0][0] + matrix [1][1] * matrix [1][0]) % 1000000007;
        long long int d = (matrix [1][0] * matrix [0][1] + matrix [1][1] * matrix [1][1]) % 1000000007;
        matrix [0][0] = a;
        matrix [0][1] = b;
        matrix [1][0] = c;
        matrix [1][1] = d;
    }
    if (n % 2 != 0)
    {
        matrix [1][1] = matrix [0][1] % 1000000007;
        matrix [0][1] = matrix [0][0] % 1000000007;
        matrix [0][0] = (matrix [0][0] + matrix [1][0]) % 1000000007;
        matrix [1][0] = matrix [0][1] % 1000000007;
    }
}
long fib (long long int n)
{
    findValue (n - 1);
    return matrix [0][0];
}

int main ()
{
    
    string line;
    getline (cin, line);
    long long int index = 9;
    long long int number = 0;
    long long int multiplier = 1000000000;
    long long int quotient = 0;
    long long int size = (long long int) line.size();
    if (size > 9)
    {
        for (int x = 0; x < 10; x++)
        {
            number += ((long long int)line.at(x) - 48) * multiplier;
            multiplier /= 10;
        }
        while (index < size)
        {
            long long int something = number / 1000000008;
            number %= 1000000008;
            
            if (index < size - 1)
            {
                number = number * 10 + ((long long int)line.at(index + 1) - 48);
            }
            else if (index == size - 1)
            {
                quotient = something;
            }
            index++;
        }
    }
    else
    {
        multiplier = 1;
        for (long long int x = size - 1; x >= 0; x--)
        {
            number += ((long long int)line.at(x) - 48) * multiplier;
            multiplier *= 10;
        }
    }
    long long int result = fib (number);
    if (quotient % 2 == 0)
    {
        cout << result << endl;
    }
    else
    {
        cout << 1000000007 - result << endl;
    }
    return 0;
}
