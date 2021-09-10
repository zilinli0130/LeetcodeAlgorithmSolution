class Solution {
    int n;
    int memo[100001];
    vector<int> visited;
    unordered_map<int, vector<int>> Map;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        n = numCourses;
        visited.resize(n);
        for (auto item : prerequisites) {
            Map[item[0]].push_back(item[1]); //Map[currentCourse] = vector<int>{preCourses}
        }
        
        for (int i = 0; i < n; i++) {
            if (!dfs(i)) {
                cout <<i << endl;
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int currentCourse) {
        
        if (memo[currentCourse] != 0) {
            return true;
        }
        
        //No more prerequisite courses
        if (Map.find(currentCourse) == Map.end()) {
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
        return true;
    }
};
