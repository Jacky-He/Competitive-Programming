#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int numtestcases;
string out;
vector <string> outs [100005];
vector <string> consoleout;
int testcases;
int randint (int from, int to)
{
    return rand()%(to - from + 1) + from;
}

int pos [100005];

string output ()
{
    string res = "";
    //int n = randint (1, 100);
    //int k = randint (1, 100);
    int n = randint (1, 1e5);
    int k = randint (1, 1e9);
    res += to_string(n) + " " + to_string (k) + endl;
    vector <int> v;
    for (int x = 0; x < n; x++)
    {
        v.push_back (x + 1);
        //res += to_string(randint(1, 100)) + endl;
        res += to_string(randint (1, 1e9)) + endl;
    }
    random_shuffle(v.begin(), v.end());
    
    for (int x = 1; x < (int)v.size(); x++)
    {
        res += to_string (v[x]) + " " + to_string(v[randint(0, x - 1)]) + endl;
    }
    return res;
}

string bigcase ()
{
    string res = "";
    int n = 1e5;
    int k = 1e9;
    res += to_string(n) + " " + to_string (k) + endl;
    vector <int> v;
    for (int x = 1; x <= n; x++)
    {
        v.push_back (x);
        res += to_string(x) + endl;
    }
    for (int x = 1; x < (int)v.size(); x++)
    {
        res += to_string (v[x]) + " " + to_string (v[x - 1]) + endl;
    }
    return res;
}

string heavycase ()
{
    string res = "";
    int n = 1e5;
    int k = randint (1, 1e9);
    res += to_string(n) + " " + to_string (k) + endl;
    vector <int> v;
    for (int x = 0; x < n; x++)
    {
        v.push_back (x + 1);
        res += to_string(randint (1, 1e9)) + endl;
    }
    random_shuffle(v.begin(), v.end());
    for (int x = 1; x < (int)v.size(); x++)
    {
        res += to_string (v[x]) + " " + to_string(v[randint(0, x - 1)]) + endl;
    }
    return res;
}

string batch1output()
{
    string res = "";
    int n = randint (1, 100);
    int k = randint (1, 100);
    res += to_string(n) + " " + to_string (k) + endl;
    vector <int> v;
    for (int x = 0; x < n; x++)
    {
        v.push_back (x + 1);
        res += to_string(randint(1, 100)) + endl;
    }
    random_shuffle(v.begin(), v.end());
    
    for (int x = 1; x < (int)v.size(); x++)
    {
        res += to_string (v[x]) + " " + to_string(v[randint(0, x - 1)]) + endl;
    }
    return res;
}

string batch2output()
{
    string res = "";
    //int n = randint (1, 100);
    //int k = randint (1, 100);
    int n = randint (1, 1e5);
    int k = randint (1, 1e5);
    res += to_string(n) + " " + to_string (k) + endl;
    vector <int> v;
    for (int x = 0; x < n; x++)
    {
        v.push_back (x + 1);
        //res += to_string(randint(1, 100)) + endl;
        res += to_string(randint (1, 1e5)) + endl;
    }
    random_shuffle(v.begin(), v.end());
    
    for (int x = 1; x < (int)v.size(); x++)
    {
        res += to_string (v[x]) + " " + to_string(v[randint(0, x - 1)]) + endl;
    }
    return res;
}

string batch3output()
{
    string res = "";
    //int n = randint (1, 100);
    //int k = randint (1, 100);
    int n = randint (1, 1e5);
    int k = randint (1, 1e9);
    res += to_string(n) + " " + to_string (k) + endl;
    vector <int> v;
    for (int x = 0; x < n; x++)
    {
        v.push_back (x + 1);
        //res += to_string(randint(1, 100)) + endl;
        res += to_string(randint (1, 1e9)) + endl;
    }
    random_shuffle(v.begin(), v.end());
    
    for (int x = 1; x < (int)v.size(); x++)
    {
        res += to_string (v[x]) + " " + to_string(v[randint(0, x - 1)]) + endl;
    }
    return res;
}

int main ()
{
    string dir = "/Users/jackyhe/Desktop/C++/DMOJ/UTSOpen/P4TestData";
    for (int x = 1; x <= 33; x++)
    {
        ofstream file;
        file.open (dir + "/input" + to_string(x) + ".txt");
        file << batch1output();
        file.close();
    }
    for (int x = 34; x <= 66; x++)
    {
        ofstream file;
        file.open (dir + "/input" + to_string(x) + ".txt");
        file << batch2output();
        file.close();
    }
    for (int x = 67; x <= 110; x++)
    {
        ofstream file;
        file.open (dir + "/input" + to_string(x) + ".txt");
        file << heavycase();
        file.close();
    }
    ofstream file;
    file.open (dir + "/input" + to_string(111) + ".txt");
    file << bigcase();
    file.close();
    
    
    /*
    //check if the two outputs are the same
    freopen((dir + "/brute.txt").c_str(), "r", stdin);
    cin >> numtestcases;
    out = "";
    int x = 0;
    while (x < numtestcases)
    {
        cin >> out;
        if (out == "___")
        {
            x++;
        }
        outs [x].push_back (out);
    }
    fclose (stdin);
    freopen ((dir + "/notbrute.txt").c_str(), "r", stdin);
    cin >> numtestcases;
    out = "";
    for (int x = 0; x < numtestcases; x++)
    {
        bool ac = true;
        for (int y = 0; y < (int)outs [x].size(); y++)
        {
            cin >> out;
            if (out != outs [x][y])
            {
                ac = false;
            }
        }
        if (ac)
        {
            consoleout.push_back ("Test Case #" + to_string(x + 1) + ": AC");
        }
        else
        {
            consoleout.push_back ("Test Caee #" + to_string (x + 1) + ": WA");
        }
    }
    fclose (stdin);
    for (string each: consoleout)
    {
        cout << each << endl;
    }*/
    return 0;
}
