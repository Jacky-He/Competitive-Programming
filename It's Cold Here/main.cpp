#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string input;
    int min = INF;
    string minc;
    int temperature;
    cin >> input >> temperature;
    while (input != "Waterloo")
    {
        if (min > temperature)
        {
            min = temperature;
            minc = input;
        }
        cin >> input >> temperature;
    }
    if (min > temperature)
    {
        min = temperature;
        minc = input;
    }
    cout << minc << endl;
    return 0;
}
