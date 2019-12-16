#include <bits/stdc++.h>
using namespace std;
int toInt (char c) {return c - 'a';}
struct Node
{
    Node** children; //0: a, 25: z
    bool endofword;
    int numwords;
    int linenumber;
    Node ()
    {
        children = new Node* [26];
        for (int x = 0; x < 26; x++)
        {
            children [x] = nullptr;
        }
        endofword = false;
        numwords = 0;
        linenumber = 0;
    }
};
int n, m;
int k;
string prefix;
string line;
Node* root = new Node();

void insert (string str, int line)
{
    Node* current = root;
    for (int index = 0; index < (int)str.length(); index++)
    {
        current -> numwords += 1;
        if (current -> children [toInt(str[index])] == nullptr)
        {
            current -> children [toInt(str[index])] = new Node();
        }
        current = current -> children [toInt(str[index])];
    }
    current -> endofword = true;
    current -> numwords += 1;
    current -> linenumber = line;
}

int query (int completion, string pre)
{
    Node* current = root;
    for (int index = 0; index < (int)pre.length(); index++)
    {
        if (current -> children [toInt(pre[index])] != nullptr)
        {
            current = current -> children [toInt(pre[index])];
        }
        else
        {
            return -1;
        }
    }
    if (current -> numwords < completion)
    {
        return -1;
    }
    int result = 0;
    while (true)
    {
        if (current -> endofword && completion == 1)
        {
            result = current -> linenumber;
            break;
        }
        if (current -> endofword)
        {
            completion--;
        }
        for (int x = 0; x < 26; x++)
        {
            if (current -> children [x] != nullptr)
            {
                if (current -> children [x] -> numwords >= completion)
                {
                    current = current -> children [x];
                    break;
                }
                else
                {
                    completion -= current -> children [x] -> numwords;
                }
            }
        }
    }
    return result;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    getline (cin, line);
    for (int x = 1; x <= n; x++)
    {
        getline (cin, line);
        insert (line, x);
    }
    for (int x = 1; x <= m; x++)
    {
        cin >> k >> prefix;
        cout << query (k, prefix) << endl;
    }
    return 0;
}
