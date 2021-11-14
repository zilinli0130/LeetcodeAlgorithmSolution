class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int left = 1, right = INT_MAX/2;
        
        while (left < right) {
            
            int mid = left + (right - left)/2;
            if (ok(quantities, n, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    
    bool ok(vector<int>& quantities, int n, int mid) {
        
        int count = 0;
        for (int i = 0; i < quantities.size(); i++) {
            
            if (quantities[i] % mid != 0) {
                count += quantities[i] / mid +1;
            } else {
                count += quantities[i] / mid;
            }
        }        
        return count <= n;
    }
};

    