#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*  next;
    Node(){
        cout<<"i am inside default ctor "<<endl;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void printLL(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int lengthLL(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
//deletion in singly linked list
void deleteNode(Node* &head,Node* &tail,int position){
    //empty list
    if(head==NULL){
        cout<<"Cannot delete,coz LL is empty"<<endl;
        return;
    }
    //delete from head
    if(position==1){
        //first node ko delete kardo

    }

}
int main(){
//CREATION OF OBJECT 
    Node a;//static object 
    //dynamically allocated object 
    // Node* head= new Node();
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth =new Node(50);
    first->next=second;
    second->next =third;
    third->next=fourth;
    fourth->next=fifth;

    Node* head=first;
    printLL(head);
    cout<<endl;
    cout<<"Length of LL is :"<<lengthLL(head);
    return 0;
}