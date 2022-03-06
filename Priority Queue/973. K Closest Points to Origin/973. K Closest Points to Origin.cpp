class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> res;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            
            return sqrt(a[0] * a[0] + a[1] * a[1]) < sqrt(b[0] * b[0] + b[1] * b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for (const auto& point : points) {
            pq.push(point);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};