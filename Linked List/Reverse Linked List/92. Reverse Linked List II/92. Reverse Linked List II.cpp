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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* L;
        ListNode* R;
        
        for (int i = 0; i < right; i++) {
            p = p->next;
        }
        R = p->next;
        p->next = nullptr;
        
        p = dummy;
        for (int i = 0; i < left - 1; i++) {
            p = p->next;
        }
        L = p->next;
        p->next = nullptr;
        
        L = reverseList(L);
        
        p = dummy;
        while (p->next) {
            p = p->next;
        }
        p->next = L;
        
        while (p->next) {
            p = p->next;
        }
        p->next = R;
        return dummy->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;

        while (cur != nullptr) {
            
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};