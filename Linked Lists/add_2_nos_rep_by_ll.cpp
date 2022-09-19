//Solved On: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbWx2MF9uSkswSUtJWEJEOS1EVVZpTWVPejlVUXxBQ3Jtc0ttbjdQZnFiQVpxM2NlNnZTTlFqRXFHaDRVdUdCQkVkMEhZRFBEd21rRDdlX09iOVdrZk1zR3BVYjQzc3VtMTNvVmdHZmJzX0ZUUFlZY3BwbDh5ZDVhR2Z2SXJUU2tvRHZKLUZvRU5meUxoc2JqUE9OSQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fadd-two-numbers-represented-by-linked-lists%2F1&v=HiRlTPf9aCg
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    Node* reverse(Node* head)
    {
      Node* curr = head;
      Node* prev = NULL;
      Node* next = NULL;
    
      while(curr != NULL)
       {
           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next; 
       }
      return prev; 
    }
    
    void insertAtTail(Node* &ansHead, Node* &ansTail, int digit)
      {
          Node* temp = new Node(digit);
          if(ansHead == NULL)
           {    
            ansHead = temp;
            ansTail = temp;
            return;
           }    
          else
           {
               ansTail->next = temp;
               ansTail = temp;
           }
      }
    
    struct Node* add(struct Node* first, struct Node* second)
     {
         int carry = 0;
         Node* ansHead = NULL;
         Node* ansTail = NULL;
         
         while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
           
         return ansHead;  
     }
     
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       //Step1: Reverse Both Linked Lists
       first = reverse(first);
       second = reverse(second);
       
       //Step2: Add 
       Node* ans = add(first,second);
       
       //Step3: Reverse ans Linked List
       ans = reverse(ans);
    }
};