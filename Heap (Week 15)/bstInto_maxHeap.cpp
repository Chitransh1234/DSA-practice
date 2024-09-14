#include<iostream>
using namespace std;

class Node{
    
}
void storeInorderTraversal(Node* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    //LNR
    storeInorderTraversal(root->left,in);
    in.push_back(root->data);
    storeInorderTraversal(root->right,in);

}
void replaceUsingPostOrder(Node* root,vector<int>in,int &index){
    if(root==NULL){
        return;
    }
    //LRN
    replaceUsingPostOrder(root->left,in,index);
    replaceUsingPostOrder(root->right,in,index);
    root->data=in[index];
}
void convertBSTIntoMaxHeap(Node* root){
    //1 step
    vector<int> inorder;
    int index=0;
    storeInorderTraversal(root,inorder);
    //replace the nodes value with the sorted inorder values using the postorder traversal
    replaceUsingPostOrder(root,inorder,index);
    return root;
}
int main(){

}