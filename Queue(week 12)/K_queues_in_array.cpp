#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class KQueue{
    public:
    int n,k,freeSpot;
    int *arr,*front,*rear,*next;
    KQueue(int _n,int _k):n(_n),k(_k),freeSpot(0){
        arr=new int[n];
        next=new int[n];
    }
}