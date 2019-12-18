#include <bits/stdc++.h>
using namespace std;

int dialogues;
string lines;
unordered_map <string, unordered_map <string, int>> lookup;
unordered_map <string, unordered_map <string, int>> subjectAction;  //1: positive, 0: uninitialized, -1: negative, -2 contradictory
unordered_map <string, unordered_map <string, int>> actionSubject;
string arr [101];
int statementcnt = 1;
bool contradictions = false;
inline void init ()
{
    lookup.clear();
    subjectAction.clear();
    actionSubject.clear();
    contradictions = false;
}
inline void fill (string str)
{
    string word = "";
    int wordcnt = 0;
    for (int x = 0; x < 101; x++)
    {
        arr [x] = "";
    }
    for (int x = 0; x < (int)str.size() - 1; x++)
    {
        if (str [x] != ' ')
        {
            word += str [x];
            if (x == (int)str.size() - 2)
            {
                arr [wordcnt] = word;
                wordcnt++;
                word = "";
            }
        }
        else if (str [x] == ' ')
        {
            arr [wordcnt] = word;
            wordcnt++;
            word = "";
        }
    }
    if ((str [str.size() - 1] == '.'&& (arr [1] == "don't" || arr [1] == "doesn't")) || arr [0] == "do" || arr [0] == "does")
    {
        int y = 4;
        while (arr [y] != "")
        {
            arr [3] += (" " + arr [y]);
            arr [y] = "";
            y++;
        }
        return;
    }
    if ((str [str.size() - 1] == '.'&& (arr [1] != "don't" && arr [1] != "doesn't")) || arr [0] == "who")
    {
        int y = 3;
        while (arr [y] != "")
        {
            arr [2] += (" " + arr [y]);
            arr [y] = "";
            y++;
        }
    }
}
pair <string, string> returnAction (string str)
{
    string first = "";
    string second = "";
    bool swticht = false;
    for (int x = 0; x < (int)str.size(); x++)
    {
        if (str [x] == ' ' && !swticht)
        {
            swticht = true;
        }
        else if (!swticht)
        {
            first += str [x];
        }
        else
        {
            second += str [x];
        }
    }
    return {first, second == ""? "": " " + second};
}
inline void statement (string str)
{
    fill (str);
    if (arr [1] == "don't" || arr [1] == "doesn't")
    {
        int& ret = subjectAction [arr [0]][arr [2] + " " + arr [3]];
        int& ret2 = subjectAction ["everybody"][arr[2] + " " + arr[3]];
        int& ret3 = subjectAction ["nobody"][arr[2] + " " + arr[3]];
        int& hi = lookup [arr[0]][arr[2] + " " + arr[3]];
        hi = (hi == 0? statementcnt: min (statementcnt, hi));
        if (ret == 1 || ret == -2)
        {
            ret = -2;
            contradictions = true;
        }
        else
        {
            ret = -1;
        }
        if ((arr [0] != "everybody" && ret == -1 && ret2 == 1) || (arr [0] != "nobody" && ret == 1 && ret3 == 1))
        {
            contradictions = true;
        }
        actionSubject [arr [2] + " " + arr [3]][arr[0]] = ret;
    }
    else
    {
        if (arr [1][arr [1].size() - 1] == 's')
        {
            arr [1] = arr [1].substr(0, arr [1].size() - 1);
        }
        int& hi = lookup [arr[0]][arr[1] + " " + arr[2]];
        hi = hi == 0? statementcnt: min (statementcnt, hi);
        int& ret = subjectAction [arr [0]][arr[1] + " " + arr [2]];
        int& ret2 = subjectAction ["everybody"][arr[1] + " " + arr[2]];
        int& ret3 = subjectAction ["nobody"][arr[1] + " " + arr[2]];
        if (ret == -1 || ret == -2)
        {
            ret = -2;
            contradictions = true;
        }
        else
        {
            ret = 1;
        }
        if ((arr [0] != "everybody" && ret == -1 && ret2 == 1) || (arr [0] != "nobody" && ret == 1 && ret3 == 1))
        {
            contradictions = true;
        }
        if (arr [0] == "everybody")
        {
            for (auto const& p: actionSubject [arr[1] + " " + arr[2]])
            {
                if (p.second == -1)
                {
                    contradictions = true;
                    break;
                }
            }
        }
        if (arr [0] == "nobody")
        {
            for (auto const& p: actionSubject [arr [1] + " " + arr [2]])
            {
                if (p.second == 1 && p.first != "nobody")
                {
                    contradictions = true;
                    break;
                }
            }
        }
        actionSubject [arr[1] + " " + arr[2]][arr[0]] = ret;
    }
}
// special subject: everybody and nobody (they will only have positive statements)
inline void question (string str)
{
    fill (str);
    if (contradictions)
    {
        cout << "I am abroad." << endl;
        return;
    }
    if (arr [0] == "does" || arr [0] == "do")
    {
        int& ret1 = subjectAction [arr [1]][arr[2] + " " + arr [3]];
        int& ret2 = subjectAction ["everybody"][arr[2] + " " + arr[3]];
        int& ret3 = subjectAction ["nobody"][arr[2] + " " + arr[3]];
        string subject = arr [1] == "you"? "I": (arr [1] == "I"? "you":arr[1]);
        if (ret1 == 1 || ret2 == 1)
        {
            cout << "yes, " << subject << " " << ((arr [0] == "does")? arr[2]+"s":arr[2]) << (arr [3] == "" ? "":" " + arr [3]) << "." << endl;
        }
        else if (ret1 == -1 || ret3 == 1)
        {
            cout << "no, " << subject << " " << arr [0] << "n't " << arr[2] << (arr[3] == "" ? "":" " + arr[3]) << "." << endl;
        }
        else
        {
            cout << "maybe." << endl;
        }
    }
    else if (arr [0] == "who")
    {
        vector <pair <int, string>> v;
        arr [1] = arr[1].substr(0, arr[1].size() - 1);
        string action = arr [1] + " " + arr [2];
        if (subjectAction ["everybody"][action] == 1)
        {
            cout << "everybody " << arr [1] << "s" << (arr [2] == ""? ".": " " + arr[2] + ".") << endl;
            return;
        }
        if (subjectAction ["nobody"][action] == 1)
        {
            cout << "nobody " << arr [1] << "s" << (arr [2] == ""? ".": " " + arr[2] + ".") << endl;
            return;
        }
        for (auto const& p: actionSubject [action])
        {
            if (p.second == 1)
            {
                if (p.first == "you")
                {
                    v.push_back ({lookup [p.first][action], "I"});
                }
                else if (p.first == "I")
                {
                    v.push_back ({lookup [p.first][action], "you"});
                }
                else
                {
                    v.push_back ({lookup [p.first][action], p.first});
                }
            }
        }
        if (v.empty())
        {
            cout << "I don't know." << endl;
            return;
        }
        if (v.size() == 1 && v [0].second != "you" && v[0].second != "I")
        {
            cout << v[0].second << " " << arr [1] << "s" << (arr [2] == ""? ".": " " + arr[2] + ".") << endl;
            return;
        }
        if (v.size() == 1)
        {
            cout << v[0].second << " " << arr [1] << (arr [2] == ""? ".": " " + arr[2] + ".") << endl;
            return;
        }
        sort (v.begin(), v.end());
        for (int x = 0; x < (int)v.size(); x++)
        {
            if (x == 0)
            {
                cout << v [x].second;
            }
            else if (x == (int)v.size() - 1)
            {
                cout << " and " << v [x].second << " " << arr[1] << (arr [2] == ""? ".": " " + arr[2] + ".") << endl;
            }
            else
            {
                cout << ", " << v[x].second;
            }
        }
    }
    else if (arr [0] == "what")
    {
        queue <string> Q;
        set <pair <int, string>> s;
        unordered_set <string> visited;
        string zhudongci = (arr[1] == "do"? "don't":"doesn't");
        bool b = (arr [1] == "do");
        for (auto const& p: subjectAction ["everybody"])
        {
            pair <string, string> te = returnAction (p.first);
            if (p.second == 1)
            {
                s.insert ({lookup ["everybody"][p.first], (b? te.first:te.first + "s") + te.second});
            }
        }
        for (auto const& p: subjectAction ["nobody"])
        {
            pair <string, string> te = returnAction (p.first);
            if (p.second == 1)
            {
                s.insert ({lookup ["nobody"][p.first], zhudongci + " " + te.first + te.second});
            }
        }
        for (auto const& p: subjectAction [arr [2]])
        {
            pair <string, string> te = returnAction (p.first);
            if (p.second == 1)
            {
                s.insert ({lookup [arr[2]][p.first], (b? te.first:te.first+ "s") + te.second});
            }
            else if (p.second == -1)
            {
                s.insert ({lookup [arr[2]][p.first], zhudongci + " " + te.first + te.second});
            }
        }
        for (pair <int, string> each: s)
        {
            if (!visited.count (each.second))
            {
                visited.insert (each.second);
                Q.push (each.second);
            }
        }
        if (Q.empty())
        {
            cout << "I don't know." << endl;
            return;
        }
        string subject = (arr [2] == "you"? "I": (arr [2] == "I"? "you":arr[2]));
        if (Q.size() == 1)
        {
            cout << subject << " " << Q.front() << "." << endl;
            return;
        }
        int size = (int)Q.size();
        int index = 0;
        while (!Q.empty())
        {
            string temp = Q.front();
            Q.pop();
            if (index == 0)
            {
                cout << subject << " " << temp;
            }
            else if (index == size - 1)
            {
                cout << ", and " << temp << "." << endl;
            }
            else
            {
                cout << ", " << temp;
            }
            index++;
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> dialogues;
    getline (cin, lines);
    for (int x = 0; x < dialogues; x++)
    {
        init ();
        cout << "Dialogue #" << x + 1 << ":" << endl;
        getline (cin, lines);
        statementcnt++;
        while (lines [lines.size() - 1] != '!')
        {
            if (lines [lines.size() - 1] == '.')
            {
                statement (lines);
            }
            else if (lines [lines.size() - 1] == '?')
            {
                cout << lines << endl;
                question (lines);
                cout << endl;
            }
            getline (cin, lines);
            statementcnt++;
        }
        cout << lines << endl;
        cout << endl;
    }
    return 0;
}
/*
nobody likes tennis.
does he like tennis?
do I like tennis?
what do I do?
what does he do?

 
*/
/*
Jula understands the universe.
Jula likes writing her stuff down.
Jula likes cooking.
Jula hates running.
what does Jula do?
Mama likes everyone.
Jula likes everyone.
Janson likes everyone.
who likes everyone?
who hates running?
does Jula like everyone?
does Jula like running?
Jula doesn't like running.
does Jula like running?
*/

/*
I like hotdogs.
nobody likes to work.
does Jamie like to work?
do I like to work?
everybody runs in the morning.
what does Jula do?
does Jula run in the running?
Jula doesn't run in the morning.
does Jula run in the morning?
*/
