#include<iostream>
using namespace std;

class deque{
    public:
    int* arr;
    int size;
    int front;
    int rear;
    deque(int size){
        arr=new int[size];
        this->size=size;
        front=-1;
        rear=-1;
    }
    void pushback(int val){
        //Overflow
        //empty case
        //normal flow
        if(rear==size-1){
            cout<<"Overflow"<<endl;
        }
        else if(front==-1&&rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }

    }
    void pushFront(int val){
        //overflow
        if(front==0){
            cout<<"Overflow"<<endl;
        }
        else if(front==-1&& rear==-1){
            front++;
            rear++;
            arr[front]=val;
        }
        else{
            front--;
            arr[front]=val;
        }
    }
    void popFront(){
        //underflow
        // empty case->single element
        //normal flow
        if(front==-1&& rear==-1){
            cout<<"underflow"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    void popback(){
        //underflow
        //empty case->single element
        //normL FLOW
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else{
            arr[rear]=-1;
            rear--;
        }
    }
};

int main(){

}
