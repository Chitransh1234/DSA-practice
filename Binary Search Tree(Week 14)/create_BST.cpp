#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertIntoBST(Node *root, int data)
{
    // base case(first node)
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // its not the first node
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void createBST(Node *&root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data:" << endl;
        cin >> data;
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void preorder(Node *root)
{
    // NLR
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    // LRN
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
Node *minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MIN Value" << endl;
        return NULL;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MAX Value" << endl;
        return NULL;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
bool searchInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    // 1 case mujhe solve karna hai
    if (root->data == target)
    {
        return true;
    }
    // baaki recursion sambhalega
    // left ya right
    bool leftAns = false;
    bool rightAns = false;
    if (target < root->data)
    {
        leftAns = searchInBST(root->left, target);
    }
    else
    {
        rightAns = searchInBST(root->right, target);
    }
    return leftAns || rightAns;
}
Node *deleteFromBST(Node *root, int target)
{
    // target ko dhundo
    // target ko delete karo
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        // ab delete karenge
        // 4 cases

        if (root->left == NULL && root->right == NULL)
        {
            // 1.case->leaf node vala
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            // 2.case->left non NULL and right NULL
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // 3.case->left NULL and right NON NULL
            Node *chilldSubtree = root->right;
            delete root;
            return chilldSubtree;
        }

        // 4.case-> left NON NULL and right NON NULL
        else
        {
            // a-> left subtree ki max value lao
            Node *maxi = maxValue(root->left);
            // replacement
            root->data = maxi->data;

            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        // target left me exist karta hoga
        // niche vali line me galti ki thi
        // root->left me store nhi karya direct return kar diya tha
        // delete kara toh denge but use link karna bahut jaruri hai
        root->left = deleteFromBST(root->left, target);
    }
    else
    {
        // target right me exist karta hoga
        // niche vali line me galti ki thi
        // root->right me store nhi karya direct return kar diya tha
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}
Node *BSTfromInorder(int inorder[], int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    // 1st case solving
    int mid = s + (e - s) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    // baaki recursion
    root->left = BSTfromInorder(inorder, s, mid - 1);
    root->right = BSTfromInorder(inorder, mid + 1, e);

    return root;
}
// convert this BST into a sorted doubly linked list
void convertBSTtoDLL(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // RNL

    // R
    convertBSTtoDLL(root->right, head);
    // N
    //attaching next pointer of current node to head of LL
    root->right = head;
    //attaching prev pointer of head of LL to current node
    if (head != NULL)
    {
        head->left = root;
    }
    //head update
    head = root;

    //L
    convertBSTtoDLL(root->left,head);
}
Node* convertDLLtoBST(Node* &head,int n){
    //base case
    if(head==NULL||n<=0){
        return NULL;
    }
    //LNR
    // cout<<"Solving left part"<<endl;
    //L
    Node* leftSubTree=convertDLLtoBST(head,n/2);
    //N
    // cout<<"creating current node"<<endl;
    Node*root=head;
    root->left=leftSubTree;
    //head update 
    head=head->right;

    //R
    // cout<<"solving right part"<<endl;
    Node* rightSubTree=convertDLLtoBST(head,n-n/2-1);
    root->right=rightSubTree;
    return root;

}
void printLinkedList(Node* head){
        Node* temp=head;
        cout<<"printing the entire linked list:"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->right;
        }
    }
int main()
{
    // Node* first=new Node(10);
    // Node* second=new Node(20);
    // Node* third=new Node(30);
    // first->right=second;
    // second->left=first;
    // second->right=third;
    // third->left=second;
    // Node* head=first;
    // //10<-->20<-->30
    // Node* root=convertDLLtoBST(head,3);
    // levelOrderTraversal(root);
//     int inorder[] = {10, 20, 30, 40, 50, 60, 70};
//     int size = 7;
//     int start = 0;
//     int end = size - 1;
//     Node *root = BSTfromInorder(inorder, start, end);
//     levelOrderTraversal(root);
//     Node* head=NULL;
//     convertBSTtoDLL(root,head);
//     printLinkedList(head);
    // Node *root = NULL;
    // createBST(root);
    // levelOrderTraversal(root);
    // cout << endl
    //      << "Inorder: ";
    // inorder(root);
    // cout << endl
    //      << "Preorder: ";
    // preorder(root);
    // cout << endl
    //      << "Postorder: ";
    // postorder(root);
    // cout << endl;
    // Node *minNode = minValue(root);
    // if (minNode == NULL)
    // {
    //     cout << "there is no node in tree, so no min value" << endl;
    // }
    // else
    // {
    //     cout << "Min Value:" << minNode->data << endl;
    // }
    // Node *maxNode = maxValue(root);
    // if (maxNode == NULL)
    // {
    //     cout << "there is no node in tree, so no min value" << endl;
    // }
    // else
    // {
    //     cout << "Max Value:" << maxNode->data << endl;
    // }
    // int target = -1;
    // cout << "Enter the value of target:" << endl;
    // cin >> target;
    // while (target != -1)
    // {
    //     root = deleteFromBST(root, target);
    //     cout << "Printing Level Order Traversal: " << endl;
    //     levelOrderTraversal(root);

    //     cout << "Enter the value of target: " << endl;
    //     cin >> target;
    // }
    // int target;
    // cout << "Enter the target: " << endl;
    // cin >> target;
    // while (target != -1)
    // {
    //     bool ans = searchInBST(root, target);
    //     if (ans == true)
    //     {
    //         cout << "Found" << endl;
    //     }
    //     else
    //     {
    //         cout << "Not found" << endl;
    //     }
    //     cin >> target;
    // }

    

    return 0;
    // 50 30 60 25 40 70 80 55 -1
}