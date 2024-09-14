#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int findLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // if LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty.
        Node *newNode = new Node(data);
        head->prev = newNode;
        // the above and below lines can be swaped their positions.
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // if LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty.
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtPostion(Node *&head, Node *&tail, int data,int pos){
    if(head==NULL){
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
    }
    else {
        int length=findLength(head);
        if(pos==1){
            insertAtHead(head,tail,data);
        }
        else if(pos==length+1){
            insertAtTail(head,tail,data);
        }
        else{
            //insert in middle
            //step1:create node
            Node* newNode=new Node(data);
            //step2:set prev and set
            Node* prevNode=NULL;
            Node* currNode=head;
            while(pos!=1){
                pos--;
                prevNode=currNode;
                currNode=currNode->next;
            }
            //step3: pointers update kar rhe the
            prevNode->next=newNode;
            newNode->prev=prevNode;
            newNode->next=currNode;
            currNode->prev=newNode;
        }
    }
}
void deleteNode(Node* &head,Node* &tail,int position){
    if(head==NULL){
        //LL is empty
        cout<<"Cannot delete, coz LL is empty"<<endl;
        return;
    }
    if(head==tail){
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
    }
    int length=findLength(head);
    if (position ==1){
        //delete from tail
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
    }
    else if(position==length){
        //delete from tail
        Node *prevNode= tail->prev;
        prevNode->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail =prevNode;
    }
    else{
        //delete from middle
        // step1: set prevNode/currNode/nextNode
        Node* prevNode= NULL;
        Node* currNode=head;
        while (position!=1)
        {
            position--;
            prevNode=currNode;
            currNode=currNode->next;
        }
        Node* nextNode =currNode->next;
        
        prevNode->next=nextNode;
        currNode->prev=NULL;
        currNode->next=NULL;
        nextNode->prev=prevNode;
        delete currNode;
    }
    

}

int main()
{
    // Node* head=new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    print(head);
    cout<<endl;
    // insertAtTail(head,tail,1000);
    // insertAtPostion(head,tail,1000,6);
    deleteNode(head,tail,4);
    print(head);
    cout<<endl;
    
    return 0;
}