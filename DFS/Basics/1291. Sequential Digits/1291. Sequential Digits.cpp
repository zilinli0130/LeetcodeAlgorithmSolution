class Solution {
    int low, high;
    vector<int> res;
public:
    vector<int> sequentialDigits(int low, int high) {
        this->low = low;
        this->high = high;
        
        int lowDigit = 0, highDigit = 0;
        while (low > 0) {
            low /=10;
            lowDigit++;
        }
        while (high > 0) {
            high /=10;
            highDigit++;
        }
        
        for (int maxDigit = lowDigit; maxDigit <= highDigit; maxDigit++) {
            for (int startNum = 1; startNum <= 9; startNum++) {
                dfs(0.0, startNum, 1, maxDigit);
            }
        }
        return res;
    }
    
    void dfs(double temp, int startNum, int curDigit, int maxDigit) {
        
        if (curDigit == maxDigit + 1) {
            if (temp >= low && temp <= high) {
                res.push_back(temp);
            }
            return;
        }
        
        if (startNum > 9) {
            return;
        }
        dfs((temp + startNum*0.1)*10, startNum + 1, curDigit + 1, maxDigit);
    }
    
};