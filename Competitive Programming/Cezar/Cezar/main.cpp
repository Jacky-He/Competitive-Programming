#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
using namespace std;
int toInt (char c) {return c - 'a';}
char toChar (int i) {return i + 'a';}
struct Node
{
    Node** children; //0: a, 25: z
    bool endofword;
    int minorder;
    int maxorder;
    int order;
    Node()
    {
        children = new Node* [26];
        for (int x = 0; x < 26; x++)
        {
            children [x] = nullptr;
        }
        endofword = false;
        minorder = INF;
        maxorder = 0;
        order = -1;
    }
};

int n, order;
string str;
vector <string> words;
unordered_set <int> adj [30]; //lists of characters that this character is bigger than
vector <int> adjrev [30];
int dis [30];
bool visited [30];
vector <pair <pair <int, int>, int>> mimax;

Node* root = new Node();
queue <Node*> Q;

void push (string word, int order)
{
    Node* current = root;
    for (int index = 0; index < (int)word.length(); index++)
    {
        if (current -> children [toInt(word[index])] == nullptr)
        {
            current -> children [toInt(word[index])] = new Node();
        }
        current = current -> children [toInt(word[index])];
        current -> maxorder = max(current -> maxorder, order);
        current -> minorder = min (current -> minorder, order);
    }
    current -> endofword = true;
    current -> order = order;
}
bool bfs ()
{
    Q.push (root);
    while (!Q.empty())
    {
        Node* temp = Q.front();
        Q.pop();
        mimax.clear();
        for (int x = 0; x < 26; x++)
        {
            if (temp -> children [x] != nullptr)
            {
                if (temp -> endofword && temp -> order > temp -> children [x] -> minorder)
                {
                    return false;
                }
                mimax.push_back ({{temp -> children [x] -> minorder, temp -> children [x] -> maxorder}, x});
                Q.push (temp -> children [x]);
            }
        }
        sort (mimax.begin(), mimax.end());
        pair <int, int> prev = {-1, -1};
        for (pair <pair <int, int>, int> each: mimax)
        {
            if (each.first.first < prev.second)
            {
                return false;
            }
            prev = each.first;
        }
        for (int x = 0; x < (int)mimax.size(); x++)
        {
            for (int y = x + 1; y < (int)mimax.size(); y++)
            {
                adj [mimax [x].second].insert (mimax [y].second);
            }
        }
    }
    return true;
}

bool cycle = false;
void dfscycle (int node)
{
    visited [node] = true;
    for (int each: adj [node])
    {
        if (visited [each])
        {
            cycle = true;
        }
        else
        {
            dfscycle (each);
        }
    }
    visited [node] = false;
}

bool checkcycle()
{
    for (int x = 0; x < 26; x++)
    {
        cycle = false;
        dfscycle(x);
        if (cycle)
        {
            return true;
        }
    }
    return false;
}

void getreverseadj ()
{
    for (int x = 0; x < 30; x++)
    {
        for (int each: adj [x])
        {
            adjrev [each].push_back (x);
        }
    }
}

void bfs2 (int node)
{
    queue <int> Q;
    Q.push (node);
    dis [node] = 1;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (dis [each] == INF)
            {
                dis [each] = dis [temp] + 1;
            }
            dis [each] = max(dis [each], dis [temp] + 1);
            Q.push (each);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        words.push_back(str);
    }
    for (int x = 0; x < n; x++)
    {
        cin >> order;
        push (words [order - 1], x + 1);
    }
    if (!bfs())
    {
        cout << "NE" << endl;
        return 0;
    }
    if (checkcycle())
    {
        cout << "NE" << endl;
        return 0;
    }
    getreverseadj ();
    memset (dis, 0x3f, sizeof (dis));
    for (int x = 0; x < 26; x++)
    {
        if (adjrev [x].empty() && !adj [x].empty())
        {
            bfs2 (x);
        }
    }
    vector <pair <int, int>> res;
    for (int x = 0; x < 26; x++)
    {
        res.push_back ({dis [x], x});
    }
    sort (res.begin(), res.end());
    string result = "aaaaaaaaaaaaaaaaaaaaaaaaaa";
    //string result = "abcdefghijklmnopqrstuvwxyz";
    int x = 0;
    for (pair <int, int> each: res)
    {
        result [each.second] = toChar(x);
        x++;
    }
    cout << "DA" << endl;
    cout << result << endl;
    return 0;
}
