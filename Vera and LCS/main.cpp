#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int cnt;
string str;
int freq [2002][26];
int frequency [2002];
int timesfreq [2002];
string result = "";
string liwi = "";
int cnt2 = 0;
int times = 1;
int check ()
{
    for (int x = 0; x < 26; x++)
    {
        //cout << char (x + 'a') << " " << freq [point][x] << endl;
        if (!freq [1][x])
        {
            return x;
        }
    }
    return -1;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k >> str;
    if (k > n)
    {
        cout << "WRONGANSWER\n";
        return 0;
    }
    for (int x = n; x > 0; x--)
    {
        for (int y = 0; y < 26; y++)
        {
            if (str [x - 1] - 'a' == y)
            {
                freq [x][y] = freq [x + 1][y] + 1;
            }
            else
            {
                freq [x][y] = freq [x + 1][y];
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        frequency [x] = freq [x][str [x - 1] - 'a'];
        timesfreq [frequency [x]]++;
    }

    while (cnt < k)
    {
        cnt += timesfreq [times];
        times++;
    }
    times--;
    for (int x = n; x > 0 && cnt2 < k; x--)
    {
        if (frequency [x] <= times)
        {
            result += char (str [x - 1]);
            cnt2++;
        }
    }
    for (int x = (int) result.length() - 1; x >= 0; x--)
    {
        liwi += result [x];
    }
    bool yes = false;
    int i = 0;
    for (int x = 1; x <= n; x++)
    {
        if (i < (int) liwi.length() && str [x - 1] == liwi [i])
        {
            yes = true;
            i++;
            if (i == (int) liwi.length())
            {
                freq [1][str [x - 1] - 'a']--;
                break;
            }
        }
        if (yes)
        {
            freq [1][str [x - 1] - 'a']--;
        }
    }
    int jjjding2 = check ();
    if (jjjding2 == -1)
    {
        cout << "WRONGANSWER\n";
        return 0;
    }
    for (int x = (int) liwi.length(); x < n; x++)
    {
        liwi += char (jjjding2 + 'a');
    }
    cout << liwi << endl;
    return 0;
}