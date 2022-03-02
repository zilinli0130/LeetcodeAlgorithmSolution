using LL = long long;
class Solution {
    int n;
    LL Sum;
    LL res = LLONG_MAX;
public:
    int minimumDifference(vector<int>& nums) {
        
        n = nums.size() / 2;
        Sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        //Split nums into two sections
        vector<int> nums1;
        vector<int> nums2;
        for (int i = 0; i < n; i++) {
            nums1.push_back(nums[i]);
        }
        for (int i = n; i < 2*n; i++) {
            nums2.push_back(nums[i]);
        }
        
        //Construct the map
        unordered_map<int, vector<LL>> Map = helper(nums2);
        
        //Find the smallest difference
        for (int state = 0; state < (1<<n); state++) {
            
            LL x = 0;
            int i = __builtin_popcount(state);
            for (int k = 0; k < n; k++) {
                if ((state>>k) & 1) {
                    x += (LL)nums1[k];
                }
            }
            
            int j = n - i;
            auto iter = lower_bound(Map[j].begin(), Map[j].end(), Sum/2 - x);
            if (iter != Map[j].end()) {
                res = min(res, abs(2*x + *iter*2 - Sum));
            }
            if (iter != Map[j].begin()) {
                iter = prev(iter);
                res = min(res, abs(2*x + *iter*2 - Sum)); 
            }
        }
        return res;
    }
    
    unordered_map<int, vector<LL>> helper(vector<int>& nums2) {
        
        unordered_map<int, vector<LL>> Map;
        for (int state = 0; state < (1<<n); state++) {
            
            LL y = 0;
            int j = __builtin_popcount(state);
            for (int k = 0; k < n; k++) {
                if ((state>>k) & 1) {
                    y += (LL)nums2[k];
                }
            }
             Map[j].push_back(y);
        }
        
        for (auto& x : Map) {
            sort(x.second.begin(), x.second.end());
        }
        return Map;
    }
};


/*
nums1: C(n,i)
nums2: C(n,j) where j = n - i
*/