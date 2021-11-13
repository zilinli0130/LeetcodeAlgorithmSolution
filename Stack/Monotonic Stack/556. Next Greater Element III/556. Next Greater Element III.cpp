class Solution {
public:
    int nextGreaterElement(int n) {
        
        long res = 0;
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n%10);
            n = n/10;
        }
        
        
        //Find the 1st element which violates the non-decreasing order from back to front
        int idx1 = 1;
        while (idx1 < digits.size() && digits[idx1] >= digits[idx1 - 1]) {
            idx1++;
        }
        if (idx1 == digits.size()) return -1;
        
        //Find the min element which is greater than digits[idx1]
        int idx2 = 0;
        while (idx2 < digits.size() && digits[idx2] <= digits[idx1]) {
            idx2++;
        }
        
        //Swap the location between idx1 and idx2
        swap(digits[idx1], digits[idx2]);
        
        sort(digits.begin(), digits.begin() + idx1);
        reverse(digits.begin(), digits.begin() + idx1);
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            res *= 10;
            res += digits[i];
        }
        if (res > INT_MAX) return -1;
        return res;
    }
};

