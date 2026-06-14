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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* res = new ListNode(v[0]);
        ListNode* temp = res;
        for (int i = 1; i < v.size(); i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return res;
    }
};
