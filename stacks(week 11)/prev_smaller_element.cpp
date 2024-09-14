#include<iostream>
#include<stack>
#include<vector>
using namespace std;
    
int main(){
    int arr[5]={8,4,6,2,3};
    int size=5;
    vector<int> ans(size);
    ans=prevSmallerElement(arr,size,ans);
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}