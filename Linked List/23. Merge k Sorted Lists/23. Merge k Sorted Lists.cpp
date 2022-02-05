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
using PII = pair<int, ListNode*>;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() == 0) {
            return nullptr;
        }
        int k = lists.size();
        priority_queue<PII, vector<PII>, greater<>> pq;
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        
        if (pq.size() == 0) {
            return nullptr;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        while (!pq.empty()) {
            
            ListNode* temp = pq.top().second;
            pq.pop();
            
            ptr->next = temp;
            ptr = ptr->next;
            if (temp->next != nullptr) {
                pq.push({temp->next->val, temp->next});
            }
            
        }
        ptr->next = nullptr;
        return dummy->next;
    }
};