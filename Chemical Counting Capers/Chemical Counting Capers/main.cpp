#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long int ll;
using namespace std;
ll n;
string line;
string trimmed;
vector <string> component;
map <string, ll> freq;
stack <ll> multipliers;
bool isNumber (char c)
{
    return '0' <= c && c <= '9';
}
bool isLetter (char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
int main ()
{
    scanf ("%lld", &n);
    getline (cin, line);
    getline (cin, line);
    int cnt = 0;
    string temp = "";
    for (int x = 0; x < line.length(); x++)
    {
        if (line [x] == ' ')
        {
            component.push_back (temp);
            temp = "";
            cnt++;
        }
        else
        {
            temp += line [x];
        }
    }
    
    component.push_back (temp);
    multipliers.push(1);
    for (int x = cnt; x >= 0; x--)
    {
        if (isNumber(component [x][0]))
        {
            if (isLetter (component [x - 1][0]))
            {
                freq [component [x - 1]] = (freq [component [x - 1]] + multipliers.top()* ll(stoi(component [x]))%MOD)%MOD;
            }
            else if (component [x - 1] == ")")
            {
                multipliers.push (multipliers.top()*stoi (component [x])%MOD);
            }
        }
        else if (component [x] == "(")
        {
            multipliers.pop();
        }
    }
    for (auto const& each: freq)
    {
        cout << each.first << " " << each.second << endl;
    }
    return 0;
}
