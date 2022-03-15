template <typename T>
class BinaryTreeNode
{
public:
    // Members
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    // Constructors
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // Destructor
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};