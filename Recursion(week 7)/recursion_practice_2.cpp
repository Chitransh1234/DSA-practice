#include<iostream>
using namespace std;
void printArray(int *arr, int size, int index) {
	//base case
	if(index >= size) {
		return ;
	}
	//processing
	cout << arr[index] << " ";
	//recursive call
	printArray(arr, size, index+1);
}
bool searchArray(int arr[],int size,int target,int index){
    //base case
    if(index >= size){
        return false;
    }
    //processing
    if(arr[index]==target){
        return true;
    }
    //recursive call
    bool aagekaAns=searchArray(arr,size,target,index+1);
    return aagekaAns;
}
// void searchArray(int arr)
int main(){
    int arr[]={10,20,30,40,50};
    int index=0;
    int size=5;
    int target=70;
    cout <<"Tagret found or not: "<< searchArray(arr,size,target, index) << endl;   
    printArray(arr,size,index);
}