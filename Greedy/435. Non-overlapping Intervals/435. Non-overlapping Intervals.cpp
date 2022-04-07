class Solution {
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int res = 0;
        sort(intervals.begin(), intervals.end(), compare);
        
        int i = 0;
        while (i < intervals.size()) {
            
            int lastEnd = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] < lastEnd) {
                j++;
                res++;
            }
            i = j;
        }
        return res;
    }
};