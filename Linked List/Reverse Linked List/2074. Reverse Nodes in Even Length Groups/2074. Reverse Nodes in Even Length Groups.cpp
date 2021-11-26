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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        int k = 1;
        int flag = 0;
        ListNode* ptr = head;
        vector<ListNode*> heads;
        heads.push_back(nullptr); //start from 1-index
        
        while (ptr) {
            
            heads.push_back(ptr);
            int i = 1;
            for (; i < k; i++) {
                if (ptr->next) {
                    ptr = ptr->next;
                } else {
                    break;
                }
            }
            
            if (i % 2 == 0  && ptr->next == nullptr) {
                cout <<i<<endl;
                flag = 1; //even number
            }
            ListNode* nxt = ptr->next;
            ptr->next = nullptr;
            ptr = nxt;
            k++;
        }
        
        for (int i = 1; i < heads.size(); i++) {
            
            if (i == heads.size() - 1 && flag == 1) {
                heads[i] = reverseList(heads[i]);
                break;
            } else if (i == heads.size() - 1 && flag == 0) {
                break;
            }
            
            if (i % 2 == 0) {
                heads[i] = reverseList(heads[i]);
            }
        }
        
        for (int i = 1; i < heads.size() - 1; i++) {
            
            ListNode* ptr = heads[i];
            while (ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = heads[i + 1];
        }
        return heads[1];
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