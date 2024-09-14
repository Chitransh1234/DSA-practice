#include<iostream>
#include <string>
#include <vector>

using namespace std;
class person{
    public:
    void walk()
    {
        cout<<"walking.."<<endl;
    }
};
class teacher: virtual public person{
    public:
    void teach(){
        cout<<"Teaching.."<<endl;
    }
};
class researcher: virtual public person{
    public:
    void research(){
        cout<<"Researching.."<<endl;
    }
};
//multiple inheritance
class professor:public teacher,public researcher{
    public:
    void bore(){
        cout<<"boring.."<<endl;
    }
};
int main(){
    professor p;
    
    //Diamond problem
    //Solution 1: Scope Resolution
    // p.teacher::walk();
    // p.researcher::walk();

    //Solution 2: using virtual
    p.walk();
    return 0;
}