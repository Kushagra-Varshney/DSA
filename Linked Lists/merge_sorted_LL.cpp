//Merge Two Sorted Linked Lists
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

Node* mergeLL(Node* head1, Node* head2)
{
   if(head1 == NULL)
    return head2;
   if(head2 == NULL)
    return head1; 
   
   Node* prev1 = head1;
   Node* curr1 = head1->next;
   Node* curr2 = head2;

   while(curr1 != NULL && curr2 != NULL)
    { 
        if(prev1->data <= curr2->data && curr2->data <= curr1->data)
         {
            prev1->next = curr2;
            curr2 = curr2->next;
            prev1->next->next = curr1;
            prev1 = prev1->next;
         }
         else
          {
            prev1 = curr1;
            curr1 = curr1->next;
          }
    }

    if(curr1 == NULL)
     prev1->next = curr2;

  return head1;   
}


int main()
{
   Node* first = new Node(1); 
   Node* head1 = first;
   Node* tail1 = first;

   insertAtTail(tail1,3);
   insertAtTail(tail1,5);
   insertAtTail(tail1,6);
   cout<<"List1: ";traverse(head1);

   Node* second = new Node(2);
   Node* tail2 = second;
   Node* head2 = second; 
   insertAtTail(tail2,3);
   insertAtTail(tail2,9);
   insertAtTail(tail2,11);
   cout<<"List2: ";traverse(head2);

   cout<<"After Merging: ";
   traverse(mergeLL(head1,head2));

 return 0;
}