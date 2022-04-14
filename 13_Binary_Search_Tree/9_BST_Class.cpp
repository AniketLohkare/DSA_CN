#include <iostream>
using namespace std;

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

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (data < node->data)
        {
            node->left = remove(data, node->left);
        }
        else if (data > node->data)
        {
            node->right = remove(data, node->right);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *rightMin = node->right;
                while (rightMin->left != NULL)
                {
                    rightMin = rightMin->left;
                }
                int minVal = rightMin->data;
                node->data = minVal;
                node->right = remove(minVal, node->right);
                return node;
            }
        }
    }

public:
    void remove(int data)
    {
        root = remove(data, root);
    }

private:
    void print(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << ":";

        if (node->left != NULL)
        {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        print(node->left);
        print(node->right);
    }

public:
    void print()
    {
        print(root);
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (data <= node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

private:
    bool search(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return search(data, node->left);
        }
        else
        {
            return search(data, node->right);
        }
    }

public:
    bool search(int data)
    {
        return search(data, root);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}