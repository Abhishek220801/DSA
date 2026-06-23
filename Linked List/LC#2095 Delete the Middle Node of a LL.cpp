// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        if(len==1) return NULL;
        if(len==2) {
            ListNode* b = new ListNode(head->val);
            return b;
        };

        temp = head;
        int mid = len/2;

        int i = 0;
        while(i<mid-1) {
            i++;
            temp = temp->next;
        };

        temp->next = temp->next->next;
        return head;
    }
};
