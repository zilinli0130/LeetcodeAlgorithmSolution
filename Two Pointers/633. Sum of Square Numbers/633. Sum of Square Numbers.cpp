/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (!head) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        int flag = 0;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            return nullptr;
        }
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};