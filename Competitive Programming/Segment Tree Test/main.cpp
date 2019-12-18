#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct s
{
    int mini, great, nnum;
};
int n, m, first, second;
string temp;
s tree [400002];
int lo [400002];        //index represents the node in the tree
int hi [400002];
int arr [100001];
int gcf (int a, int b) {return b == 0? a : gcf (b, a%b);}
//int gcf (int a, int b) {return (b > a)? gcf (b, a):((a%b == 0)? b : gcf (b, a%b));}
void init (int left, int right, int index)
{
    hi [index] = right;
    lo [index] = left;
    if (left == right)
    {
        tree [index].mini = arr [left];
        tree [index].great = arr [left];
        tree [index].nnum = 1;
        return;
    }
    int mid = (left + right)/2;
    init (left, mid, index*2);
    init (mid + 1, right, index*2 + 1);
    tree [index].mini = min(tree [index*2].mini,tree [index*2 + 1].mini);
    tree [index].great = gcf (tree [index*2].great, tree [index*2 + 1].great);
    if (tree [index*2].great == tree [index*2 + 1].great)
    {
        tree [index].nnum = tree [index*2].nnum + tree [index*2 + 1].nnum;
    }
    else if (tree [index].great == tree [index*2].great)
    {
        tree [index].nnum = tree [index*2].nnum;
    }
    else if (tree [index].great == tree [index*2 + 1].great)
    {
        tree [index].nnum = tree [index*2 + 1].nnum;
    }
    else
    {
        tree [index].nnum = 0;
    }
}
void change (int i, int value, int index) //i: index of arr     index: index of tree
{
    if (hi [index] == i && lo [index] == i)
    {
        tree [index].mini = value;
        tree [index].great = value;
        return;
    }
    int mid = (hi [index] + lo [index])/2;
    if (mid >= i)
    {
        change (i, value, index*2);
    }
    else
    {
        change (i, value, index*2 + 1);
    }
    tree [index].mini = min(tree [index*2].mini,tree [index*2 + 1].mini);
    tree [index].great = gcf (tree [index*2].great, tree [index*2 + 1].great);
    if (tree [index*2].great == tree [index*2 + 1].great)
    {
        tree [index].nnum = tree [index*2].nnum + tree [index*2 + 1].nnum;
    }
    else if (tree [index].great == tree [index*2].great)
    {
        tree [index].nnum = tree [index*2].nnum;
    }
    else if (tree [index].great == tree [index*2 + 1].great)
    {
        tree [index].nnum = tree [index*2 + 1].nnum;
    }
    else
    {
        tree [index].nnum = 0;
    }
}
int minimum (int left, int right, int index)
{
    if (lo [index] > right || hi [index] < left)
    {
        return INF;
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        return tree [index].mini;
    }
    int minLeft = minimum (left, right, index*2);
    int minRight = minimum (left, right, index*2 + 1);
    return min (minLeft, minRight);
}
int gcd (int left, int right, int index)
{
    if (lo [index] > right || hi [index] < left)
    {
        return -1;
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        return tree [index].great;
    }
    int gcdLeft = gcd (left, right, index*2);
    int gcdRight = gcd (left, right, index*2 + 1);
    if (gcdLeft == -1)
    {
        return gcdRight;
    }
    if (gcdRight == -1)
    {
        return gcdLeft;
    }
    return gcf (gcdLeft, gcdRight);
}
pair <int, int> numnum (int left, int right, int index)
{
    if (lo [index] > right || hi [index] < left)
    {
        return {-1, -1};
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        return {tree [index].great, tree [index].nnum};
    }
    pair <int, int> nnumLeft = numnum (left, right, index*2);
    pair <int, int> nnumRight = numnum (left, right, index*2 + 1);
    if (nnumLeft.first == -1)
    {
        return nnumRight;
    }
    if (nnumRight.first == -1)
    {
        return nnumLeft;
    }
    int currentgcf = gcf (nnumLeft.first, nnumRight.first);
    if (nnumLeft.first == nnumRight.first)
    {
        return {nnumLeft.first, nnumLeft.second + nnumRight.second};
    }
    if (currentgcf == nnumLeft.first)
    {
        return {nnumLeft.first, nnumLeft.second};
    }
    if (currentgcf == nnumRight.first)
    {
        return {nnumRight.first, nnumRight.second};
    }
    return {currentgcf, 0};
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int x = 1; x < n; x++)
    {
        cin >> arr [x];
    }
    cin >> arr [n];
    init (1, n, 1);
    for (int x = 0; x < m; x++)
    {
        cin >> temp >> first >> second;
        if (temp == "C")
        {
            change (first, second, 1);
        }
        else if (temp == "M")
        {
            printf ("%d\n", minimum (first, second, 1));
        }
        else if (temp == "G")
        {
            printf ("%d\n", gcd (first, second, 1));
        }
        else if (temp == "Q")
        {
            printf ("%d\n", numnum (first, second, 1).second);
        }
    }
    return 0;
}
