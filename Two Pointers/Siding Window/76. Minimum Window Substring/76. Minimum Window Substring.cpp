class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int res = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            res += grumpy[i] == 0 ? customers[i] : 0;
        }
        
        int i = 0;
        int temp = 0;
        int window = 0;
        for (int j = 0; j < n; j++) {
            temp += grumpy[j] == 1 ? customers[j] : 0;
            if (j - i + 1 == minutes) {
                window = max(window, temp);
                temp -= grumpy[i] == 1 ? customers[i] : 0;
                i++;
            } 
        }
        return res + window;
    }
};