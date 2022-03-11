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
    ListNode* partition(ListNode* head, int x) 
    {
        if (!head)
        {
            return nullptr;
        }
        
        ListNode* s = new ListNode();
        ListNode* l = new ListNode();
        ListNode* ptr1 = s;
        ListNode* ptr2 = l;
        
        while (head)
        {
            if (head->val < x)
            {
                ptr1->next = head;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2->next = head;
                ptr2 = ptr2->next;
            }
            head = head->next;
        }
        
        ptr1->next = l->next;
        ptr2->next = nullptr;
        return s->next;
    }
};