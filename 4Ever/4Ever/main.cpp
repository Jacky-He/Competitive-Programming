#include <cstdio>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main()
{
    map <int, int> reference;
    reference [1] = 3;    reference [11] = 6;   reference [30] = 6;
    reference [2] = 3;    reference [12] = 6;   reference [40] = 5;
    reference [3] = 5;    reference [13] = 8;   reference [50] = 5;
    reference [4] = 4;    reference [14] = 8;   reference [60] = 5;
    reference [5] = 4;    reference [15] = 7;   reference [70] = 7;
    reference [6] = 3;    reference [16] = 7;   reference [80] = 6;
    reference [7] = 5;    reference [17] = 9;   reference [90] = 6;
    reference [8] = 5;    reference [18] = 8;   reference [100] = 7;
    reference [9] = 4;    reference [19] = 8;   reference [1000] = 8;       reference [0] = 0;
    reference [10] = 3;   reference [20] = 6;   reference [1000000] = 7;    reference [1000000000] = 7;
    
    int num;
    cin >> num;
    while (num != 4)
    {
        int length = 0;
        int counter = 0;
        int zerosThousands = 0;
        int zerosMillions = 0;
        int previousLength = 0;
        int previousDigit = 0;
        while (num != 0)
        {
            counter++;
            int digit = num % 10;
            num /= 10;
            switch (counter)
            {
                case 1:
                    length += reference [digit];
                    previousLength = reference [digit];
                    previousDigit = digit;
                    break;
                case 2:
                    if (digit != 1)
                    {
                        length += reference [digit*10];
                    }
                    else
                    {
                        length -= previousLength;
                        length += reference [previousDigit + 10];
                    }
                    break;
                case 3:
                    if (digit != 0)
                    {
                        length += reference [digit] + reference [100];
                    }
                    break;
                case 4:
                    if (digit != 0)
                    {
                        length += reference [digit] + reference [1000];
                    }
                    else
                    {
                        zerosThousands++;
                    }
                    previousLength = reference [digit];
                    previousDigit = digit;
                    break;
                case 5:
                    if (digit != 0)
                    {
                        if (zerosThousands == 1)
                        {
                            length += reference [1000];
                        }
                        if (digit != 1)
                        {
                            length += reference [digit*10];
                        }
                        else
                        {
                            length -= previousLength;
                            length += reference [previousDigit + 10];
                        }
                    }
                    else
                    {
                        zerosThousands++;
                    }
                    break;
                case 6:
                    if (digit != 0)
                    {
                        if (zerosThousands == 2)
                        {
                            length += reference [digit] + reference [100] + reference [1000];
                        }
                        else
                        {
                            length += reference [digit] + reference [100];
                        }
                    }
                    break;
                case 7:
                    if (digit != 0)
                    {
                        length += reference [digit] + reference [1000000];
                    }
                    else
                    {
                        zerosMillions++;
                    }
                    previousLength = reference [digit];
                    previousDigit = digit;
                    break;
                case 8:
                    if (digit != 0)
                    {
                        if (zerosMillions == 1)
                        {
                            length += reference [1000000];
                        }
                        if (digit != 1)
                        {
                            length += reference [digit*10];
                        }
                        else
                        {
                            length -= previousLength;
                            length += reference [previousDigit + 10];
                        }
                    }
                    else
                    {
                        zerosMillions++;
                    }
                    break;
                case 9:
                    if (digit != 0)
                    {
                        if (zerosMillions == 2)
                        {
                            length += reference [digit] + reference [100] + reference [1000000];
                        }
                        else
                        {
                            length += reference [digit] + reference [100];
                        }
                    }
                    break;
                case 10:
                    length += reference [digit] + reference [1000000000];
                    break;
            }
        }
        cout << length << endl;
        num = length;
    }
    return 0;
}
