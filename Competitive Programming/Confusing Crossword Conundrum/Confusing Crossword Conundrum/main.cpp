#include <bits/stdc++.h>
using namespace std;
map <string, vector<string>> adj;
int n, m, q;
string str, str1, str2;

queue <string> Q;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> q;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
    }
    for (int x = 0; x < m; x++)
    {
        cin >> str1 >> str2;
        adj [str1].push_back (str2);
        adj [str2].push_back (str1);
    }
    for (int x = 0; x < q; x++)
    {
        cin >> str1 >> str2;
        map <string, bool> visited;
        map <string, int> dis;
        set <string> visitedset;
        Q.push (str1);
        dis [str1] = 0;
        visited [str1] = true;
        visitedset.insert (str1);
        pair <int, string> minimum = {0x3f3f3f3f, "ZZZZZZZZZZZZ"};
        if (str1 [0] == str2 [0])
        {
            minimum = {0, str1};
        }
        while (!Q.empty())
        {
            string temp = Q.front();
            Q.pop();
            for (string each: adj [temp])
            {
                if (!visited [each])
                {
                    visited [each] = true;
                    dis [each] = dis [temp] + 1;
                    
                    Q.push (each);
                    if (each [0] == str2 [0])
                    {
                        pair <int, string> p = {dis [each], each};
                        if (minimum > p)
                        {
                            minimum = p;
                        }
                    }
                }
            }
        }
        if (minimum.first == 0x3f3f3f3f && minimum.second == "ZZZZZZZZZZZZ")
        {
            cout << -1 << endl;
        }
        else
        {
            cout << minimum.second << endl;
        }
    }
    return 0;
}




