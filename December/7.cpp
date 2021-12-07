//Question : Convert Binary Number in a Linked List to Integer(https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
//Difficulty : Easy
//Pre-requisites : Pointer

//Time- Complexity : O(N) where N->length of Linked List

 int getDecimalValue(ListNode* head) {
        if(!head or !head->next) return head->val;
        ListNode* curr=head;
         string temp="";
        while(curr)
        {
            temp+=(to_string(curr->val));
            curr=curr->next;
        }
        int ans=0;
        for(int i=temp.size()-1,j=0;i>=0;i--,j++)
        {
            int num=temp[i]-'0';
            ans+=(1<<j)*num;
        }
        return ans;
    }