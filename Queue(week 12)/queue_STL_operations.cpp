#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creation
    queue<int> q;
    //insertion
    q.push(5);

    //size
    cout<<"Size of Queue: "<< q.size()<<endl;

    //empty
    if(q.empty()==true){
        cout<<"Queue is not empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    //remove
    q.pop();

    //size
    cout<<"Size of Queue: "<< q.size()<<endl;

    //empty
    if(q.empty()==true){
        cout<<"Queue is not empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"Front element of queue is :"<<q.front()<<endl;
    cout<<"last element of queue is :"<<q.back()<<endl;
    return 0;
}