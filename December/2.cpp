//Question : Odd Even Linked List(https://leetcode.com/problems/odd-even-linked-list/)
//Difficulty Level : Medium
//Pre-requisites : Pointers

//Time - Complexity:- O(N)
//Space - Complexity:-O(N)

//seperate in a odd and even Linked-List && then simply add 
   ListNode* oddEvenList(ListNode* head) {
     if(!head) return head;
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *odd_head=head;
        ListNode *even_head=head->next;
        
        while(even && even->next)
        {
          odd->next=odd->next->next;
          even->next=even->next->next;
          odd=odd->next;
          even=even->next;
        }
        odd->next=even_head;
        return head;
    }