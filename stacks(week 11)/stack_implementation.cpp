#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    void push(int data)
    {
        if (top ==size - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    int getsize()
    {
        return top + 1;
    }
    //just to check that other funtions is working or not.
    void print(){
        cout<<"Top: "<<top<<endl;
        cout<<"Top element: "<<getTop()<<endl;
        cout<<"stack:";
        for(int i=0;i<getsize();i++){
            cout<<arr[i]<<" ";
        }
            cout<<endl;
    }
};
int main()
{   
    //creation
    stack st(8);
    st.push(10);
    st.print();
    st.push(20);
    st.print();
    st.push(30);
    st.print();
    // st.pop();
    // st.print();
    // st.pop();
    // st.print();
    // st.pop();
    // st.print();
    cout<<"Top element:"<<st.getTop()<<endl;
    cout<<endl<<"Size of stack:"<< st.getsize()<<endl;
    if(st.isempty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

    
    return 0;
}