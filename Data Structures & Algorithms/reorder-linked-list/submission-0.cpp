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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<int> v;
        ListNode* temp = head;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int left = 0;
        int right = v.size() - 1;
        vector<int> ans;

        while (left <= right) {
            if (left == right) {
                ans.push_back(v[left]);
            } else {
                ans.push_back(v[left]);
                ans.push_back(v[right]);
            }

            left++;
            right--;
        }

        temp = head;
        int i = 0;

        while (temp) {
            temp->val = ans[i++];
            temp = temp->next;
        }

        return;
    }
};
