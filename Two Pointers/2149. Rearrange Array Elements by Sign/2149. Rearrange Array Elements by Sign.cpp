class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {        
        vector<int> res;
        vector<int> arr1;
        vector<int> arr2;

        for (const auto& num : nums) 
        {
            if (num > 0)
            {
                arr1.push_back(num);
            }
            else 
            {
                arr2.push_back(num);
            }
        }
        
        int idx1 = 0, idx2 = 0, len = arr1.size();
        while (idx1 < len || idx2 < len)
        {
            if (idx1 < len)
            {
                res.push_back(arr1[idx1]);
                idx1++;
            }
            
            if (idx2 < len)
            {
                res.push_back(arr2[idx2]);
                idx2++;
            }
        }
        return res;
    }
};