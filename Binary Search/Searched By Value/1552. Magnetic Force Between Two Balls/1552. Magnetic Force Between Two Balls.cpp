class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position[0];
        while (low < high) {
            
            int mid = high - (high - low) / 2;
            if (helper(position, m, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    
    bool helper(vector<int>& position, int m, int mid) {
     
        int count = 1; //Put the first ball on the first position as default setting
        int i = 0;
        while (i < position.size()) {
            
            int j = i;
            while (j < position.size() && position[j] - position[i] < mid) {
                j++;
            }
            if (j == position.size()) {
                break;
            } else {
                count++;
                i = j;
            }
            if (count == m) {
                return true;
            }
        }
        return false;
    }
};