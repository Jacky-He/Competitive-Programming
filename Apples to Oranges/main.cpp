#include <bits/stdc++.h>
using namespace std;
int n, m;
double weight;
string fruit, from, to;
unordered_map <string, vector <int>> adj;
unordered_map <string, double> dis;
pair <string, double> edges [6001];
bool visited [10001];
queue <string> Q;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie (nullptr);
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> fruit;
        dis [fruit] =  0;
    }
    dis ["APPLES"] = 1.0;
    for (int x = 0; x < m; x++)
    {
        cin >> from >> to >> weight;
        edges [x] = {to, weight};
        adj [from].push_back (x);
    }
    Q.push ("APPLES");
    while (!Q.empty())
    {
        string temp = Q.front();
        Q.pop();
        for (int edge: adj [temp])
        {
            if (dis [temp]*edges [edge].second > dis [edges [edge].first])
            {
                dis [edges [edge].first] = dis [temp]*edges [edge].second;
                Q.push (edges [edge].first);
            }
            if (dis ["APPLES"] > 1.1)
            {
                cout << "YA";
                return 0;
            }
        }
    }
    cout << "NAW";
    return 0;
}