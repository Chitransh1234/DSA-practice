#include <iostream>
using namespace std;
class abc
{
    // mutable int x; don't use mutable , it should be for debugging purpose.
    int x;
    int *y;
    const int z;

public:
    // abc()
    // {
    //     x = 0;
    //     y = new int(0);
    // }
    // ctor :old list
    // abc(int _x,int _y,int _z=0){//default argument
    //     x=_x;
    //     y=new int(_y);
    //     z=_z;
    // }

    // initialization list
    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z)
    {
        cout << "in init list" << endl;
        *y = *y * 10;
        
    }

    int getX() const
    {
        // x=10; //nhi hoga
        return x;
    }
    void setX(int _val)
    {
        x = _val;
    }
    int getY() const
    {
        return *y;
    }

    void setY(int _val)
    {
        *y = _val;
    }
    int getZ() const
    {
        return z;
    }
};
void printABC(const abc &a)
{
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}
int main()
{
    abc a(1, 2, 3);
    printABC(a);
    // cout<<a.getX()<<endl;
    // cout<<a.getY()<<endl;

    return 0;
}
int main2()
{
    // const int x = 5; // x is const
    // initialisation can be done
    // but we can't re-assign a value
    // x=10; can not be done
    // below is the old way of changing the value of const keyword,
    // used in old C based compilers
    // int *p=&x;
    // *p=10;
    // cout << x << endl;

    // 2. const with pointer
    // const int *a = new int(2);// CONST data,NON-CONST pointer
    // OR
    // int const *a =new int(2);
    // cout << *a << endl;
    // // *a = 20;//can't change the content of pointer
    // int b=20;
    // a=&b;//pointer itself can be reassigned.
    // cout<<*a<<endl;
    // // delete a;
    // int b = 5;
    // a = &b;
    // cout << *a << endl;

    // CONST POINTER, BUT NON-CONST data.
    // int *const a = new int(3);
    // cout << *a << endl;

    // *a = 20; // chal jayega
    // cout << *a << endl;
    // int b = 50;
    // a=&b;//nahi chalega ,CONST pointer

    // Const Pointer,Const data
    //  const int *const a =new int(10);
    //  cout<<*a<<endl;
    //  *a=50;
    //  int b=100;
    //  a=&b;
    return 0;
}