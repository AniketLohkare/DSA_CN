
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    else if (pos == 0)
    {
        head = head->next;
        return head;
    }
    else
    {
        Node *temp = head;

        int count = 0;
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp != NULL && temp->next != NULL)
        {
            Node *target = temp->next;
            temp->next = target->next;
            delete target;
        }
    }

    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}