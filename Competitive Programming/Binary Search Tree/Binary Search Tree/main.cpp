#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long int ll;

mt19937 g1((unsigned int)time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<ll>(a, b)(g1);}
 
struct node
{
    node* pls; // <
    node* prb; // >=
    int key;
    int priority;
    int sz;
    node (int key, int priority)
    {
        pls = prb = nullptr;
        this -> key = key;
        this -> priority = priority;
        this -> sz = 1;
    }
};

struct treap
{
    node* root = nullptr;

    void insert (int key)
    {
        if (root == nullptr)
        {
            root = new node (key, randint(1, 1e9));
            return;
        }
        root = insert (key, root);
    }
    node* insert (int key, node* curr)
    {
        curr -> sz ++;
        if (key < curr -> key)
        {
            if (curr -> pls)
            {
                curr -> pls = insert (key, curr -> pls);
            }
            else
            {
                curr -> pls = new node (key, randint(1, 1e9));
            }
            if (curr -> pls -> priority <= curr -> priority)
            {
                return rightrotation (curr);
            }
            return curr;
        }
        if (curr -> prb)
        {
            curr -> prb = insert (key, curr -> prb);
        }
        else
        {
            curr -> prb = new node (key, randint(1, 1e9));
        }
        if (curr -> prb -> priority <= curr -> priority)
        {
            if (curr -> prb -> key == curr -> key)
            {
                int temp = curr -> key;
                curr -> key = curr -> prb -> key;
                curr -> prb -> key = temp;
                return curr;
            }
            return leftrotation (curr);
        }
        return curr;
    }
    
    node* rightrotation (node* curr)
    {
        node* temp = curr -> pls;
        int rs = curr -> pls -> prb ? curr -> pls -> prb -> sz : 0;
        curr -> sz += (rs - curr -> pls -> sz);
        curr -> pls -> sz += (curr -> sz - rs);
        //pointers
        curr -> pls = curr -> pls -> prb;
        temp -> prb = curr;
        return temp;
    }
    
    node* leftrotation (node* curr)
    {
        node* temp = curr -> prb;
        //sizes
        int ls = curr -> prb -> pls ? curr -> prb -> pls -> sz : 0;
        curr -> sz += (ls - curr -> prb -> sz);
        curr -> prb -> sz += (curr -> sz - ls);
        //pointers
        curr -> prb = curr -> prb -> pls;
        temp -> pls = curr;
        return temp;
    }
    
    int find (int ele) //returns index;
    {
        int res = find (ele, root);
        return res < 0 ? -1 : res + 1;
    }
    
    int find (int key, node* curr)
    {
        if (curr == nullptr) {return -INF;}
        if (curr -> key == key)
        {
            return curr -> pls ? curr -> pls -> sz : 0;
        }
        if (curr -> key > key && curr -> pls)
        {
            return find (key, curr -> pls);
        }
        if (curr -> key <= key && curr -> prb)
        {
            return (curr -> pls ? curr -> pls -> sz : 0) + 1 + find (key, curr -> prb);
        }
        return -INF;
    }
    
    void erase (int key)
    {
        if (find (key) != -1)
        {
            root = erase (key, root);
        }
    }
    
    node* meld (node* t1, node* t2)
    {
        if (t1 == nullptr) {return t2;}
        if (t2 == nullptr) {return t1;}
        node* smaller; node* bigger;
        if (t1 -> priority < t2 -> priority)
        {
            smaller = t1;
            bigger = t2;
        }
        else
        {
            smaller = t2;
            bigger = t1;
        }
        if (smaller -> key < bigger -> key)
        {
            bigger -> sz += smaller -> sz;
            smaller -> sz += bigger -> pls ? bigger -> pls -> sz : 0;
            smaller -> prb = meld (smaller -> prb, bigger -> pls);
            bigger -> pls = smaller;
        }
        else
        {
            bigger -> sz += smaller -> sz;
            smaller -> sz += bigger -> prb ? bigger -> prb -> sz : 0;
            smaller -> pls = meld (smaller -> pls, bigger -> prb);
            bigger -> prb = smaller;
        }
        return bigger;
    }
    
    node* erase (int key, node* curr)
    {
        if (curr == nullptr) {return nullptr;}
        curr -> sz --;
        if (curr -> key == key)
        {
            return meld (curr -> pls, curr -> prb);
        }
        if (key < curr -> key)
        {
            curr -> pls = erase (key, curr -> pls);
        }
        else
        {
            curr -> prb = erase (key, curr -> prb);
        }
        return curr;
    }
    
    int kth (int k)
    {
        return kth (k, root);
    }
    
    int kth (int k, node* curr)
    {
        int currsz = curr -> pls ? curr -> pls -> sz : 0;
        if (currsz + 1 == k)
        {
            return curr -> key;
        }
        if (currsz + 1 > k)
        {
            return kth (k, curr -> pls);
        }
        return kth (k - currsz -1, curr -> prb);
    }
    
    int size ()
    {
        return root ? root -> sz : 0;
    }
};


int n, m, num;
string op;
/*
int randint (int from, int to)
{
    return rand()%(to - from + 1) + from;
}*/

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie (0);
    treap* t = new treap();
    /*for (int x = 0; x < 500000; x++)
    {
        int a = randint (1, 1e9);
        int b = randint (1, 1e9);
        t -> insert (a);
        t -> erase (b);
        if (t -> size() > 0)
        {
            cout << t -> kth (randint (1, t.size())) << endl;
        }
        cout << t.find (randint (1, 1e9)) << endl;
    }*/
    
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> num;
        t -> insert (num);
    }
    int lastans = 0;
    for (int x = 0; x < m; x++)
    {
        cin >> op >> num;
        if (op == "I")
        {
            //t -> insert (num);
            t -> insert (num^lastans);
        }
        else if (op == "R")
        {
            //t -> erase (num);
            t -> erase (num^lastans);
        }
        else if (op == "S")
        {
            //cout << t -> kth (num) << endl;
            lastans = t -> kth (num^lastans);
            cout << lastans << endl;
        }
        else if (op == "L")
        {
            //cout << t -> find (num) << endl;
            lastans = t -> find (num^lastans);
            cout << lastans << endl;
        }
    }
    for (int x = 1; x <= t -> size(); x++)
    {
        cout << t -> kth (x) << " ";
    }
    return 0;
}

/*
3 5
1 1 1
R 1
R 1
R 1
L 1
I 1

10 2
92 23 34 23 223 214 23 93 93 92
L 92
L 23


*/
