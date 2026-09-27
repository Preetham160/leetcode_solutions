#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Build list: 3 -> 2 -> 0 -> -4 -> (back to 2, cycle at pos 1)
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // creates the cycle

    Solution sol;
    cout << "Output: " << (sol.hasCycle(n1) ? "true" : "false") << endl;

    // Note: memory not freed here since it contains a cycle (can't traverse
    // it normally with delete). In a real cyclic structure, you'd need to
    // break the cycle first before cleanup.

    return 0;
}