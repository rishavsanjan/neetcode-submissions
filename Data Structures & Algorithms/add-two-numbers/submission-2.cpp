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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode* temp = dummy;
        int carry = 0;
        while(list1 != NULL || list2 != NULL){
            int total = 0;

            if(list1){
                total += list1 -> val;
            }

            if(list2){
                total += list2 -> val;
            }
            if(carry != 0){
                total += 1;
            }

            if(total > 9){
                carry = 1;
            }else{
                carry = 0;
            }

            ListNode* newNode = new ListNode(total % 10);
            temp -> next = newNode;
            temp = temp -> next;
            
            if(list1){
               list1 = list1 -> next; 
            }

            if(list2){
               list2 = list2 -> next; 
            }
            
            
        }

       

        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            temp -> next = newNode;
        }

        return dummy -> next;


    }
};
