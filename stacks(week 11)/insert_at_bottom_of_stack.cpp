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
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    int element=400;
    insertAtBottom(st,element);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}