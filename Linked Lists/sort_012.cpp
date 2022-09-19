//Sort a LL containing 0's 1's and 2's
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

Node* sort012(Node* head)
{
   //We make 3 dummy nodes so that merging becomes easier
   Node* zeroHead = new Node(-1);
   Node* zeroTail = zeroHead;
   Node* oneHead = new Node(-1);
   Node* oneTail = oneHead;
   Node* twoHead = new Node(-1);
   Node* twoTail = twoHead;

   Node* curr = head;
  // Creating separate lists for 0 1 and 2

   while(curr != NULL)
   {
     int value = curr->data;

     if(value == 0)
      {
        zeroTail->next = curr;
        zeroTail = zeroTail->next;
      }
     if(value == 1)
      {
        oneTail->next = curr;
        oneTail = oneTail->next;
      } 
     if(value == 2)
      {
        twoTail->next = curr;
        twoTail = twoTail->next;
      }

     curr = curr->next; 
       
   }
  
  //Merging the Individual Lists
  
  //One list Empty or Not
   if(oneHead->next != NULL)
     zeroTail->next = oneHead->next;
   else
     zeroTail->next = twoHead->next;

   oneTail->next = twoHead->next;
   twoTail->next = NULL;

   //Setup New Head
   Node* newHead = zeroHead->next;
   
   //Delete Dummy Nodes
   delete zeroHead;
   delete oneHead;
   delete twoHead;

   return newHead;
}

int main()
{
   Node* first = new Node(0); 
   Node* head = first;
   Node* tail = first;

   insertAtTail(tail,0);
   insertAtTail(tail,2);
   insertAtTail(tail,1);
   insertAtTail(tail,2);
   insertAtTail(tail,2);
   insertAtTail(tail,0);
   insertAtTail(tail,1);
   
   cout<<"Before: ";
   traverse(head);
   cout<<"After: ";
   traverse(sort012(head));

 return 0;
}