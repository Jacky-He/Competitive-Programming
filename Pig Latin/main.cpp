#include <bits/stdc++.h>
using namespace std;
string input = " ";
bool vowel (char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (input != "")
    {
        if (vowel(input [0]))
        {
            cout << input + "ay ";
        }
        else
        {
            int yesvowel = false;
            for (int x = 0; x < (int)input.length(); x++)
            {
                if (vowel (input[x]))
                {
                    yesvowel = true;
                    
                    cout << input.substr(x) + input.substr(0, x) + "ay ";
                    break;
                }
            }
            if (!yesvowel)
            {
                for (int x = 0; x < (int)input.length(); x++)
                {
                    if (input [x] == 'y')
                    {
                        cout << input + "ay ";
                        break;
                    }
                }
            }
        }
        cin >> input;
    }
    cout << endl;
    return 0;
}
