#include <iostream>
using namespace std;
int x = 6; // Global variable

void fun(){
    int x=60;
    cout<<x<<endl;
    ::x=40;
    cout<<::x<<endl;
}
int main() // scope is from line 5 to 10 ( between curly brackets)
{
    x = 4;             // global x
    int x = 20;        // local to main function
    cout << x << endl; // most local variable ko jyada preference milti hai

    cout << ::x << endl; // accessing Global with ::
    {
        int x = 50;
        {
            int x=44;// scoped between 20 and 23
            cout<<x<<endl;
        }
        cout << x << endl;
        cout<<::x<<endl;
    }
    fun();
    return 0;
}