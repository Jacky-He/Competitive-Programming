#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
void update (bool boolArray [])
{
    int index;
    int length;
    cin >> index;
    cin >> length;
    for (int n = index, j = index + length - 1; n <= (index + length)/2 && j >= (index + length)/2; n++, j--)
    {
        if (boolArray [n]^boolArray[j])
        {
            boolArray [n] = !(boolArray [n]);
            boolArray[j] = !(boolArray[j]);
        }
    }
}
void queries (bool boolArray [])
{
    bool* boolPointer = boolArray;
    int index;
    int length;
    cin >> index;
    cin >> length;
    int max = 0;
    int counter = 0;
    for (int n = index; n < index + length; n++)
    {
        if (*(boolPointer + n))
        {
            counter++;
        }
        else
        {
            if (counter > max)
            {
                max = counter;
            }
            counter = 0;
        }
    }
    if (counter > max)
    {
        max = counter;
    }
    cout << max << endl;
}
int main()
{
    int substringLength;
    int numOperations;
    string binaryString;
    cin >> substringLength;
    cin >> numOperations;
    bool boolArray [substringLength];
    cin >> binaryString;
    for (int index = 0; index < substringLength; index++)
    {
        if (binaryString.at(index) == '0')
        {
            boolArray [index] = 0;
        }
        else
        {
            boolArray [index] = 1;
        }
    }
    for (int num = 0; num < numOperations; num++)
    {
        int operation;
        cin >> operation;
        if (operation == 1)
        {
            update (boolArray);
        }
        else if (operation == 2)
        {
            queries (boolArray);
        }
    }
    return 0;
}
