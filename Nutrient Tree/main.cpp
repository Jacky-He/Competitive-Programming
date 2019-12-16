#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

int tree [1000][2]; //first: edge weight, second: leaf weight
int dp [1000][2][2505]; //first: node, second: 0: edge, 1: node, third: agents
string str;
int agents;
queue <int> Q;

int solve (int node, int op, int agents)
{
    int& ret = dp [node][op][agents];
    if (ret != 0)
    {
        return ret;
    }
    int res = 0;
    if (op == 1)
    {
        for (int x = 0; x <= agents; x++)
        {
            res = max (res, solve ((node << 1), 0, x) + solve ((node << 1)|1, 0, agents - x));
        }
        return ret = res;
    }
    for (int x = 0; x < 750 && x <= agents; x++)
    {
        res = max (res, min ((1 + x)*(1 + x), solve (node, 1, agents - x)));
    }
    return ret = res;
}

bool isNum (char c) {return '0' <= c && c <= '9';}

string trim (string str)
{
    int i = 0;
    while (i < (int)str.size() && str [i] == ' ')
    {
        i++;
    }
    int j = (int)str.size() - 1;
    while (j >= 0 && str [j] == ' ')
    {
        j--;
    }
    return str.substr(i, j - i + 1);
}

void parse (string str, int index)
{
    str = trim (str);
    if (str [0] != '(')
    {
        tree [index][0] = 1;
        tree [index][1] = stoi (str);
        Q.push (index);
        for (int x = 0; x <= agents; x++)
        {
            dp [index][1][x] = tree [index][1] + x;
        }
        return;
    }
    str = str.substr(1, str.size() - 2);
    str = trim (str);
    string left = "";
    string right = "";
    bool space = false;
    int open = 0;
    for (int x = 0; x < (int)str.size(); x++)
    {
        if (str [x] == '(')
        {
            open++;
        }
        else if (str [x] == ')')
        {
            open--;
        }
        if (str [x] == ' ' && open == 0)
        {
            space = true;
        }
        else
        {
            space ? right += str [x] : left += str [x];
        }
    }
    tree [index][0] = 1;
    parse (left, index<<1);
    parse (right, index<<1|1);
}

int main ()
{
    getline (cin, str);
    cin >> agents;
    parse(str, 1);
    cout << solve (1, 1, agents) << endl;
    return 0;
}

