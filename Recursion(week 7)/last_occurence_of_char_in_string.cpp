#include<iostream>
using namespace std;

void lastOcc(string &s, char x,int i , int &ans){
    //base case
    if(i>=s.size()){
        return;
    }
    //ek case mai solve karunga
    if(s[i] == x){
        ans = i;
    }
    //else mai recursion call karunga
    lastOcc(s,x,i+1,ans);

}
int main(){
    string s;
    cin>>s;
    int ans = -1;
    char x;
    cin>>x; 
    lastOcc(s,x,0,ans);
    cout<<ans<<endl;
    return 0;
}