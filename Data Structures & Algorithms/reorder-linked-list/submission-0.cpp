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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;

        ListNode* prev = NULL ;
        ListNode* curr = head ;

        while(curr != NULL){
            ListNode* next = curr->next ;

            curr->next = prev ;
            prev = curr; 
            curr = next ;
        }

        return prev ;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return ;

        ListNode* slow = head;
        ListNode* fast = head->next ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }

        ListNode* newHead = reverseList(slow->next);
        slow->next = NULL ;
        bool down = true ;
        slow = head ;

        while(newHead != NULL && slow != NULL){
            if(down){
                ListNode* nex = slow->next ;
                slow->next = newHead ;
                slow = nex ;
                down = !down ;
            }
            else{
                ListNode* nex = newHead->next ;
                newHead->next = slow ;
                newHead = nex ;
                down = !down ;
            }
        }
    }
};
