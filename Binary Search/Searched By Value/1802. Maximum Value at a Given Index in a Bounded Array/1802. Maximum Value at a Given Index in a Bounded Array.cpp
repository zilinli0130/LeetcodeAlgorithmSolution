typedef long long LL;
class Solution {
    int n,index,maxSum;
public:
    int maxValue(int n, int index, int maxSum) {
        
        this->n = n;
        this->index = index;
        this->maxSum = maxSum;
        LL l = 1, r = maxSum;
        while (l < r) {
            
            LL mid = r + (l - r) / 2; 
            if (checkOK(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

private:
    bool checkOK(LL m) {
        
        LL sum = 0;
        if (m > index) {
            sum += (m - index + m) * (index + 1) / 2;
        } else {
            sum += (1 + m) * m / 2;
            sum += index + 1 - m;
        }
        
        if (m > n - index) {
            sum += (m + m - (n - index) + 1) * (n - index) / 2;
        } else {
            sum += (m + 1) * m / 2;
            sum += (n - (index + m));
        }
        return sum - m <= maxSum;
    }
};    