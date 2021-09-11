class Solution {
    int n;
    int memo[100001];
    vector<int> res;
    vector<int> visited;
    vector<int> marked;
    unordered_map<int, vector<int>> Map;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        n = numCourses;
        visited.resize(n);
        marked.resize(n);
        for (auto item : prerequisites) {
            Map[item[0]].push_back(item[1]); //Map[currentCourse] = vector<int>{preCourses}
        }
        
        for (int i = 0; i < n; i++) {
            if (!dfs(i)) {
                return vector<int>{};
            } 
        }
        return res;
    }
    
    bool dfs(int currentCourse) {
        
        if (memo[currentCourse] != 0) {
            return true;
        }
        
        //No more prerequisite courses
        if (Map.find(currentCourse) == Map.end()) {
            if (marked[currentCourse] != 1) {
                marked[currentCourse] = 1;
                res.push_back(currentCourse);
            }
            return true;
        }
        
        visited[currentCourse] = 1;
        for (auto preCourse : Map[currentCourse]) {
            if (visited[preCourse]) {
                return false;
            }
            if (!dfs(preCourse)) {
                return false;
            }
        }
        visited[currentCourse] = 0;
        memo[currentCourse] = 1;
        if (marked[currentCourse] != 1) {
            marked[currentCourse] = 1;
            res.push_back(currentCourse);
        }
        return true;
    }
};