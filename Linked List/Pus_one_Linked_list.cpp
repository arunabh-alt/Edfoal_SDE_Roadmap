/* Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:
Input: head = [1,2,3]
Output: [1,2,4]

Example 2:
Input: head = [0]
Output: [1]*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node *reverse(Node *head)
{
    Node * prev = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *adding(Node *head)
{
    Node* res = head;
    Node *temp, *prev = NULL;

    int carry = 1, sum;

    while (head != NULL)
    {
        sum = carry + head->data;
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}
Node* addOne(Node *head)
{
    head = reverse(head);
    head = adding(head);
    return reverse(head);
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout<<endl;
}
int main(void)
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    cout << "Linked List is ";
    printList(head);

    head = addOne(head);

    cout << "\nAfter adding one, the new list is: ";
    printList(head);

    return 0;
}
