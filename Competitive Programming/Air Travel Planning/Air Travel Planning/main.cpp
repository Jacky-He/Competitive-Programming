#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n;
string from, to;
int weight;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int x = 0; x < 5; x++)
    {
        cin >> n;
        map <string, vector <pair <string, int>>> adj;
        map <string, int> dis;
        for (int y = 0; y < n; y++)
        {
            cin >> from >> to >> weight;
            dis [from] = INF;
            dis [to] = INF;
            adj [from].push_back (make_pair (to, weight));
        }
        queue <string> Q;
        Q.push("YYZ");
        dis ["YYZ"] = 0;
        while (!Q.empty())
        {
            string temp = Q.front();
            Q.pop();
            for (pair <string, int> each: adj [temp])
            {
                if (dis [each.first] > dis [temp] + each.second)
                {
                    dis [each.first] = dis [temp] + each.second;
                    Q.push (each.first);
                }
            }
        }
        cout << dis ["SEA"] << endl;
    }
    return 0;
}
