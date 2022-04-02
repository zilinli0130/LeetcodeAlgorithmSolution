class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        nums.insert(nums.begin(),0);
        for (int i = 1; i <= n; i++) {
            while (nums[i] != i && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        
        vector<int>res;
        for (int i = 1; i <= n; i++) {
            if (nums[i]!=i) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};