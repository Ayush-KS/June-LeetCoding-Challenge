// Delete Node in a Linked List

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node -> next);
    }
};
