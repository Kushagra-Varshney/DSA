//Remove Duplicates from a sorted LL
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d)
{
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
    return; 
}

void insertAtPosition(Node* head,Node* tail, int k, int d)
{
    Node* temp = head;

    if(k == 1)
     insertAtHead(head,d);
    
    for(int i = 1; i<k-1; i++)
    {
        temp = temp->next;
    }
    
    
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void traverse(Node* head)
{
    Node* tempHead = head;
    while(tempHead != NULL)
    {
        cout<<tempHead->data<<" ";
        tempHead = tempHead->next;
    }
    
   cout<<endl;

}

void deleteNode(Node* &head, Node* &tail, int target, int pos)
{
   //For Empty List
   if(head == NULL)
    return;
   
   Node* temp = head;
   Node* prev = NULL;

   if(temp->data == target && pos == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        while(temp != NULL && temp->data != target)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout<<"Node Not Found";
            return;
        }

        //If Last Node is being Deleted
        if(temp->next == NULL)
         tail = prev;

        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

Node* removeDuplicates(Node* head)
{
    //Empty List
    if(head == NULL)
     return NULL;

    Node* curr = head;

    while(curr != NULL)
     {
        if((curr->next != NULL) && curr->data == curr->next->data)
         {
            Node* next_next = curr->next->next;
            Node* delNode = curr->next;
            delete delNode;
            curr->next = next_next;
         }
        else
         {
            curr = curr->next;
         } 
     }

  return head; 
}

int main()
{
   Node* first = new Node(1); 
   Node* head = first;
   Node* tail = first;

   insertAtTail(tail,2);
   insertAtTail(tail,3);
   insertAtTail(tail,3);
   insertAtTail(tail,3);
   insertAtTail(tail,4);
   insertAtTail(tail,4);
   insertAtTail(tail,5);
   insertAtTail(tail,6);
   insertAtTail(tail,6);
   cout<<"Before: ";
   traverse(head);
   removeDuplicates(head);
   cout<<"After: ";
   traverse(head);

 return 0;
}