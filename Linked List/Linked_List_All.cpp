#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;

    }
};
void insertAtHead(node* &head, int val){
        node* n= new node(val);
        n->next=head;
        head=n;
}
void insertAtTail(node* &head, int val){
            node* n= new node(val);
            node* temp=head;

            if(head==NULL){
                head=n;
                return;
            }
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next =n;
}
bool searchKeyIterative(node* head,int key ){
         node* temp=head;
         while(temp!=NULL){
            if(temp->data==key){
                return true;

            }
            temp=temp->next;
         }
         return false;

}
bool searchKeyRecursive(node* head, int key)
{
    if (head == NULL)
        return false;

    if (head->data == key)
        return true;

    return searchKeyRecursive(head->next, key);
}
void deleteNode(node** head, int key1)
{
    node* temp = *head;
    node* prev = NULL;
    if (temp != NULL && temp->data == key1)
    {
        *head = temp->next;
        delete temp;
        return;
    }
      else
    {
    while (temp != NULL && temp->data != key1)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
    }
}
void deleteNodePosition(node **head, int position)
{
    if (*head == NULL)
        return;
    node* temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
     node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void deleteList(node** head)
{
    node* current = *head;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
int CountIterativeMethod(node* head)
{
    int count = 0;
    node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int CountRecursiveMethod(node* head)
{
    if (head == NULL) {
        return 0;
    }
    else {
        return 1 + CountRecursiveMethod(head->next);
    }
}
int getNth(node* head, int index)
{

    node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    assert(0);
}
void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}
int main(){
        int key,key1,index,position;
        node* head=NULL;
        insertAtTail(head, 1);
        insertAtHead(head, 3);
        insertAtTail(head, 5);
        insertAtHead(head, 9);
        cout<<"The linked list is: \n";
        display(head);
        cout<<"The length of the linked list (By IterativeMethod) is: "<<CountIterativeMethod(head);
        cout<<"\nThe length of the linked list (By RecursiveMethod) is: "<<CountRecursiveMethod(head);
        cout<<"\nEnter the search key: \n";
        cin>>key;
        cout<<"\nBy Iterative Method: "<<searchKeyIterative(head,key);
        cout<<"\nBy Recursive Method: "<<searchKeyRecursive(head,key);
        cout<<"\nEnter the position index to find the number: \n";
        cin>>index;
        cout<<"\nElement at index "<<index<<" is: "<<getNth(head,index);
        cout<<"\nEnter the deletion key: \n";
        cin>>key1;
        deleteNode(&head, key1);
        cout<<"\nAfter deletion the new linked list is: \n";
        display(head);
        cout<<"Enter the position number for deleting element: \n";
        cin>>position;
        deleteNodePosition(&head, position);
        cout<<"\nAfter deletion the position new linked list is: \n";
        display(head);
        cout << "\nDeleting linked list";
        deleteList(&head);
        cout << "\nLinked list deleted";
        display(head);


return 0;
}
