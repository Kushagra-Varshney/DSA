//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* solve(ListNode* &head, bool& anyChange)
    {
       if(head == NULL)
           return head;
        
        ListNode* temp = head;
        int sum = 0;
        
        while(temp != NULL)
        {
            sum = sum + temp->val;
            if(sum == 0)
                break;
            temp = temp->next;
        }
        
        if(sum == 0)
        {
            anyChange = true;
            return temp->next;
        } 
       
        //agli node ko head maanke check kro prefix sum zero aa rha hai ya nahi
       head->next = solve(head->next,anyChange); 
       return head; 
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        while(true)
        {   
           bool anyChange = false;
           head = solve(head,anyChange);
            
           if(head == NULL || anyChange == false)
               break;
                               
        }
        
        return head;
        
    }
};

int main()
{
  

 return 0;
}