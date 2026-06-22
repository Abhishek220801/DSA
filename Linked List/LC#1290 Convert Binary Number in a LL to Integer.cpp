// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp) {
            temp = temp->next;
            len++;
        }
        int idx = len-1, sum = 0;
        temp = head;
        while(temp){
            if(temp->val==1) {
                sum+= pow(2, idx);
            }
            idx--;
            temp = temp->next;
        }
        return sum;
    }
};
