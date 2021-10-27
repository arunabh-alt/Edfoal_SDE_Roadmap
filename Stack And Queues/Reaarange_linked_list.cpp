/* You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3] */
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
void reverselist(Node** head)
{
    Node *prev = NULL, *curr = *head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}
void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
}
void rearrange(Node** head)
{
    Node *slow = *head, *fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head1 = *head;
    Node* head2 = slow->next;
    slow->next = NULL;
    reverselist(&head2);
    *head = newNode(0);
    Node* curr = *head;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    *head = (*head)->next;
}
int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printlist(head);
    rearrange(&head);
    printlist(head);
    return 0;
}
