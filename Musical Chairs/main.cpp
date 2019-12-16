#include <bits/stdc++.h>
using namespace std;
int n, k;
int empty, student;

int state [1000003]; //-1: empty, 0: nothing: 1: student
stack <int> students;
int lookup [1000003];
int studentcnt;

int main ()
{
    scanf ("%d%d", &n, &k);
    studentcnt = k + 1;
    for (int x = 0; x < k; x++)
    {
        scanf ("%d", &empty);
        state [empty] = -1;
    }
    for (int x = 0; x < k + 1; x++)
    {
        scanf ("%d", &student);
        if (state [student] == -1)
        {
            state [student] = 0;
            studentcnt--;
        }
        else
        {
            state [student] = 1;
            lookup [student] = x + 1;
        }
    }
    int index = 1;
    while (studentcnt > 1)
    {
        if (state [index] == 1)
        {
            state [index] = 0;
            students.push(index);
        }
        if (state [index] == -1 && !students.empty())
        {
            state [index] = 0;
            students.pop();
            studentcnt--;
        }
        index = index%n + 1;
    }
    printf ("%d\n", lookup [students.top()]);
    return 0;
}
