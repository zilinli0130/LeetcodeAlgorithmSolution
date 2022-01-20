class Solution {
    int h;
    vector<int> piles;
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        this->h = h;
        this->piles = piles;
        int low = 1, high = INT_MAX;
        while (low < high) {
            
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool isValid(int k) {
        
        int count = 0;
        for (auto pile : piles) {
            if (pile % k == 0) {
                count += pile / k;
            } else {
                count += pile / k + 1;
            }
        }
        return count <= h;
    }
};