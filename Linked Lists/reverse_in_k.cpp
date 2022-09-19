//Linked List Questions
//Reverse in Groups of K

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

Node* reverseInK(Node* &head, int k)
{
   //Empty List
   if(head == NULL)
    return NULL;

   Node* curr = head;
   Node* prev = NULL;
   Node* nextNode = NULL;
   int count = 0;

   //Step1: Reverse first k Nodes
   while(curr != NULL && count<k)
   {
     nextNode = curr->next;
     curr->next = prev;

     prev = curr;
     curr = nextNode;
     count++;
   } 

   //Recursive call for Remaining LL
   //nextNode will denote the head of remaining LL
   if(nextNode != NULL)
   {
     //Step2: Recursion will solve for remaining LL
     Node* remaining = reverseInK(nextNode,k);

     //Step3: connect the list from step 1 and 2
     head->next = remaining;
   }

   //Step4: Return the new head of the LL
   return prev; 
}

int main()
{
  Node* first = new Node(1);
  Node* head = first;
  Node* tail = first;
  insertAtTail(tail,2);
  insertAtTail(tail,3);
  insertAtTail(tail,4);
  insertAtTail(tail,5);
  insertAtTail(tail,6);
  insertAtTail(tail,7);
  insertAtTail(tail,8);

  cout<<"Before: "<<endl;

  traverse(head);

  cout<<"After: "<<endl;
  head = reverseInK(head,3); 

  traverse(head);


 return 0;
}