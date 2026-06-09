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

    ListNode* findMiddle(ListNode* l){
        ListNode* slow = l;
        ListNode* fast = l;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* l){
        ListNode* prev = NULL;
        ListNode* front = l;
        ListNode* temp = l;

        while(temp != NULL){
            front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }


    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* middle = findMiddle(head);

        ListNode* l2 = middle -> next;
        middle -> next = NULL;

        l2 = reverseList(l2);
        ListNode* l1 = head;
        while(l2 != NULL){
            ListNode* t1 = l1 -> next;
            ListNode* t2 = l2 -> next;

            l1 -> next = l2;
            l2 -> next = t1;
            
            l1 = t1;
            l2 = t2;
        }
    }
};
