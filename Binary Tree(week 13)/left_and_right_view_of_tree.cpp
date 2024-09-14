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
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createTree()
{
    cout << "Entering the value of node: " << endl;
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }
    // create Node
    Node *root = new Node(value);
    cout << "Entering in left of: " << value << endl;
    root->left = createTree();
    cout << "Entering in right of: " << value << endl;
    root->right = createTree();
    return root;
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    cout << root->data << " ";

    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << endl;
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
void printLeftView(Node *root, int level, vector<int> &leftview)
{
    if (root == NULL)
    {
        return;
    }
    if (level == leftview.size())
    {
        // iska matlab mujhe left view ki node mil gyi hai
        leftview.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftview);
    printLeftView(root->right, level + 1, leftview);
}
void printRightView(Node *root, int level, vector<int> &rightview)
{
    if (root == NULL)
    {
        return;
    }
    if (level == rightview.size())
    {
        // iska matlab mujhe left view ki node mil gyi hai
        rightview.push_back(root->data);
    }
    printRightView(root->right, level + 1, rightview);
    printRightView(root->left, level + 1, rightview);
}
void printTopView(Node *root)
{
    map<int, int> hdToNodemap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;
        // if there is no entry for hd in map, then create a new entry
        if (hdToNodemap.find(hd) == hdToNodemap.end())
        {
            hdToNodemap[hd] = frontNode->data;
        }

        // chile ko dekhna hai
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout << "printing top view: " << endl;
    for (auto it : hdToNodemap)
    {
        cout << it.second << " ";
    }
}
void printBottomView(Node *root)
{
    map<int, int> hdToNodemap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;
        // if there is no entry for hd in map, then create a new entry
        hdToNodemap[hd] = frontNode->data;

        // chile ko dekhna hai
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout << "printing Bottom view: " << endl;
    for (auto it : hdToNodemap)
    {
        cout << it.second << " ";
    }
}
void printleftBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->left != NULL)
    {
        printleftBoundary(root->left);
    }
    else
    {
        printleftBoundary(root->right);
    }
}
void printleafNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printleafNode(root->left);
    printleafNode(root->right);
}
void printrightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        printrightBoundary(root->right);
    }
    else
    {
        printrightBoundary(root->left);
    }
    cout << root->data << " ";
}
void BoundaryTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // printleftBoundary(root);
    // printleafNode(root);
    // if (root->right != NULL)
    // {
    //     printrightBoundary(root->right);
    // }
    // else
    // {
    //     printrightBoundary(root->left);
    // }

    // A DIFFERENT EASY WAY TO OVERCOME THE IF AND ELSE CONDITIONS
    cout << root->data << " ";
    printleftBoundary(root->left);
    //a wrong answer can be formed by using the below statement
    //so rather doing this , break it into 2 left and right
    // printleafNode(root);
    printleafNode(root->left);
    printleafNode(root->right);
    printrightBoundary(root->right);
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

int main()
{
    Node *root = createTree();
    LevelOrderTraversal(root);
    // left view
    //  vector<int> leftview;
    //  printLeftView(root, 0, leftview);
    //  cout << "printing left view: " << endl;
    //  for (int i = 0; i < leftview.size(); i++)
    //  {
    //      cout<<leftview[i]<<" ";
    //  }
    //  vector<int> rightview;
    //  printRightView(root, 0, rightview);
    //  cout << "printing right view: " << endl;
    //  for (int i = 0; i < rightview.size(); i++)
    //  {
    //      cout<<rightview[i]<<" ";
    //  }
    // printTopView(root);
    // printBottomView(root);
    BoundaryTraversal(root);
    return 0;
}