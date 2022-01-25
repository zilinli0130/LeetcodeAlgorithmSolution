class Solution {
    int memo[1<<21];
    int maxChoosableInteger, desiredTotal;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        this->maxChoosableInteger = maxChoosableInteger;
        this->desiredTotal = desiredTotal;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        return dfs(0,0);
    }
    
    bool dfs(int state, int curSum) {
        
        if (memo[state] == 1) {
            return false;
        }
        if (memo[state] == 2) {
            return true;
        }
        
        for (int i = 1; i <= maxChoosableInteger; i++) {
            
            if (state & (1<<i)) continue;
            if (curSum + i >= desiredTotal) {
                memo[state] = 2;
                return true;
            }
            if (dfs(state + (1<<i), curSum + i) == false) {
                memo[state] = 2;
                return true;
            }
        }
        memo[state] = 1;
        return false;
    }
};