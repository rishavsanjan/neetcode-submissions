class Solution {
   public:
    ListNode* kthNode(ListNode* node, int k) {
        while (node && --k) {
            node = node->next;
        }

        return node;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;

            curr->next = prev;

            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevGroup = nullptr;

        while (temp) {
            ListNode* kth = kthNode(temp, k);

            if (kth == nullptr) {
                if (prevGroup) prevGroup->next = temp;

                break;
            }

            ListNode* nextNode = kth->next;

            kth->next = nullptr;

            ListNode* newHead = reverseLinkedList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevGroup->next = newHead;
            }

            prevGroup = temp;
            temp = nextNode;
        }

        return head;
    }
};