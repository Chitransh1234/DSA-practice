#include<iostream>
#include<vector>
using namespace std;
int binarySearch_recursive(int arr[],int s,int e,int target){
    //base case
    if(s>e){
        return -1;
    }
    //processing-> 1 case khud solve karo
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
        return mid;
    }
    //baaki recursion solve kare lega
    if(arr[mid]<target){
        //right me jao
        return binarySearch_recursive(arr,mid+1,e,target);
    }
    else{
        //left me jao
        return binarySearch_recursive(arr,s,mid-1,target);
    }
}
bool checkSorted(int arr[],int size,int index){
    //Base case
    if(index>=size){
        return true;
    }
    //processing
    if(arr[index]>arr[index-1]){
        //aage check karna padega
        //ab recursion sambhalega
        bool aagekaAns= checkSorted(arr,size,index+1);
        return aagekaAns;
    }
    else{
        //sorted nhi hai
        return false;
    }
}
void findSubsequences(string str,string output,int index,vector<string> &ans){
    //base case
    if(index>=str.length()){
        //ans jo h, vo output string me build ho chuka hai
        //print kardo
        // cout<<"->"<<output<<endl;
        ans.push_back(output);
        return;
    }
    //processing
    char ch=str[index];
        // ---> Method 1 of include and exclude<---

    //include
    output.push_back(ch);
    findSubsequences(str,output,index+1,ans);
    //exclude
    output.pop_back();
    findSubsequences(str,output,index+1,ans);
        // ---> Method 2 of include and exclude<---

    //exclude
    // findSubsequences(str,output,index+1,ans);
    //include
    //output string me current character ko include kar do
    // output.push_back(ch);
    //baaki recusion dekh lega
    // findSubsequences(str,output,index+1,ans);

}
int main(){
    string str="abc";
    string output="";
    int index =0;
    vector<string> ans;
    findSubsequences(str,output,index,ans);

    cout<<"printing the subsequences in vector:"<<endl;
    for(string s: ans){
        cout<<"->"<<s<<endl;
    }
    // int arr[]={10,20,30,40,50,60,70,80};
    // int size=8;
    // int start=0;
    // int end=size-1;
    // int target=60;
    // int foundIndex =binarySearch_recursive(arr,start,end,target);
    // if(foundIndex !=-1){
    //     cout<<"target found at:"<<foundIndex<<endl;
    // }
    // else{
    //     cout<<"target not found"<<endl;
    // }
    // int arr[]={10,20,30,20,60,70};
    // int size=6;
    // int index=1;
    // bool isSorted= checkSorted(arr,size,index);
    // if(isSorted){
    //     cout<<"Array is sorted."<<endl;
    // }
    // else{
    //     cout<<"Array is not sorted."<<endl;
    // }
}