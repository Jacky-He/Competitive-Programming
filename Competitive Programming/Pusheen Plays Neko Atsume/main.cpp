#include <bits/stdc++.h>
using namespace std;
int n;
string str;
unordered_map <string, int> lookup;
unordered_map <int, string> lookup2;
int stuff [5];
vector <pair <int, int>> v;
bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return (p1.second > p2.second) || (p1.second == p2.second && p1.first < p2.first);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie (NULL);
    cin >> n;
    lookup ["Deluxe Tuna Bitz"] = 1;
    lookup ["Bonito Bitz"] = 2;
    lookup ["Sashimi"] = 3;
    lookup ["Ritzy Bitz"] = 4;
    lookup2 [1] ="Deluxe Tuna Bitz";
    lookup2 [2] = "Bonito Bitz";
    lookup2 [3] ="Sashimi";
    lookup2 [4] = "Ritzy Bitz";
    getline (cin, str);
    while (n--)
    {
        getline (cin, str);
        stuff [lookup [str]]++;
    }
    for (int x = 1; x < 5; x++)
    {
        if (stuff [x] != 0)
        {
            v.push_back ({x, stuff [x]});
        }
    }
    sort (v.begin(), v.end(), cmp);
    for (pair <int, int> each: v)
    {
        cout << lookup2 [each.first] << " " << each.second << "\n";
    }
    return 0;
}
