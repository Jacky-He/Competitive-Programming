#include <bits/stdc++.h>
using namespace std;
int floors, movetime, passengers;
int t, start, finish;
int main ()
{
    scanf ("%d%d%d", &floors, &movetime, &passengers);
    int sum = 0;
    for (int x = 0; x < passengers; x++)
    {
        scanf ("%d%d%d", &t, &start, &finish);
        int waittime = 0;
        if (start > finish)       // going down
        {
            if (t/movetime/floors%2 == 0) //elevator going up
            {
                waittime = floors*movetime - t%(floors*movetime) + (floors-start)*movetime;
            }
            else   //elevator going down
            {
                if (t%(floors*movetime) > (floors - start)*movetime)
                {
                    waittime = floors*movetime*2 - (t%(floors*movetime) - (floors - start)*movetime);
                }
                else
                {
                    waittime = (floors - start)*movetime - t%(floors*movetime);
                }
            }
        }
        else if (start < finish)  // going up
        {
            if (t/movetime/floors%2 == 0) //elevator going up
            {
                if (t%(floors*movetime) > start*movetime)
                {
                    waittime = floors*movetime*2 - (t%(floors*movetime) - start*movetime);
                }
                else
                {
                    waittime = start*movetime - t%(floors*movetime);
                }
            }
            else //elevator going down
            {
                waittime = floors*movetime - t%(floors*movetime) + start*movetime;
            }
        }
        sum += waittime + abs(finish - start)*movetime;
    }
    printf ("%d\n", sum);
    return 0;
}
