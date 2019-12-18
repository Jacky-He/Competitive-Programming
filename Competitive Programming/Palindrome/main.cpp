#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
string input;
bool isAPalindrome (int index1, int index2)
{
    for (int first = index1, second = index2; first <= second; first++, second--)
    {
        if (input.at(first) != input.at(second))
        {
            return false;
        }
    }
    return true;
}
int main ()
{
    getline (cin, input);
    int length = 0;
    int size = (int) input.size();
    bool something = true;
    for (int index = 0; index < size && something; index++)
    {
        for (int index2 = size - 1; index2 >= index; index2--)
        {
            if (input.at(index) == input.at (index2))
            {
                if (isAPalindrome (index, index2))
                {
                    int templength = index2 - index + 1;
                    if (templength > length)
                    {
                        length = templength;
                    }
                    break;
                }
            }
            
        }

    }
    cout << length << endl;
    return 0;
}
