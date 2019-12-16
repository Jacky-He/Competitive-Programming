#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct snowflake {int row, col, t, delta;};
struct query {string type; int a, b, c, d, t, order, ans;};
query makequery (string type, int a, int b, int c, int d, int t, int order) {query q; q.type = type; q.a = a; q.b = b; q.c = c; q.d = d; q.t = t; q.order = order; return q;}
snowflake makesnow (int a, int b, int c, int d) {snowflake s; s.row = a; s.col = b; s.t = c; s.delta = d; return s;}
bool cmp (snowflake s1, snowflake s2) {return s1.t < s2.t;}
bool cmp1 (query q1, query q2){return q1.t < q2.t;}
bool cmp2 (query q1, query q2){return q1.order < q2.order;}

int n, m, q, a, b, c, d, t;
vector <snowflake> v;
vector <query> queries;
string operation;
int fenwick [5005][5005];

int lowbit (int num)
{
    return num&(-num);
}
void add (int row, int col, int delta)
{
    while (row <= n)
    {
        int temp = col;
        while (temp <= n)
        {
            fenwick [row][temp] += delta;
            temp += lowbit (temp);
        }
        row += lowbit (row);
    }
}
int sum (int row, int col)
{
    int tot = 0;
    while (row > 0)
    {
        int temp = col;
        while (temp > 0)
        {
            tot += fenwick [row][temp];
            temp -= lowbit (temp);
        }
        row -= lowbit (row);
    }
    return tot;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> n >> m >> q;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c >> d;
        v.push_back (makesnow (a + 1, b + 1, c, 1));
        v.push_back (makesnow (a + 1, b + 1, d, -1));
    }
    sort (v.begin(), v.end(), cmp);
    
    for (int x = 0; x < q; x++)
    {
        cin >> operation;
        if (operation == "R" || operation == "C")
        {
            cin >> a >> b >> t;
            queries.push_back (makequery (operation, a + 1, b + 1, -1, -1, t, x));
        }
        else if (operation == "V")
        {
            cin >> a >> b >> c >> d >> t;
            queries.push_back (makequery (operation, a + 1, b + 1, c + 1, d + 1, t, x));
        }
    }
    sort (queries.begin(), queries.end(), cmp1);
    int i = 0, j = 0;
    while (i < (int)queries.size())
    {
        while (j < (int)v.size() && v [j].t <= queries [i].t)
        {
            add (v[j].row, v[j].col, v[j].delta);
            j++;
        }
        if (queries [i].type == "R")
        {
            queries [i].ans = sum (queries [i].b, n) - sum (queries [i].a - 1, n);
        }
        else if (queries [i].type == "C")
        {
            queries [i].ans = sum (n, queries [i].b) - sum (n, queries [i].a - 1);
        }
        else if (queries [i].type == "V")
        {
            int betweenrows = sum (queries [i].b, n) - sum (queries [i].a - 1, n);
            int betweencols = sum (n, queries [i].d) - sum (n, queries [i].c - 1);
            int betweenrowsandcols = (sum (queries [i].b, queries [i].d) - sum (queries [i].b, queries [i].c - 1)) - (sum(queries [i].a - 1, queries [i].d) - sum (queries [i].a - 1, queries [i].c - 1));
            queries [i].ans = betweenrows + betweencols - betweenrowsandcols;
        }
        i++;
    }
    sort (queries.begin(), queries.end(), cmp2);
    for (query each: queries)
    {
        cout << each.ans << endl;
    }
    return 0;
}



