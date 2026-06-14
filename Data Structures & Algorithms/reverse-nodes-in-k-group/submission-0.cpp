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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i + k <= v.size(); i += k) {
            reverse(v.begin() + i, v.begin() + i + k);
        }

        ListNode* res = new ListNode(v[0]);
        ListNode* temp2 = res;
        for (int i = 1; i < v.size(); i++) {
            temp2->next = new ListNode(v[i]);
            temp2 = temp2->next;
        }

        return res;
    }
};
