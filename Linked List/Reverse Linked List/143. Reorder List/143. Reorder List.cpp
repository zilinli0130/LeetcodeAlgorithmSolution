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
        
        int count = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next) {
            count++;
            p = p->next;
        }
        
        p = dummy;
        for (int i = 0; i < (count + 1) / 2; i++) {
            p = p->next;
        }
        ListNode* head2 = p->next;
        p->next = nullptr;
        head2 = reverseList(head2);
        
        p = head;
        ListNode* q = head2;
        ListNode* h = dummy;
        
        while (p || q) {
            
            if (p) {
                
                h->next = p;
                p = p->next;
                h = h->next;
            }
            
            if (q) {
                
                h->next = q;
                q = q->next;
                h = h->next;
                
            }
        }
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