class Solution {
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if (points.size() == 0) {
            return 0;
        }
        
        int res = 0;
        sort(points.begin(), points.end(), compare);
        
        int idx = 0;
        while (idx < points.size()) {
            
            int lastEnd = points[idx][1];
            while (idx < points.size() && points[idx][0] <= lastEnd) {
                idx++;
            }
            res++;
        }
        return res;
    }
};
