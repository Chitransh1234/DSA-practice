#include <iostream>
#include <vector>
using namespace std;
void checkEvenOdd(int n)
{
    if (n & 1)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "even" << endl;
    }
}
int getIthBit(int n, int i)
{
    int mask = (1 << i);
    // ans=n& mask;
    if (mask & n == 0)
        cout << "bit->0" << endl;
    else
        cout << "bit->1" << endl;
}

void setIthBit(int n, int i)
{
    int mask = (1 << i);
    n = n | mask;
    cout << "updated number:" << n << endl;
    ;
}
void clearIthBit(int n, int i)
{
    // method by takying &
    int mask = ~(1 << i);
    n = n & mask;
    cout << "updated number:" << n << endl;
    // other way by taking xor
    //  int mask=(1<<i);
    //  n=n^mask;
    //  cout<<"updated number:"<<n<<endl;
}
void updateIthBit(int n, int i, int target)
{
    // clear ith bit
    clearIthBit(n, i);
    // create mask
    int mask = (target << i);
    n = n | mask;
    cout << "updated number:" << n << endl;
}
void clearLastIBits(int n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
    cout << "updated number:" << n << endl;
}
bool checkPowerOf2(int n)
{
    // count set bit
    int count = 0;
    while (n != 0)
    {
        int lastbit = n & 1;
        if (lastbit)
        {
            count++;
        }
        n = (n >> 1);
    }
    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool fastCheckPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
    {
        return true;
    }
    else
        return false;
}
int fastCountSetbits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n = (n & (n - 1));
    }
    return count;
}
void clearBitsInRange(int n, int i, int j)
{
    int a = (-1 << (i + 1));
    int b = ~(-1 << j);
    int mask = a | b;
    n = n & mask;
    cout << "updated number:" << n << endl;
}
void getSubsequences(string str)
{
    int n = str.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        // number is ready
        // use num to create subsequences
        //  num->set bit ->index->char ->incl
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            // i->represent index
            char ch = str[i];
            // agar i index pr num ke andr set bit present hai
            // toh character ko include karlo
            if (num & (1 << i))
            {
                temp.push_back(ch);
            }
        }
        ans.push_back(temp);
    }
    cout << "printing the subsequences:" << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
}
int main()
{
    string str = "abc";
    getSubsequences(str);
    // int n=1023;
    // int i=8;
    // int j=1;
    // clearBitsInRange(n,i,j);
    // int n=15;
    // checkEvenOdd(n);
    // int i=2;
    // int target=1;
    // getIthBit(n,i);
    // setIthBit(n,i);
    // clearIthBit(n,i);
    // updateIthBit(n,i,target);
    // clearLastIBits(n,i);
    // int n=16;
    // cout<<fastCountSetbits(n)<<endl;
    // cout<<checkPowerOf2(n)<<endl;
    // cout<<fastCheckPowerOf2(n)<<endl;
    return 0;
}