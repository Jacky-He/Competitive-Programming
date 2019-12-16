#include <bits/stdc++.h>
using namespace std;
int n;
string str;
vector <string> v;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        v.push_back(str);
    }
    sort (v.begin(), v.end(), [] (string s1, string s2) {return s1 + s2 > s2 + s1;});
    string result = "";
    for (int x = 0; x < (int)v.size(); x++)
    {
        cout << v [x];
    }
    cout << endl;
    return 0;
}
