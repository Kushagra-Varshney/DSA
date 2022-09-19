//Find the Kth node from last in a LL
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

//Recursive Solution
int countKFromLast(Node* &head, int k)
{
    if(head == NULL)
     return 0;

    int count = countKFromLast(head->next, k) +1;

    if(count == k)
     cout<<"Kth Node from Last is: "<<head->data;

   return count;   
}

int main()
{
   int k;
   Node* first = new Node(1); 
   Node* head = first;
   Node* tail = first;
//    cout<<"Enter k: ";
//    cin>>k;  
   insertAtTail(tail,3);
   insertAtTail(tail,5);
   insertAtTail(tail,6);
   insertAtTail(tail,7);
   insertAtTail(tail,8);
   insertAtTail(tail,9);
   traverse(head); 

//    cout<<"Kth Node from End is: "<<kthNode(head,k)->data;
   countKFromLast(head,6);
   return 0; 
}