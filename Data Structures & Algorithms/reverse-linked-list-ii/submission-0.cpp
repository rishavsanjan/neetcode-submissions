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
    ListNode* rev(ListNode* head, int right, int left) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        int i = left;
        while (i <= right) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;

            i++;
        }
        head->next = front;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return rev(head,right,left);
        }
        ListNode* tail = NULL;
        ListNode* temp = head;
        int i = 1;
        while (temp != NULL) {
            if (i == left) {
                tail->next = rev(temp, right, left);
                break;
            }
            i++;
            tail = temp;
            temp = temp->next;
        }

        return head;
    }
};