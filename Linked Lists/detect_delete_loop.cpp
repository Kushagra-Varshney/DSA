//Detect and Delete Loop from LL
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

Node* kthNode(Node* head, int k)
{
    Node* fast = head;
    Node* slow = head;
    
    while(k-- && fast != NULL)
     {
        fast = fast->next;
     }

    while(fast != NULL)
     {
        slow = slow->next;
        fast = fast->next;
     }

  return slow;    
}

Node* detectLoop(Node* head)
{
    if(head == NULL)
     return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL)
     {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
         return slow;
     }

  return NULL;
}

bool detectDeleteLoop(Node* head)
{
    //List Empty
    if(head == NULL)
     return false;
    //Step1: Detect if Loop Present
    Node* fast = detectLoop(head);
    //If Loop not present
    if(fast == NULL)
     {
        cout<<"Loop Not Present ";
        return true;
     }
    //Step2: Detect Beginning Node
    Node* slow = head;

    while(fast != slow)
     {
        slow = slow->next;
        fast = fast->next;
     }

    Node* beginning = slow;
    //Step3: Remove Loop
    Node* temp = beginning;

    while(temp->next != beginning)
     {
        temp = temp->next;
     }

   temp->next = NULL;
  return true;    
}



int main()
{
   Node* first = new Node(1); 
   Node* head = first;
   Node* tail = first;

   insertAtTail(tail,3);
   insertAtTail(tail,5);
   insertAtTail(tail,6);
   insertAtTail(tail,7);
   insertAtTail(tail,8);
   Node* temp = tail;
   insertAtTail(tail,9);
   insertAtTail(tail,10);
   insertAtTail(tail,11);
   insertAtTail(tail,12);
   tail->next = temp;
   
   detectDeleteLoop(head);
   traverse(head);
   

  return 0;  
}