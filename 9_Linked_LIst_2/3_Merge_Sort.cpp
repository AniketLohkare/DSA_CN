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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    Node *newHead = NULL, *newTail = NULL;

    if (head1->data < head2->data)
    {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            newTail->next = head1;
            newTail = newTail->next;
            head1 = head1->next;
        }
        else
        {
            newTail->next = head2;
            newTail = newTail->next;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
    {
        newTail->next = head1;
    }
    if (head2 != NULL)
    {
        newTail->next = head2;
    }

    return newHead;
}

Node *midPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *mergeSort(Node *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Divide Linked List into 2 parts, after finding mid
    Node *mid = midPoint(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // Recursive Calls to sort both parts
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both left and right parts
    Node *result = mergeTwoSortedLinkedLists(left, right);
    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }

    return 0;
}