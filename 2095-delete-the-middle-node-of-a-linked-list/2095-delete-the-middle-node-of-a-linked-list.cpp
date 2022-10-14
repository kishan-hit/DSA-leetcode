/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode *temp = head;
        while(temp){
            ++cnt;
            temp = temp->next;
        }
        if(cnt==1)
            return NULL;
        cnt /= 2;
        temp = head;
        for(int i=0;i<cnt-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};