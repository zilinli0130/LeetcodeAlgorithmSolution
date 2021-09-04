class Solution {
    int n;
    int memo[1<<24];
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        //Get rid of fake offers
        n = price.size();
        vector<vector<int>> optimizedSpecial;
        for (auto offer : special) {
            int totalPrice = 0;
            for (int i = 0; i < n; i++) {
                totalPrice += offer[i] * price[i];
            }
            if (totalPrice > offer[n]) {
                optimizedSpecial.push_back(offer);
            }
        }
        
        //DFS
        int state = 0;
        for (int i = 0; i < n; i++) {
            state += needs[i]<<(i*4);
        }
        return dfs(price, optimizedSpecial, state);
    }
    
    int dfs(vector<int>& price, vector<vector<int>>& optimizedSpecial, int state) {
        
        if (state == 0) {
            return 0;
        }
        if (memo[state] != 0) {
            return memo[state];
        }
        
        int res = 0;
        //Use normal price only
        for (int i = 0; i < n; i++) {
            res += (state>>(i*4)) % 16 * price[i];
        }
        
        //Use special
        for (auto offer: optimizedSpecial) {
            
            //Check if it is valid to use this offer
            int valid = 1;
            for (int i = 0; i < n; i++) {
                if ((state>>(i*4)) % 16 < offer[i]) {
                    valid = 0;
                    break;
                }
            }
            
            if (!valid) continue;
            
            int state2 = state;
            for (int i = 0; i < n; i++) {
                state2 -= offer[i]* (1<<(i*4));
            }
            res = min(res, offer[n] + dfs(price, optimizedSpecial, state2));
        }
        memo[state] = res;
        return res;
    }
};

/*
state = XXXX XXXX XXXX XXXX XXXX XXXX, 24bits
The value for each item : 0-15

Add number of ith item to state : state += needs[i]<<(i*4)
Get number of ith item inside state : (state>>(i*4) % 2^4)

*/