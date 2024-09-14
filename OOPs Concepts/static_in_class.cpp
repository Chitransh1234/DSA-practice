#include<iostream>
using namespace std;

class abc{
    public:
    static int x,y;
    void print() const{
        //this pointer.
        cout<<x<<" "<<y<<endl;
        // no this pointer accessible.
        printf("I am in Static %s\n",__FUNCTION__);
    }
};
int abc::x;
int abc::y;
int main(){
    abc obj1;
    
    obj1.x=1;
    obj1.y=2;// or abc::y=2;
    obj1.print();// or abc::print();
    abc obj2;
    obj2.x=10;// or abc::x=10;
    obj2.y=20;
    obj1.print();
    obj2.print();


    return 0;
}