class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int n = mentors.size();
        vector<int> dp((1<<n), INT_MIN/2);
        auto new_dp = dp;
        dp[0] = 0;
        
        for (int j = 0; j < n; j++) {
            
            for (int state = 0; state < (1<<n); state++) {
                
                for (int i = 0; i < n; i++) {
                    
                    if ((state>>i) & 1) {
                        new_dp[state] = max(new_dp[state], dp[state - (1<<i)] + helper(students[i], mentors[j]));
                    }                    
                }
            }
            dp = new_dp;
        }
        return dp[(1<<n) - 1];
    }
    
    int helper(vector<int>& nums1, vector<int>& nums2) {
        
        int res = 0;
        int n = nums1.size();
        for (int k = 0; k < n; k++) {
            if (nums1[k] == nums2[k]) {
                res++;
            }
        }
        return res;
    }
};


// state = 000
// state = 111
    
// state = 00101100 -> k bits of one in state represents that there
// are k students being paired with the [0:k-1] mentors

