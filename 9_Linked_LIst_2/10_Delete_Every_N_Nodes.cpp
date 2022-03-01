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

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (M == 0)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp != NULL)
    {

        int count = 1;
        while (temp != NULL && count < M)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
        {
            return head;
        }

        Node *save = temp;

        count = -1;
        while (temp != NULL && count < N)
        {
            temp = temp->next;
            count++;
        }

        save->next = temp;
    }

    if (temp != NULL)
    {
        temp->next = NULL;
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
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}