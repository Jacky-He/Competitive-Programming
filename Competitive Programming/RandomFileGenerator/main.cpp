#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int toChar (int n)
{
    return n + 'a';
}
int main ()
{
    /*
    int cnt = 0;
    string dir = "/Users/jackyhe/Desktop/RandomFolders";
    for (int a = 0; a < 26; a++)
    {
        dir += "/";
        dir += toChar (a);
        mkdir(dir.c_str(), ACCESSPERMS);
        dir = dir.substr (0, dir.size() - 2);
    }
    for (int a = 0; a < 26; a++)
    {
        dir += "/";
        dir += toChar (a);
        for (int b = 0; b < 26; b++)
        {
            dir += "/";
            dir += toChar (b);
            mkdir(dir.c_str(), ACCESSPERMS);
            dir = dir.substr(0, dir.size() - 2);
        }
        dir = dir.substr (0, dir.size() - 2);
    }
    for (int a = 0; a < 26; a++)
    {
        dir += "/";
        dir += toChar (a);
        for (int b = 0; b < 26; b++)
        {
            dir += "/";
            dir += toChar (b);
            for (int c = 0; c < 26; c++)
            {
                dir += "/";
                dir += toChar (c);
                mkdir(dir.c_str(), ACCESSPERMS);
                dir = dir.substr (0, dir.size() - 2);
            }
            dir = dir.substr(0, dir.size() - 2);
        }
        dir = dir.substr (0, dir.size() - 2);
    }
    for (int a = 0; a < 26; a++)
    {
        dir += "/";
        dir += toChar (a);
        for (int b = 0; b < 26; b++)
        {
            dir += "/";
            dir += toChar (b);
            for (int c = 0; c < 26; c++)
            {
                dir += "/";
                dir += toChar (c);
                for (int d = 0; d < 26; d++)
                {
                    dir += "/";
                    dir += toChar (d);
                    mkdir(dir.c_str(), ACCESSPERMS);
                    ofstream file;
                    file.open (dir + "/climate.txt");
                    file << "change";
                    file.close();
                    dir = dir.substr (0, dir.size() - 2);
                    cnt++;
                    printf ("%d\n", cnt);
                }
                dir = dir.substr (0, dir.size() - 2);
            }
            dir = dir.substr(0, dir.size() - 2);
        }
        dir = dir.substr (0, dir.size() - 2);
    }*/
    return 0;
}

