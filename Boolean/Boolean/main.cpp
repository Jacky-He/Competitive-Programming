#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, const char * argv[])
{
    int numNots = 0;
    string input;
    while (input != "True" && input != "False")
    {
        cin >> input;
        if (input == "not")
        {
            numNots++;
        }
    }
    if (input == "True")
    {
        if (numNots % 2 == 0)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    else if (input == "False")
    {
        if (numNots % 2 == 0)
        {
            cout << "False" << endl;
        }
        else
        {
            cout << "True" << endl;
        }
    }
    return 0;
}
