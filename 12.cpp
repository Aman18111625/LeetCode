//Question:- Remove LinkedList Element(https://leetcode.com/problems/remove-linked-list-elements/)
//Difficulty Level: Easy
//Pre-requisite: Knowledge of Pointer

   ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;//if head is already null
        if(!head->next and head->val==val) return NULL;//if only one node  and that is to be deleted node then return NULL
        ListNode *newHead=head;
        while(newHead->next)
        {
          if(newHead->next->val==val)//if node with given val found then skip that node
          {
            newHead->next=newHead->next->next;
          }
            else
            {
             newHead=newHead->next;
            }
        }
        if(head->val==val) head=head->next;//if there are two or more than two node and to be deleted node is head then move head to next and delete prev
        return head;
    }