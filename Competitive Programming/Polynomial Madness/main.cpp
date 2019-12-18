#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main ()
{
    int n;
    int degree = 0;
    scanf ("%d", &n);
    ll polynomial [10];
    set <int> PRRlast;
    vector <int> results;
    bool found = false;
    ll sum = 0;
    while (n--)
    {
        scanf ("%d", &degree);
        for (int x = 0; x <= degree; x++)
        {
            scanf ("%lld", &polynomial [x]);
        }
        while (polynomial [degree] == 0)
        {
            results.push_back (0);
            degree--;
        }
        while (degree > 0)
        {
            found = false;
            for (int x = 1; x <= abs(polynomial [degree]); x++)  //Find factors of last term
            {
                if (polynomial [degree] % x == 0)
                {
                    PRRlast.insert (x);
                    PRRlast.insert (0-x);
                    sum = 0;
                    int power = degree;
                    for (int i = 0; i <= degree; i++)
                    {
                        sum += polynomial [i]*pow(x, power);
                        power--;
                    }
                    if (sum == 0) //If works
                    {
                        ll temp = polynomial [0];
                        for (int i = 0; i < degree; i++)
                        {
                            polynomial [i] = temp;
                            temp = x*polynomial [i] + polynomial [i + 1];
                        }
                        results.push_back (x);
                        found = true;
                        break;
                    }
                    else
                    {
                        sum = 0;
                        int power = degree;
                        for (int i = 0; i <= degree; i++)
                        {
                            sum += polynomial [i]*pow(0 -x, power);
                            power--;
                        }
                        if (sum == 0) //If works
                        {
                            ll temp = polynomial [0];
                            for (int i = 0; i < degree; i++)
                            {
                                polynomial [i] = temp;
                                temp = (0 - x)*polynomial [i] + polynomial [i + 1];
                            }
                            results.push_back (0 - x);
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found == true)
            {
                degree--;
                PRRlast.clear();
                continue;
            }
            for (int x = 1; x <= abs(polynomial [0]); x++)  //Find PRRs
            {
                if (polynomial [0] % x == 0)
                {
                    for (int each: PRRlast)
                    {
                        if (each % x == 0)
                        {
                            sum = 0;
                            int power = degree;
                            for (int i = 0; i <= degree; i++)
                            {
                                sum += polynomial [i]*pow(each/x, power);
                                power--;
                            }
                            if (sum == 0) //If works
                            {
                                ll temp = polynomial [0];
                                for (int i = 0; i < degree; i++)
                                {
                                    polynomial [i] = temp;
                                    temp = (each/x)*polynomial [i] + polynomial [i + 1];
                                }
                                results.push_back (each/x);
                                found = true;
                                break;
                            }
                            else
                            {
                                sum = 0;
                                int power = degree;
                                for (int i = 0; i <= degree; i++)
                                {
                                    sum += polynomial [i]*pow(0 - each/x, power);
                                    power--;
                                }
                                if (sum == 0) //If works
                                {
                                    ll temp = polynomial [0];
                                    for (int i = 0; i < degree; i++)
                                    {
                                        polynomial [i] = temp;
                                        temp = (0 - each/x)*polynomial [i] + polynomial [i + 1];
                                    }
                                    results.push_back (0 - each/x);
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (found)
                {
                    break;
                }
            }
            degree--;
            PRRlast.clear();
        }
        sort (results.begin(), results.end());
        for (int x = 0; x < (int)results.size() - 1; x++)
        {
            printf ("%d ", results [x]);
        }
        printf ("%d", results [results.size() - 1]);
        printf ("\n");
        results.clear();
    }
    return 0;
}
