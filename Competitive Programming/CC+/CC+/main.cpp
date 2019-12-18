#include <bits/stdc++.h>
using namespace std;
void encrypt (int key, string message)
{
    int numWords = 0;
    string lengthWords = "";
    int lengthWord = 0;
    string messageWS = "";
    string ultimateMessage = "  ";
    for (int index = 0; index < (int) message.size(); index++)
    {
        if (message [index] == ' ')
        {
            lengthWords += (char) (lengthWord + 'a');
            lengthWord = 0;
            numWords++;
        }
        else if (index == (int)message.size() - 1)
        {
            lengthWord++;
            numWords++;
            messageWS += message [index];
            lengthWords += (char) (lengthWord + 'a');
        }
        else
        {
            messageWS += message [index];
            lengthWord++;
        }
    }
    ultimateMessage [0] = (char)(numWords/26 + 'a');
    ultimateMessage [1] = (char)(numWords % 26 + 'a');
    ultimateMessage += (lengthWords + messageWS);
    int array [ultimateMessage.size()];
    array [0] = ultimateMessage [0] - 'a';
    for (int index = 1; index < (int)ultimateMessage.size(); index++)
    {
        array [index] = ultimateMessage [index] - 'a' + array [index - 1];
    }
    for (int index = 0; index < (int) ultimateMessage.size(); index++)
    {
        ultimateMessage [index] = (ultimateMessage [index] - 'a' + (key + array [ultimateMessage.size() - 1] - array [index])%26)%26 + 'a';
    }
    cout << ultimateMessage << endl;
}
void decrypt (int key, string secretMessage)
{
    int sum = 0;
    int numWords = 0;
    for (int index = (int) secretMessage.size() - 1; index >= 0; index--)
    {
        int charInt = secretMessage [index] - 'a';
        int rotate = (key + sum)%26;
        secretMessage [index] = (26 + charInt - rotate)%26 + 'a';
        sum += (int)(secretMessage [index] - 'a');
    }
    numWords = ((int)(secretMessage [0] - 'a'))*26 + ((int)(secretMessage [1] - 'a'));
    secretMessage.erase (0, 2);
    string lengthWords = secretMessage.substr(0, numWords);
    secretMessage.erase (0, numWords);
    int x = 0;
    for (int index = 0; index < numWords; index++)
    {
        for (int index2 = x; index2 < x + (lengthWords [index] - 'a'); index2++)
        {
            cout << secretMessage [index2];
            
        }
        x += (lengthWords [index] - 'a');
        if (index < numWords - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}
int main ()
{
    int n;
    string str;
    for (int x = 0; x < 10; x++)
    {
        scanf ("%d\n", &n);
        getline (cin, str);
        if ((int)str.find(' ') != -1)
        {
            encrypt (n, str);
        }
        else
        {
            decrypt (n, str);
        }
    }
    return 0;
}
