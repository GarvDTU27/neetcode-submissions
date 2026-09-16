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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL ;
        ListNode* fwd = head ;
        ListNode* curr = head ;

        for(int i = 0 ; i< n ; i++){
            fwd = fwd->next ;
        }

        if(fwd == NULL) return head->next ;
        while(fwd->next != nullptr){
            curr = curr->next ;
            fwd = fwd->next ;
        }

        curr->next = curr->next->next ;

        return head ;
    }
};
