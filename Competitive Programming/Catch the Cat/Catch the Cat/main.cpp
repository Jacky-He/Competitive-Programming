#include <bits/stdc++.h>
using namespace std;
bool reached [1000000];
vector <int> levels [1000000];
int main ()
{
    int start, finish;
    scanf ("%d%d", &start, &finish);
    levels [0].push_back (start);
    int index = 0;
    bool something = true;
    while (something)
    {
        for (int each : levels [index])
        {
            if (each == finish)
            {
                cout << index << endl;
                something = false;
                break;
            }
            else
            {
                if (!reached [each - 1] && each - 1 >= 0)
                {
                    levels [index + 1].push_back (each - 1);
                    reached [each - 1] = 1;
                    if (each - 1 == finish)
                    {
                        cout << index + 1 << endl;
                        something = false;
                        break;
                    }
                }
                if (!reached [each + 1] && each + 1 >= 0)
                {
                    levels [index + 1].push_back (each + 1);
                    reached [each + 1] = 1;
                    if (each + 1 == finish)
                    {
                        cout << index + 1 << endl;
                        something = false;
                        break;
                    }
                }
                if (!reached [each*2] && each*2 >= 0 && each <= 100000)
                {
                    levels [index + 1].push_back (each*2);
                    reached [each*2] = 1;
                    if (each*2 == finish)
                    {
                        cout << index + 1 << endl;
                        something = false;
                        break;
                    }
                }
            }
        }
        index++;
    }
    return 0;
}
