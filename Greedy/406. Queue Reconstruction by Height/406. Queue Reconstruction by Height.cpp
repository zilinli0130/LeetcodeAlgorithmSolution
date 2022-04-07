class Solution {
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>> res;
        sort(people.begin(), people.end(), compare);
        
        for (int i = 0; i < people.size(); i++) {
            
            if (res.size() == 0) {
                res.push_back(people[i]);
            } else {
                int idx = people[i][1];
                res.insert(res.begin() + idx, people[i]);
            }
        }
        return res;
    }
};


