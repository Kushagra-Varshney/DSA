//Linked List basics
//Insertion , Deletion, Traversal
//Reverse LL, find length, get middle, is circular or not
//Reverse LL in k groups
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

int findLength(Node* head)
{
    int length = 0;
    Node* temp = head;
    while(temp != NULL)
     {
        length++;
        temp = temp->next;
     }

   return length;  
}

Node* reverseLL(Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL)
    {
        Node* nextNode = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
  //Prev pointer indicates the new Head of the reversed LL
  return prev;  
}

Node* reverseRecursion(Node* curr, Node* prev)
{
   if(curr == NULL)
     return prev;

   Node* forward = curr->next;
   curr->next = prev;
   
    reverseRecursion(forward,curr);  
}

Node* getMiddle(Node* head)
{
    //If List is Empty
    if(head == NULL)
    {
        cout<<"List is Empty";
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL)
     {
        fast = fast->next->next;
        slow = slow->next;
     }
   
  return slow; 
}

bool isCircular(Node* head)
{
    if(head == NULL)
     {
        cout<<"List is Empty";
        return false;
     }
    
    Node* temp = head;

    while(temp->next != head)
     {
        if(temp->next == NULL)
         return false;
        temp = temp->next;
     }

   return true;   
}



int main()
{
   Node* first = new Node(5); 
   Node* head = first;
   Node* tail = first;

   insertAtHead(head,2);
   insertAtHead(head,9);
   
   insertAtTail(tail,11);
   insertAtTail(tail,12);

   insertAtPosition(head,tail,6,24);

   traverse(head); 

   deleteNode(head,tail,24,1);
   deleteNode(head,tail,9,1);

   insertAtTail(tail,69);
   insertAtHead(head,96);

   traverse(head);

   cout<<"Length of Linked List: "<<findLength(head)<<endl;

   cout<<"Middle Node of the LL is: "<<getMiddle(head)->data<<endl;
   
   //head->next = head;
   cout<<"LL Circular or Not: "<<isCircular(head)<<endl;

   Node* reversedHead = reverseRecursion(head,NULL);

   traverse(reversedHead);

   
}