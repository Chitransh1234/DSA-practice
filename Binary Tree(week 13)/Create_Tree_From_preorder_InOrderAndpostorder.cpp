#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

    // while (q.size()>1)
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            // galti hui thi yha , dubara null push kar rha tha
            // infintite loop me fs gya
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // valid node vala case
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
int searchInorder(int inOrder[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == target)
        {
            return i;
        }
    }
    return -1;
}
void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node *constructTreeFromPreAndInorderTraversal(map<int, int> &valueToIndexMap, int preOrder[], int inOrder[], int &postIndex, int inorderStart, int inorderEnd, int size)
{
    // base case
    if (postIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }
    // 1 case mai solve karta hu baaki rec kar lega
    int element = preOrder[postIndex];
    postIndex++;
    Node *root = new Node(element);
    // element search karna padega inorder me
    //  int position = searchInorder(inOrder,size,element);
    int position = valueToIndexMap[element];
    // baaki recursion sambhal lega
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, postIndex, position + 1, inorderEnd, size);
    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, postIndex, inorderStart, position - 1, size);
    return root;
}
Node *constructTreeFromPostAndInorderTraversal(map<int, int> &valueToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inorderStart, int inorderEnd, int size)
{
    // base case
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }
    // 1 case mai solve karta hu baaki rec kar lega
    int element = postOrder[postIndex];
    postIndex--;
    Node *root = new Node(element);
    // element search karna padega inorder me
    //  int position = searchInorder(inOrder,size,element);
    int position = valueToIndexMap[element];
    // baaki recursion sambhal lega
    // right ki call pehle lagegi
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, position + 1, inorderEnd, size);
    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inorderStart, position - 1, size);
    return root;
}
int main()
{
    // int inorder[]={10,8,6,2,4,12};
    // int preOrder[]={2,8,10,6,4,12};
    // int size=6;
    // int preOrderIndex=0;
    // int inorderStart=0;
    // int inorderEnd=5;
    // map<int,int> valueToIndexMap;
    // createMapping(inorder,size,valueToIndexMap);
    // Node* root=constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inorder,preOrderIndex,inorderStart,inorderEnd,size);
    int inOrder[] = {8, 14, 6, 2, 10, 4};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int inorderStart = 0;
    int inorderEnd = 5;
    int size = 6;
    int postIndex = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);
    cout << "printing the entire tree: " << endl;
    Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inorderStart, inorderEnd, size);
    LevelOrderTraversal(root);
    return 0;
}