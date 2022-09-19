//Check if LL is Pallindrome or Not
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

bool pallindrome(Node* head)
{
    if(head == NULL || head->next == NULL)
     return true;

    //Step1: Find Middle
    Node* middle = getMiddle(head);

    //Step2: Reverse List after middle
    Node* temp = middle->next;
    middle->next = reverseLL(temp);

    //Step3: Compare all 3 Halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1->data != head2->data)
          return false;

        head1 = head1->next;
        head2 = head2->next;  
    }

    //Step4: Repeat step2 to get the original list(optional)
    temp = middle->next;
    middle->next = reverseLL(temp);

   return true; 

}

int main()
{
   Node* first = new Node(1);
   Node* head = first;
   Node* tail = first;

   insertAtTail(tail,2);
   insertAtTail(tail,2);
   insertAtTail(tail,1);
   insertAtPosition(head,tail,3,3);

   traverse(head);

   cout<<"Pallindrome Status: "<<pallindrome(head);

  return 0;
}