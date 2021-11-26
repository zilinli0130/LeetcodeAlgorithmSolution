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
        
        int flag = 0;
        ListNode* ptr = head;
        vector<ListNode*> heads;
        
        while (ptr) {
            
            heads.push_back(ptr);
            for (int i = 0; i < k - 1; i++) {
                if (ptr->next) {
                    ptr = ptr->next;
                } else {
                    flag = 1;
                }
            }
            ListNode* nxt = ptr->next;
            ptr->next = nullptr;
            ptr = nxt;
        }
        
        for (int i = 0; i < heads.size(); i++) {
            if (i == heads.size() - 1 && flag == 1) continue;
            heads[i] = reverseList(heads[i]);
        }
        
        for (int i = 0; i < heads.size() - 1; i++) {
            
            ListNode* ptr = heads[i];
            while(ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = heads[i + 1];
        }
        return heads[0];
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