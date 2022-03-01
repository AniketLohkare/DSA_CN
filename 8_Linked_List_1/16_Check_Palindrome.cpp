#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

Node *findSecondLastNode(Node *head)
{
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    return head;
}

bool isPalindrome(Node *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *secondLast = findSecondLastNode(head);
    Node *last = secondLast->next;

    if (head->data == last->data)
    {
        secondLast->next = NULL;
        return isPalindrome(head->next);
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}