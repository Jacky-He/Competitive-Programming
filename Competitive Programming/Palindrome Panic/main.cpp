#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
string line;
int size;
ll hashesforward [1000001];
ll hashesbackward [1000001];
ll powers [1000001];
void computePowers ()
{
    powers [0] = 1;
    for (int index = 1; index < size; index++)
    {
        powers [index] = powers [index - 1] * 31;
    }
}
void usehash ()
{
    hashesforward [0] = 0;
    hashesbackward [0] = 0;
    for (int index = 1; index <= size; index++)
    {
        hashesforward [index] = line.at(index - 1)* powers [index - 1] + hashesforward [index - 1];
    }
    for (int index = size - 1, index2 = 1; index >= 0; index--, index2++)
    {
        hashesbackward [index2] = line.at(index)* powers [index2 - 1] + hashesbackward [index2 - 1];
    }
    return;
}
bool isPalindrome (int i, int j)
{
    if ((j - i) % 2 == 0) //odd size
    {
        int i2 = (i + j)/2;
        int j2 = (i + j)/2 + 2;
        int j2mirror = size + 1 - j2;
        int jmirror = size - j;
        ll firstsubhash = 0, secondsubhash = 0;
        if (i < jmirror - 1)
        {
            firstsubhash = (hashesforward [i2] - hashesforward [i]) * powers [jmirror - 1 - i];
            secondsubhash = hashesbackward [j2mirror] - hashesbackward [jmirror - 1];
        }
        else
        {
            firstsubhash = hashesforward [i2] - hashesforward [i];
            secondsubhash = (hashesbackward [j2mirror] - hashesbackward [jmirror - 1])*powers [i - (jmirror - 1)];
        }
        if (firstsubhash == secondsubhash)
        {
            return true;
        }
    }
    else    //even size
    {
        int i2 = (i + j - 1)/2 + 1;
        int j2 = (i + j + 1)/2 + 1;
        int j2mirror = size + 1 - j2;
        int jmirror = size - j;
        ll firstsubhash = 0, secondsubhash = 0;
        if (i < jmirror - 1)
        {
            firstsubhash = (hashesforward [i2] - hashesforward [i]) * powers [jmirror - 1 - i];
            secondsubhash = hashesbackward [j2mirror] - hashesbackward [jmirror - 1];
        }
        else
        {
            firstsubhash = hashesforward [i2] - hashesforward [i];
            secondsubhash = (hashesbackward [j2mirror] - hashesbackward [jmirror - 1])*powers [i - (jmirror - 1)];
        }
        if (firstsubhash == secondsubhash)
        {
            return true;
        }
    }
    return false;
}
int main ()
{
    for (int x = 0; x < 10; x++)
    {
        getline (cin, line);
        size = (int) line.size();
        computePowers();
        usehash ();
        char first = line.at(0);
        char last = line.at (size - 1);
        int palF = 0;
        int palB = 0;
        for (int index = size - 1; index > 0; index--)
        {
            
            if (line.at (index) == first)
            {
                if (isPalindrome (0, index))
                {
                    palF = index + 1;
                    break;
                }
            }
        }
        for (int index = 0; index < size - 1; index++)
        {
            if (line.at(index) == last)
            {
                if (isPalindrome (index, size - 1))
                {
                    palB = size - index;
                    break;
                }
            }
        }
        if (palF == 0 && palB == 0)
        {
            cout << size - 1 << endl;
        }
        else
        {
            cout << size - max (palF, palB) << endl;
        }
    }
    return 0;
}
