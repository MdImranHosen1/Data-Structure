#include <bits\stdc++.h>
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
void printLinkList(Node *a)
{
    while (a->next != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << a->data << endl;
}
void InsertLinkList(Node *&head, int value)
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
bool searching(Node *head, int value)
{
    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }
    if (temp->data == value)
    {
        return true;
    }

    return false;
}
int main()
{
    Node *head = NULL;
    cout << "How much value you want to insert?" << endl;
    int n;
    cin >> n;
    cout << "Enter the value of every index\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        InsertLinkList(head, value);
    }
    cout << "Which value do you want to search:: ";
    int value;
    cin >> value;
    int x = searching(head, value);
    if (x == 1)
    {
        cout << "We found the number in linkList\n";
    }
    else
    {
        cout << "We not found the number in linkList\n";
    }
}