#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // default constructor
    Node()
    {
        // cout<<"I am inside def constructor"<<endl;
        this->next = NULL;
    }
    Node(int data)
    {
        // cout<<"I am inside parameterized constructor"<<endl;

        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void getLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    cout << length << endl;
}
int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // Corner case
    if (head == NULL)
    {
        // empty LL
        //  step 1: create new NOde
        Node *newNode = new Node(data);
        // step2:update head
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non-empty LL wala case.
        // Create a new node
        Node *newNode = new Node(data);

        // attach new node to head node
        newNode->next = head;
        // update head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL
        // step1:create new node
        Node *newNode = new Node(data);
        // step2:single node h entire LL me
        // that's why head and tail ko ispe point kara do
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non-empty LL
        // step1:create new node
        Node *newNode = new Node(data);
        // step2:tail node ko attach kardo new node se
        tail->next = newNode;
        // step3:update tail
        tail = newNode;
    }
}
void createTail(Node *head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // jab ye loop khtm ho gya hoga
    // then aapka temp wala pointer
    // khada hoga last node pr
    // tab tail=temp krke, tail ko last node pr le aao
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // if (position < 1)
    // {
    //     cout << "Cannot insert,please enter a valid position" << endl;
    //     return;
    // }
    int length = findLength(head);

    if (position == 1)
    {
        insertAtHead(head, tail, data);
    }
    // else if(position == length+1){
    //     //mistake done in above line.
    //     insertAtTail(head,tail,data);
    // }
    else if (position == length + 1)
    {
        // mistake done in above line.
        insertAtTail(head, tail, data);
    }
    else
    {
        // insert at middle of linked list

        // step1:create a new Node
        Node *newNode = new Node(data);
        // step2: traverse curr/prev to the position
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        // step3:attach prev to new Node
        prev->next = newNode;
        // step4:attach newNode to curr
        newNode->next = curr;
    }
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 50);
    printLL(head);

    insertAtPosition(head, tail, 1000, 5);
    printLL(head);
    // creation of Node
    // Node a;
    //  Node *head=new Node();
    //  Node* first=new Node(10);
    //  Node* second=new Node(20);
    //  Node* third=new Node(30);
    //  Node* fourth=new Node(40);
    //  Node* fifth=new Node(50);

    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;
    // //linked list bn chuki hai
    // Node *head=first;
    // Node *tail=fifth;
    // insertAtHead(head,tail,5);
    // insertAtTail(head,tail,500);
    // cout<<"Printing the entire LL:"<<endl;
    // printLL(head);

    // cout<<"Length of Linked list:";
    // getLength(head);
    // //insert in the beginning of the linked list.

    return 0;
}