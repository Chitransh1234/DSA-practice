 #include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int> &st,int &element){
    //base case
    //when accesing the top element of the stack and when popping the element, check 
    //if it is not empty
    if(st.empty() || element>st.top()){
        st.push(element);
        return;
    }
    //EK CASE SAMBHALNA HAI
    int temp=st.top();
    st.pop();

    // recursion
    insertSorted(st,element);

    //backtrack
    st.push(temp);
}
void sortStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }
    //ek case mai solve karunga
    int temp=st.top();
    st.pop();
    //recursion sambhalega
    sortStack(st);
    //backtrack
    insertSorted(st,temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(7);
    st.push(12);
    st.push(5);
    st.push(11);
    int element=50;
    // insertSorted(st,element);
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
} 