class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int left = 1, right = m*n;
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            if (smallerOrEqual(m, n, mid) < k) {
                left = mid + 1; //(mid + 1, right)
            } else {
                right = mid; //(left, mid)
            }
        }
        return left;
        
    }
    
    int smallerOrEqual(int m, int n, int mid) {
        
        int count = 0;
        int i = m, j = 1;
        while (i >= 1 && j <= n) {
            
            if (i*j <= mid) {
                count += i;
                j++;
            } else {
                i--;
            }
        }
        return count;
    }
};