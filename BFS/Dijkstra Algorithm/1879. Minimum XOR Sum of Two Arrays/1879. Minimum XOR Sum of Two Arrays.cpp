class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<int> visited((1<<n));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push(pair<int, int>{0,0}); //{cost, state}
        
        while (!pq.empty()) {
            
            int cost = pq.top().first;
            int state = pq.top().second;
            pq.pop();
            
            if (visited[state]) continue;
            visited[state] = 1;
            
            int j = __builtin_popcount(state);
            if (j == n) {
                return cost;
            }
            
            for (int i = 0; i < n; i++) {
                if ((state>>i) & 1) continue;
                if (visited[state + (1<<i)]) continue;
                 pq.push(pair<int, int>{cost + (nums1[i]^nums2[j]), state + (1<<i)});
            }                    
        }
        return -1;
    }
};


// state = 0000000
// state = 1111111
// state -> k bits in state represent the k paired number in nums1 with nums[0:k - 1]
