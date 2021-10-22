class Solution {
    int n;
    int memo[101][101]; 
    vector<vector<int>> Graph;
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    
        n = numCourses;
        Graph.resize(n);
        vector<bool> res;
        for (auto item : prerequisites) {
            Graph[item[1]].push_back(item[0]); //Take item[0] before item[1]
        }
        
        for (auto query : queries) {
            if (memo[query[1]][query[0]] != 0) {
                res.push_back(false);
                continue;
            } 
            res.push_back(dfs(query[1], query[0]));
        }
        return res;
    }
    
    
    bool dfs(int curCourse, int targetCourse) {
        
        if (curCourse == targetCourse) {
            return true;
        }
        
        if (memo[curCourse][targetCourse] != 0) {
            return false;
        }
        
        for (auto prevCourse : Graph[curCourse]) {
            
            if (dfs(prevCourse, targetCourse)) {
                return true;
            }
        }
        memo[curCourse][targetCourse] = 1;
        return false;;
    }
};