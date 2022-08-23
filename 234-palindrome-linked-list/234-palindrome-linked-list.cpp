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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            ++cnt;
            temp = temp->next;
        }
        vector<int> v1,v2;
        int i=1;
        while(i<=cnt/2){
            v1.push_back(head->val);
            head = head->next;
            ++i;
        }
        if(cnt&1){
            ++i;
            head = head->next;
        }
        while(i<=cnt){
            v2.push_back(head->val);
            head = head->next;
            ++i;
        }
        reverse(v2.begin(),v2.end());
        return v1==v2;
    }
};