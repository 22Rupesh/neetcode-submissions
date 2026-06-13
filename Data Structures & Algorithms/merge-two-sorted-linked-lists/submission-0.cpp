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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1) {
            v.push_back(temp1->val);
            temp1 = temp1->next;
        }

        while(temp2){
            v.push_back(temp2->val);
            temp2 = temp2->next;
        }
        if (v.empty()) return nullptr;
        sort(v.begin(),v.end());

        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;
        for(int i=1;i<v.size();i++){
            temp -> next = new ListNode(v[i]);
            temp = temp->next;
        }

        return head;
    }
};
