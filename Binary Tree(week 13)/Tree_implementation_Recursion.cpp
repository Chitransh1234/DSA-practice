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
        this->right = NULL;
        this->left = NULL;
    }
};
// it returns root node of the created tree
Node *createTree()
{
    cout << "Enter the value for node:" << endl;
    int data;
    cin >> data;
    // base case
    if (data == -1)
    {
        return NULL;
    }
    // Step1: create Node
    Node *root = new Node(data);
    // step2: create left subtree
    //  cout<<"Left of Node: "<<root->data<<endl;
    root->left = createTree();
    // step3: create right subtree
    //  cout<<"Right of Node: "<<root->data<<endl;
    root->right = createTree();
    return root;
}
void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // N L R
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // L N R
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // L R N
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // asli traversal start krte hai
    // while (q.size()>1)
    while(!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            // galti hui thi yha , dubara null push kar rha tha
            //infintite loop me fs gya
            if(!q.empty()){
            q.push(NULL);
            }
        }
        else
        {
            //valid node vala case
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    Node *root = createTree();
    // cout << root->data << endl;
    cout << "Printing Pre-order: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Printing In-order: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Printing Post-order: ";
    postOrderTraversal(root);
    cout << endl;
    cout << "Printing Level-order: ";
    LevelOrderTraversal(root);
    cout << endl;
    // 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1

    return 0;
}