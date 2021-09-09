class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if (m*k > bloomDay.size()) return -1;
        int low = 1, high = 1e9;
        while (low < high) {
            
            int mid = low + (high - low) / 2;
            if (isValid(bloomDay, mid, m, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool isValid(vector<int>& bloomDay, int mid, int m, int k) {
        
        int count = 0, group = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            
            if (bloomDay[i] > mid) {
                group = 0;
            } else {
                group++;
                if (group == k) {
                    count++;
                    group = 0;
                }
            }
        }
        return count >= m;
    }
};