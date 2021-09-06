typedef long long ll;
class Solution {
    int n;
    int batchSize;
    unordered_map<ll, int> memo;
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        
        n = groups.size();
        this->batchSize = batchSize;
        vector<int> remainders(batchSize);
        for (auto group : groups) {
            remainders[group%batchSize]++;
        }
        
        ll state = 0; //5 * batchSize bits
        for (int i = 0; i < batchSize; i++) {
            state += (ll)remainders[i]<<(i*5);
        }
        return dfs(state, 0, 0);
    }
    
    int dfs(ll state, int preSum, int count) {
     
        if (count == n) {
            return 0;
        }
        
        if (memo.find(state) != memo.end()) {
            return memo[state];
        }
        
        int res = 0;
        int happy = (preSum % batchSize == 0);
        for (int i = 0; i < batchSize; i++) {
            
            if ((state>>(i*5))%32 == 0) continue;
            state -= (1ll<<(i*5));
            res = max(res, dfs(state, (preSum + i)%batchSize, count + 1));
            state += (1ll<<(i*5));
        }
        memo[state] = res + happy;
        return res + happy;
    }
};