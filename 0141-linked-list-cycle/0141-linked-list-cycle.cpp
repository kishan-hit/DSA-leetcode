/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode *head){
        ListNode *prev=NULL,*nxt=NULL;
        while(head){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    bool hasCycle(ListNode *head) {
        ListNode *rev = reverse(head);
        if(head && head->next && rev==head)
            return true;
        return false;
    }
};