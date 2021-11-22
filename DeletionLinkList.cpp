#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insertInLast(Node *&head, int value)
{
    Node *a = new Node(value);
    if (head == NULL)
    {
        head = a;
        return;
    }
    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = a;
}
void printLinkList(Node *a)
{
    while (a->next != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << a->data << endl;
}
void deleteLinkList(Node *&head, int index)
{
    Node *temp = head;
    if (index == -1)
    {
        head = temp->next;
    }
    else
    {
        Node *temp1 = head;
        temp1 = temp1->next;
        temp1 = temp1->next;

        while (index--)
        {
            temp = temp->next;
            temp1 = temp1->next;
        }

        temp->next = temp1;
    }
}
int main()
{
    Node *head = NULL;
    cout << "How much value you want to insert?" << endl;
    int n;
    cin >> n;
    cout << "Enter the value of LinkList\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertInLast(head, value);
    }
    cout << "How munch value do you want to delete?" << endl;
    int newi;
    cin >> newi;
    for (int i = 0; i < newi; i++)
    {
        cout << "Enter the index number" << endl;
        int index;
        cin >> index;
        deleteLinkList(head, index - 2);
        cout << "Update linkedList::\n";
        printLinkList(head);
    }

    printLinkList(head);
}