#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    // cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        // cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        // cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int depth(BinaryTreeNode<int> *root, int node)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == node)
    {
        return 0;
    }

    int lDepth = depth(root->left, node);
    if (lDepth != -1)
    {
        return 1 + lDepth;
    }
    else
    {
        int rDepth = depth(root->right, node);
        if (rDepth != -1)
        {
            return 1 + rDepth;
        }
    }
    return -1;
}

bool isSibling(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->left != NULL && root->right != NULL)
    {
        if (root->left->data == p && root->right->data == q)
        {
            return true;
        }
        else if (root->left->data == q && root->right->data == p)
        {
            return true;
        }
        else
        {
            return isSibling(root->left, p, q) || isSibling(root->right, p, q);
        }
    }

    if (root->left != NULL && root->right == NULL)
    {
        return isSibling(root->left, p, q);
    }
    else
    {
        return isSibling(root->right, p, q);
    }
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == NULL)
    {
        return false;
    }

    int depth_p = depth(root, p);
    int depth_q = depth(root, q);

    if (depth_p == depth_q)
    {
        if (isSibling(root, p, q) == false)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if (isCousin(root, n1, n2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
