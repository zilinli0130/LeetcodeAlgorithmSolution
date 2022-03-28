class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int cost = 0;
        int x1 = startPos[0], y1 = startPos[1];
        int x2 = homePos[0], y2 = homePos[1];
        
        if (x1 < x2) {
            cost += sumHelper(rowCosts, x1 + 1, x2);
            
        } else if (x1 > x2) {
            cost += sumHelper(rowCosts, x2, x1 - 1);
        }
        
        if (y1 < y2) {
            cost += sumHelper(colCosts, y1 + 1, y2);
            
        } else if (y1 > y2) {
            cost += sumHelper(colCosts, y2, y1 - 1);
        }
        return cost;
    }
    
    int sumHelper(vector<int>& arr, int st, int en) {
        
        int totalSum = 0;
        for (int i = st; i <= en; i++) {
            totalSum += arr[i];
        }
        return totalSum;
    }
};