#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student{

    private:
        string gf;
        string gfname;
        // Student *this;
    public:
        // double a ;
        // double b;
        // char c;
        // bool absent;

        int id; 
        int age;
        string name;
        int nos; 
        bool present;
        //default constructor 
        //As constructor is mandatory
        // Student()
        // { 

        // }
        //ctor:Default ctor:assigns garbage value
        Student()
        {
            cout<<"Student ctor called"<<endl;
        }
        //parameterized ctor
        Student(int _id, int _age,string _name,int _nos,bool _present,string _gfname){
            id=_id;// or this->id=id;
            age=_age;
            name=_name;
            nos=_nos;
            present=_present;
            gfname=_gfname;
            cout<<"Student parameterized ctor called "<<endl;
        }
        void study(){
            cout<<"studying"<<endl;
        }
        void sleep(){
            cout<<"sleeping"<<endl;
        }
        void bunk(){
            cout<<"bunking"<<endl;
        }
        private:
            void gfchatting(){
                cout<<"chatting"<<endl;
            }
};
int main(){
    // int id1,id2;
    // string name1,name2;
    // int age1,age2;
    // int nos1,nos2;
    // int marks1[5],marks[2];
    //aise maza nhi aa rha
    // cout<<sizeof(Student)<<endl; // output comes 1.
    // Student s1;
    // cout<<s1.age<<endl;//gives garbage
    
    // Student s2(2,24,"gurnoor",5,0,"chutki");
    // cout<<s2.name<<endl;
    // cout<<s2.id<<endl;
    // s1.name="chitransh"; 
    // s1.age =20;
    // s1.id=1;
    // s1.nos=5;
    // s1.present=1;

    // Student s2;
    // s2.name="gurnoor"; 
    // s2.age =24;
    // s2.id=2;
    // s2.nos=5;
    // s2.present=0;
    // Student s3(2,15,"arsh",4,1,"arsh");
    // cout<<s3.name<<endl;


    // //allocating on heap
    // Student *s4=new Student(3,21,"chirag",5,1,"chirag");
    // cout<<s4->name<<endl;
    // cout<<(*s4).name<<endl;

    // delete s4; //NO LEAK
    Student s1(1,20,"chitransh",2,1,"chitransh");
    Student s2=s1;
    cout<<s1.name<<endl;
    cout<<s2.name<<endl;
    return 0;
    
}