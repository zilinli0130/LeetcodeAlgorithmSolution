class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<>> pq;      
        for (const auto& num : nums) {
            
            if (pq.size() < k) {
                pq.push(num);
            } else if (pq.size() == k && num >= pq.top()) {
                pq.push(num);
                pq.pop();
            }
        }
        return pq.top();
    }
};