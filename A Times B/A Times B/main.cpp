#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
string num1;
string num2;
char toChar (int n)
{
    return n + '0';
}
int toNum (char c)
{
    return c - '0';
}

string slowmulti (string num1, string num2)
{
    int num1size = (int) num1.size();
    int num2size = (int) num2.size();
    string numadd = "";
    string num1temp = "";
    int indentation = 0; //indentation
    if (num1 == "0" or num2 == "0")
    {
        return "0";
    }
    else
    {
        for (int index2 = num2size - 1; index2 >= 0; index2--)
        {
            int advanceDigit = 0;
            num1temp = num1;
            for (int index1 = num1size - 1; index1 >= 0; index1--) //finds for example 2342323*3423, 2342323*3
            {
                int tempProduct = toNum(num2[index2])*toNum(num1temp[index1]) + advanceDigit;
                if (index1 == 0)
                {
                    if (tempProduct/10 > 0)
                    {
                        num1temp[index1] = toChar(tempProduct%10);
                        num1temp = " " + num1temp;
                        num1temp [0] = toChar(tempProduct/10);
                    }
                    else
                    {
                        num1temp[index1] = toChar(tempProduct%10);
                    }
                }
                else
                {
                    num1temp[index1] = toChar(tempProduct % 10);
                    advanceDigit = tempProduct/10;
                }
            }
            if (index2 == num2size - 1)
            {
                numadd = num1temp;
            }
            else //adds products
            {
                int advance = 0;
                int tempindex = (int) num1temp.size() - 1;
                for (int addindex = (int)numadd.size() - indentation - 1; addindex >= 0; addindex--, tempindex--)
                {
                    int tempSum = toNum(numadd[addindex]) + toNum(num1temp[tempindex]) + advance;
                    numadd [addindex] = toChar (tempSum%10);
                    advance = tempSum/10;
                }
                for (int tempindex2 = tempindex; tempindex2 >= 0; tempindex2--)
                {
                    numadd = " " + numadd;
                    int tempSum = toNum(num1temp[tempindex2]) + advance;
                    numadd [0] = toChar(tempSum%10);
                    advance = tempSum/10;
                }
                if (advance != 0)
                {
                    numadd = " " + numadd;
                    numadd [0] = toChar(advance);
                }
            }
            indentation++;
        }
        return numadd;
    }
}

string add (string n1, string n2)
{
    string bigger;
    string smaller;
    if (n1.size() < n2.size())
    {
        bigger = n2;
        smaller = n1;
    }
    else
    {
        bigger = n1;
        smaller = n2;
    }
    int carry = 0;
    int lastindex = 0;
    for (int i = (int)(bigger.size() - 1), j = (int)(smaller.size() - 1); i >= 0 && j >= 0; i--, j--)
    {
        int d1 = toNum (bigger [i]);
        int d2 = toNum (smaller [j]);
        bigger [i] = toChar ((d1 + d2 + carry)%10);
        carry = (d1 + d2 + carry)/10;
        lastindex = i;
    }
    string temp = "";
    for (int i = lastindex - 1; i >= 0; i--)
    {
        int d = toNum (bigger [i]);
        temp += toChar ((d + carry)%10);
        carry = (d + carry)/10;
    }
    if (carry != 0)
    {
        temp += toChar (carry);
    }
    reverse(temp.begin(), temp.end());
    return bigger.replace(0, lastindex, temp);
}


string multiply (int n11, int n12, int n21, int n22)
{
    if (n11 > n12 || n21 > n22)
    {
        return "0";
    }
    if (n12 - n11 + 1 < 10 && n22 - n21 + 1 < 10)
    { 
        return to_string (stoll(num1.substr(n11, n12 - n11+1))*stoll(num2.substr(n21, n22 - n21 + 1)));
    }
    string ac = multiply (n11, (n11 + n12)/2, n21, (n21 + n22)/2);
    for (int x = 0; x < (n11 + n12)/2 + (n21 + n22)/2; x++)
    {
        ac.append ("0");
    }
    string ad = multiply (n11, (n11 + n12)/2, (n21 + n22)/2 + 1, n22);
    for (int x = 0; x < (n11 + n12)/2; x++)
    {
        ad.append ("0");
    }
    string bc = multiply ((n11 + n12)/2 + 1, n12, n21, (n21 + n22)/2);
    for (int x = 0; x < (n21 + n22)/2; x++)
    {
        bc.append ("0");
    }
    string bd = multiply ((n11 + n12)/2 + 1, n12, (n21 + n22)/2 + 1, n22);
    return add(add(add(ac, ad), bc), bd);
}

string multiply (string n1, string n2)
{
    if ((int)n1.size() < 10 && (int)n2.size() < 10)
    {
        return to_string (stoll(n1)*stoll(n2));
    }
    if ((int)n1.size() < 100 && (int)n2.size() < 100)
    {
        return slowmulti (n1, n2);
    }
    if ((int)n1.size()%2 == 1)
    {
        n1 = "0" + n1;
    }
    if ((int)n2.size()%2 == 1)
    {
        n2 = "0" + n2;
    }
    
    int size1 = (int)n1.size()/2;
    int size2 = (int)n2.size()/2;
    
    string a = n1.substr(0, size1);
    string b = n1.substr(size1, size1);
    string c = n2.substr(0, size2);
    string d = n2.substr(size2, size2);
    
    string ac = multiply (a, c);
    for (int x = 0; x < size1 + size2; x++)
    {
        ac.append ("0");
    }
    string ad = multiply (a, d);
    for (int x = 0; x < size1; x++)
    {
        ad.append ("0");
    }
    string bc = multiply (b, c);
    for (int x = 0; x < size2; x++)
    {
        bc.append ("0");
    }
    string bd = multiply (b, d);
    string result = add(add(add(ac, ad), bc), bd);
    string res = "";
    int x = 0;
    while (result [x] == '0')
    {
        x++;
    }
    while (x < (int) result.size())
    {
        res += result [x];
        x++;
    }
    return res;
    
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> num1;
    cin >> num2;
    cout << multiply (0, (int)num1.size() - 1, 0, (int)num2.size() - 1) << endl;
    return 0;
}
