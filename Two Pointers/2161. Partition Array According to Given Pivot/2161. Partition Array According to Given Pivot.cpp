class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {   
        vector<int> s;
        vector<int> e;
        vector<int> l;
        
        for (const auto& num : nums)
        {
            if (num < pivot)
            {
                s.push_back(num);
            }
            else if (num == pivot) 
            {
                e.push_back(num);
            }
            else 
            {
                l.push_back(num);
            }
        }
        
        s.insert(s.end(), e.begin(), e.end());
        s.insert(s.end(), l.begin(), l.end());
        return s;
    }
};