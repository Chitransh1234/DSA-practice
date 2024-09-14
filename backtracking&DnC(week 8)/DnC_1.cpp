#include<iostream>
using namespace std;
void merge
int mergeSort(int arr[],int s,int e){
    //base case
    if(s>e){
        //invalid array(empty array)
        return;
    }
    if(s==e){
        //single element
        return;
    }
    //break
    int mid=(s+e)/2;
    //s->mid->left
    //mid+1->e->right

    //recursion bhaiya ko bulao
    //left and right arrays ko sort karao
}
int main(){
    int arr[]={2,1,6,9,4,5};
    int size=6;
    int s=0;
    int e=size-1
    mergeSort(arr,s,e);
}