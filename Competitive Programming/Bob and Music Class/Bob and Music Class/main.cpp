#include <bits/stdc++.h>
using namespace std;
map <string, int> notes;
int distance (string a, string b)
{
    if (notes [a] <= notes [b])
    {
        return notes [b] - notes [a];
    }
    else
    {
        return notes[b] + 12 - notes [a];
    }
}
int main ()
{
    notes ["A"] = 0;
    notes ["A#"] = 1;
    notes ["B"] = 2;
    notes ["C"] = 3;
    notes ["C#"] = 4;
    notes ["D"] = 5;
    notes ["D#"] = 6;
    notes ["E"] = 7;
    notes ["F"] = 8;
    notes ["F#"] = 9;
    notes ["G"] = 10;
    notes ["G#"] = 11;
    string triads [3];
    cin >> triads [0] >> triads [1] >> triads [2];
    int counter = 0;
    string temp = triads [0];
    while (distance (triads [0], triads [1]) > 4 || distance (triads [1], triads [2]) > 4)
    {
        string temp1 = triads [0];
        string temp2 = triads [1];
        string temp3 = triads [2];
        triads [0] = temp2;
        triads [1] = temp3;
        triads [2] = temp1;
        counter++;
    }
    
    int first = distance (triads [0], triads [1]);
    int second = distance (triads [1], triads [2]);
    bool augmented = false;
    if (first == 4 && second == 3)
    {
        cout << triads [0] << endl;
        cout << "major" << endl;
    }
    else if (first == 3 && second == 4)
    {
        cout << triads [0] << endl;
        cout << "minor" << endl;
    }
    else if (first == 4 && second == 4)
    {
        cout << temp << endl;
        cout << "augmented" << endl;
        augmented = true;
    }
    else if (first == 3 && second == 3)
    {
        cout << triads [0] << endl;
        cout << "diminished" << endl;
    }
    if (!augmented)
    {
        if (counter == 0)
        {
            cout << "root position" << endl;
        }
        else if (counter == 1)
        {
            cout << "second inversion" << endl;
        }
        else if (counter == 2)
        {
            cout << "first inversion" << endl;
        }
    }
    else
    {
        cout << "root position" << endl;
    }
    return 0;
}
