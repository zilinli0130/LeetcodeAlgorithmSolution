class Solution {
    int n;
public:
    int firstMissingPositive(vector<int>& nums) {
        
        n = nums.size();
        nums.insert(nums.begin(), 0);
        
        for (int i = 1; i <= n; i++) {
            while (nums[i] != i && isValid(nums[i]) && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n + 1;
    }
    
    bool isValid(int num) {
        return num >= 0 && num <= n;
    }
};