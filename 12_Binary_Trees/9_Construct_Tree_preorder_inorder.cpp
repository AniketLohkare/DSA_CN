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

BinaryTreeNode<int> *buildTreeHelper(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd)
{
    // Base Case
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    // Building root node
    int rootVal = preorder[preStart];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);

    // Finding root val in inorder
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (rootVal == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }

    int lInStart = inStart;
    int lInEnd = rootIndex - 1;
    int lPreStart = preStart + 1;
    int lPreEnd = lInEnd + lPreStart - lInStart;

    int rPreStart = lPreEnd + 1;
    int rPreEnd = preEnd;
    int rInStart = rootIndex + 1;
    int rInEnd = inEnd;

    root->left = buildTreeHelper(preorder, lPreStart, lPreEnd, inorder, lInStart, lInEnd);
    root->right = buildTreeHelper(preorder, rPreStart, rPreEnd, inorder, rInStart, rInEnd);
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    int preStart = 0;
    int preEnd = preLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;

    return buildTreeHelper(preorder, preStart, preEnd, inorder, inStart, inEnd);
}

int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}