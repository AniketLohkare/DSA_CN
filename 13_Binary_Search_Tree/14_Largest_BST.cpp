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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
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
#include <bits/stdc++.h>

class largestBSTSubtreeReturn
{
public:
    int minimum;
    int maximum;
    int height;
    bool isBST;
};

largestBSTSubtreeReturn largestBSTSubtreeHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        largestBSTSubtreeReturn ans;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        ans.height = 0;
        ans.isBST = true;
        return ans;
    }

    largestBSTSubtreeReturn left = largestBSTSubtreeHelper(root->left);
    largestBSTSubtreeReturn right = largestBSTSubtreeHelper(root->right);

    int minimum = min(root->data, min(left.minimum, right.minimum));
    int maximum = max(root->data, max(left.maximum, right.maximum));

    bool isBSTFinal = (root->data > left.maximum) && (root->data < right.minimum) && left.isBST && right.isBST;

    largestBSTSubtreeReturn ans;
    ans.minimum = minimum;
    ans.maximum = maximum;
    if (isBSTFinal)
    {
        ans.height = 1 + max(left.height, right.height);
    }
    else
    {
        ans.height = max(left.height, right.height);
    }
    ans.isBST = isBSTFinal;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return largestBSTSubtreeHelper(root).height;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}