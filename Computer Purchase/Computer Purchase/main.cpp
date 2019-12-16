#include <bits/stdc++.h>
using namespace std;
struct Computer
{
    string name;
    int performance;
};
int numComputers;
vector <Computer> coms;
string n;
int r, s, d;
bool compareComs (Computer c1, Computer c2) {return (c1.performance > c2.performance) || (c1.performance == c2.performance && c1.name.compare (c2.name) < 0);}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> numComputers;
    Computer hi;
    for (int x = 0; x < numComputers; x++)
    {
        cin >> hi.name;
        cin >> r >> s >> d;
        hi.performance = 2*r + 3*s + d;
        coms.push_back (hi);
    }
    if (numComputers == 1)
    {
        cout << coms [0].name << endl;
    }
    else if (numComputers > 1)
    {
        sort (coms.begin(), coms.end(), compareComs);
        cout << coms [0].name << endl;
        cout << coms [1].name << endl;
    }
    return 0;
}
