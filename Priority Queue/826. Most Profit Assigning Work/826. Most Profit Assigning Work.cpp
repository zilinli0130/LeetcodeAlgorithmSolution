class Solution {
    unordered_map<int, int> Map;
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        sort(worker.begin(), worker.end());        
        for (int i = 0; i < profit.size(); i++) {
            if (Map.find(profit[i]) == Map.end()) {
                Map[profit[i]] = difficulty[i];
            } else {
                Map[profit[i]] = min(Map[profit[i]], difficulty[i]);
            }
        }
        return isCapable(profit, worker);
    }
    
    int isCapable(vector<int>& profit, vector<int>& worker) {
        
        int res = 0;
        int num = worker.size();
        int idx =  profit.size() - 1;
        sort(profit.begin(), profit.end());
        multiset<int> Set(worker.begin(), worker.end());
        
        while (idx >= 0 && num > 0) {

            int diff = Map[profit[idx]];

            if (*Set.rbegin() >= diff) {
                res += profit[idx];
                Set.erase(prev(Set.end()));
                num--;
                continue;
            } else {
                idx--;
            }
        }
        return res;
    }
};