class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int left = 1, right = INT_MAX/2;
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            if (ok(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool ok(vector<int>& weights, int days, int bound) {
        
        int count = 0;
        int weight = 0;
        for (int i = 0; i < weights.size(); i++) {
            
            if (weights[i] > bound) {
                return false;
            }
            
            weight += weights[i];
            if (weight > bound) {
                count++;
                weight = weights[i];
            }
        }
        count++;
        return count <= days;
    }
};