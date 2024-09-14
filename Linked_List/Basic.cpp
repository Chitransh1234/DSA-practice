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
    ~Node()
    {
        cout << "Destructor called for:" << this->data << endl;
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
    // ASSUMPTION: POSITION KI VALUE [1 TO LENGTH+1] TK
    //  if (position < 1)
    //  {
    //      cout << "Cannot insert,please enter a valid position" << endl;
    //      return;
    //  }
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

void deleteNode(Node *&head, Node *&tail, int position)
{
    // empty list
    if (head == NULL)
    {
        cout << "cannot delete,coz LL is empty" << endl;
    }
    if(head==tail){
        //single element
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    int len = findLength(head);
    // delete from head
    if (position == 1)
    {
        // first node ko delete kardo
        Node *temp = head;
        // head=temp->next;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if (position == len)
    {
        // last node ko delete kar do

        // find prev
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        // prev node ka link null karo
        prev->next = NULL;

        // node delte kro
        delete tail;

        // update tail
        tail = prev;
    }
    else
    {
        // middle me koi node ko delete karna hai
        // step1: set prev/curr pointers
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }

        // step2: prev->next me curr ka next node add kro.
        prev->next = curr->next;
        // step3: node isolate krdo.
        curr->next = NULL;
        delete curr;
    }
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 50);
    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 10);
    // printLL(head);
    // cout<<endl;
    // deleteNode(head,tail,1);
    // printLL(head);
    // cout<<endl;
    cout << "Before-> Length of LL is: " << findLength(head) << endl;
    // cout << "before -> head -> " << head -> data << endl;
    cout << "Before tail-> " << tail->data << endl;
    deleteNode(head, tail, 1);
    cout << "After Length of LL is: " << findLength(head) << endl;
    cout << "After tail-=> << " << tail->data << endl;
    // deleteNode(head,tail,5);
    // printLL(head);
    // cout<<endl;
    // deleteNode(head,tail,1);
    // printLL(head);
    // cout<<endl;
    // insertAtPosition(head, tail, 1000, 5);
    // printLL(head);
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