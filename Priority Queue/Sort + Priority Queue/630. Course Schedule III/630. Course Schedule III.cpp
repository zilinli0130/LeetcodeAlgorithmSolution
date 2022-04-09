class Solution {
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int days = 0;
        int n = courses.size();
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), compare);
        
        for (int i = 0; i < n; i++) {
            
            pq.push(courses[i][0]);
            days += courses[i][0];
            
            if (days > courses[i][1]) {
                days -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};