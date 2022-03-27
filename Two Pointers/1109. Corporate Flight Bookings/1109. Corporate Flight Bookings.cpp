class Solution {
    int diff[20002];
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> res;
        for (const auto& booking : bookings) {
            diff[booking[0]] += booking[2];
            diff[booking[1] + 1] -= booking[2];
        }
        
        int curSeat = 0;
        for (int i = 1; i <= n; i++) {
            
            curSeat += diff[i];
            res.push_back(curSeat);
            
        }
        return res;
    }
};