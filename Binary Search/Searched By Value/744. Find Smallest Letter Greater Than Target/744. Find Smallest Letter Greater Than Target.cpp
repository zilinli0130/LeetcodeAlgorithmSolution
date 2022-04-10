class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int l = 0, r = letters.size() - 1;
        while (l < r) {
            
            int mid = l + (r - l)/2;
            if (letters[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return letters[l] <= target ? letters[0] : letters[l];
    }
};