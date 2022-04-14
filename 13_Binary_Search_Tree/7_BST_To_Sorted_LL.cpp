#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class Pair
{
public:
    Node<int> *head;
    Node<int> *tail;
};

Pair BST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node<int> *node = new Node<int>(root->data);
    Pair leftAns = BST(root->left);
    Pair rightAns = BST(root->right);
    Pair ans;

    if (leftAns.head == NULL && rightAns.head == NULL)
    {
        ans.head = node;
        ans.tail = node;
    }
    else if (leftAns.head == NULL && rightAns.head != NULL)
    {
        ans.head = node;
        node->next = rightAns.head;
        ans.tail = rightAns.tail;
    }
    else if (leftAns.head != NULL && rightAns.head == NULL)
    {
        ans.head = leftAns.head;
        leftAns.tail->next = node;
        ans.tail = node;
    }
    else
    {
        ans.head = leftAns.head;
        leftAns.tail->next = node;
        node->next = rightAns.head;
        ans.tail = rightAns.tail;
    }
    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return BST(root).head;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}