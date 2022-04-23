class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if (num == 1) {
            return true;
        }
        
        int leftEnd = 1, rightEnd = num;
        while (leftEnd < rightEnd) {

            long long midPoint = leftEnd + (rightEnd - leftEnd) / 2;
            unsigned long long temp = midPoint * midPoint;
            if (temp < num) {
                leftEnd = midPoint + 1;
            } else {
                rightEnd = midPoint;
                if (temp == num) {
                    return true;
                }
            }
        }
        return false;
    }
};