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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int count = 0;
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr=curr->next;
        }
        int index = len - n;
        if(index==0){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(temp !=nullptr && count < index){
            prev = temp;
            temp= temp->next;
            count++;
        }
       
        if(temp == nullptr) return head;
        prev->next = temp->next;
        delete temp;

        return head;
    }
};
