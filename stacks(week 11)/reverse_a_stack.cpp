#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st,int &element){
    // base case
    if(st.empty()){
        st.push(element);
        return;
    }
    //ek case mai solve kar deta hu
    int temp=st.top();
    st.pop();

    // baaki recursion sambhal lega
    insertAtBottom(st,element);

    //backtracking
    st.push(temp);
}
void reverseStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }
    //ek case mai solve karunga
    int temp=st.top();
    st.pop();

    //baaki recursion
    reverseStack(st);

    //backtrack
    insertAtBottom(st,temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    // int element=400;
    // insertAtBottom(st,element);
    cout<<"without reverse:"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"after reverse:"<<endl;
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}