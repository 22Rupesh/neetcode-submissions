class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        ListNode* temp = l1;
        while (temp) {
            v1.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> v2;
        ListNode* temp2 = l2;
        while (temp2) {
            v2.push_back(temp2->val);
            temp2 = temp2->next;
        }

        vector<int> v3;
        int carry = 0;

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; i++) {
            int a = (i < v1.size()) ? v1[i] : 0;
            int b = (i < v2.size()) ? v2[i] : 0;

            int sum = a + b + carry;
            v3.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry) {
            v3.push_back(carry);
        }

        ListNode* res = new ListNode(v3[0]);
        ListNode* temp3 = res;

        for (int i = 1; i < v3.size(); i++) {
            temp3->next = new ListNode(v3[i]);
            temp3 = temp3->next;
        }

        return res;
    }
};