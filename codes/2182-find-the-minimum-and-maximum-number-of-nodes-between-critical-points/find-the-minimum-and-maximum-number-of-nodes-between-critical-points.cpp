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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int index = 1;
        int first = -1;
        int prev = -1;

        int minDist = INT_MAX;
        int last = -1;

        ListNode* curr = head->next;
        ListNode* prevNode = head;

        while (curr->next != nullptr) {

            ListNode* nextNode = curr->next;

            // Check if current node is a critical point
            if ((curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val)) {

                if (first == -1) {
                    // First critical point
                    first = index;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - prev);
                }

                prev = index;
                last = index;
            }

            prevNode = curr;
            curr = nextNode;
            index++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};