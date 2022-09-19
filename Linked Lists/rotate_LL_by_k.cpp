#include<iostream>
//https://leetcode.com/problems/rotate-list/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    int getLength(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(temp != NULL)
        {
            len ++;
            temp = temp->next;
        }
       return len; 
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        int len = getLength(head);
        
        if(k % len == 0)
            return head;
        
        k = k % len;
        
        for(int i=0; i<(len-k); i++)
        {
            prev = temp;
            temp = temp->next;
        } 
        
        prev->next = NULL;
        
        ListNode* tail = temp;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        
        tail->next = head;
        
        return temp;
    }
};