class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int idx1 = m - 1, idx2 = n - 1, idx = m + n - 1;
        while ((idx1 >= 0 || idx2 >= 0) && idx >= 0) {
            
            if (idx1 < 0) {
                
                while (idx >= 0) {
                    nums1[idx] = nums2[idx2];
                    idx2--;
                    idx--;
                }
                return;
            } else if (idx2 < 0) {
                
                while (idx >= 0) {
                    nums1[idx] = nums1[idx1];
                    idx1--;
                    idx--;
                }
                return;
            }
            
            if (nums1[idx1] > nums2[idx2]) {
                nums1[idx] = nums1[idx1];
                idx1--;
                idx--;
            } else if (nums1[idx1] < nums2[idx2]) {
                nums1[idx] = nums2[idx2];
                idx2--;
                idx--;
            } else if (nums1[idx1] == nums2[idx2]) {
                nums1[idx] = nums1[idx1];
                idx--;
                nums1[idx] = nums2[idx2];
                idx--;
                idx1--;
                idx2--;
            }
        }
        return;
    }
};