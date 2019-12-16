#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long int ll;
using namespace std;
int n, k, value;
struct liwiDeque
{
    deque <pair <int, int>> mono; //first: value, second: index
    bool minormax = false;  //min: false, max: true
    void push (int val, int index)
    {
        while (!mono.empty() && (minormax? mono.back().first < val : mono.back().first > val))
        {
            mono.pop_back();
        }
        mono.push_back ({val, index});
    }
    pair <int, int> getFront ()
    {
        return mono.front();
    }
    void pop ()
    {
        mono.pop_front();
    }
};
int main ()
{
    scanf ("%d%d", &n, &k);
    ll i = 1, j = 1;
    ll cnt = 0;
    ll lastj = 0;
    liwiDeque minDeque, maxDeque;
    minDeque.minormax = false;
    maxDeque.minormax = true;
    scanf ("%d", &value);
    minDeque.push (value, 1);
    maxDeque.push (value, 1);
    while (j <= n)
    {

        pair <int, int> curr = {minDeque.getFront().first, maxDeque.getFront().first};
        if (curr.second - curr.first <= k)
        {
            cnt += ((j - i + 1) + 1)*(j - i + 1)/2;
            if (lastj >= i && lastj <= j)
            {
                cnt -= ((lastj - i + 1) + 1)*(lastj - i + 1)/2;
            }
            lastj = j;
            j++;
            if (j <= n)
            {
                scanf ("%d", &value);
                minDeque.push (value, j);
                maxDeque.push (value, j);
            }
        }
        else
        {
            i++;
            while (!minDeque.mono.empty() && minDeque.getFront().second < i)
            {
                minDeque.pop();
            }
            while (!maxDeque.mono.empty() && maxDeque.getFront().second < i)
            {
                maxDeque.pop();
            }
        }
    }
    printf ("%lld\n", cnt);
    return 0;
}
