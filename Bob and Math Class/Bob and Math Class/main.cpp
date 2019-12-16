#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
ll powers [1000001];
ll somethinghash [1000001];
char TT [1000001];
char FF [1000001];
ll TThash [1000001];
ll FFhash [1000001];
void computePowers ()
{
    powers [1] = 1;
    for (int index = 2; index < 1000001; index++)
    {
        powers [index] = (powers [index - 1]*131);
    }
}
int main ()
{
    int n;
    computePowers();
    string something;
    cin >> n;
    cin >> something;
    memset (TT, 'T', sizeof (TT));
    memset (FF, 'F', sizeof (FF));
    for (int index = 1; index < 1000001; index++)
    {
        TThash [index] = TThash [index - 1] + TT [index - 1]*powers [index];
        FFhash [index] = FFhash [index - 1] + FF [index - 1]*powers [index];
    }
    for (int index = 1; index <= (int) something.size(); index++)
    {
        somethinghash [index] = somethinghash [index - 1] + something [index - 1]*powers [index];
    }
    int counter = 0;
    for (int substringlength = 1; substringlength <= (int)something.size(); substringlength++)
    {
        ll tt = 0, ff = 0;
        int length = 0;
        if (substringlength % 2== 0)
        {
            tt = TThash [substringlength/2];
            ff = FFhash [substringlength/2];
            length = substringlength/2;
        }
        else
        {
            tt = TThash [substringlength/2 + 1];
            ff = FFhash [substringlength/2 + 1];
            length = substringlength/2 + 1;
        }
        for (int start = 0, finish = substringlength - 1; finish < (int)something.size(); start++, finish++)
        {
            for (int begin = start, end = begin + length - 1; end <= finish; begin++, end++)
            {
                ll hash = somethinghash [end + 1] - somethinghash [begin];
                if (tt*powers [begin + 1]== hash || ff*powers [begin + 1] == hash)
                {
                    counter++;
                    break;
                }
            }
        }
    }
    cout << counter << endl;
    return 0;
}
