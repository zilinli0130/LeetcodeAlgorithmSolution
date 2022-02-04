class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int balance = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
        }
        if (balance < 0) {
            return -1;
        }
        balance = 0;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
            if (balance < 0) {
                balance = 0;
                res = i + 1;
            }
        }
        return res;
    }
};


    