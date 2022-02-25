class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        queue<string> q;
        vector<string> res;
        int n = recipes.size(); 
        unordered_map<string, int> inDegreeMap;
        unordered_map<string, vector<string>> next;
       
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < ingredients[i].size(); j++) {
               next[ingredients[i][j]].push_back(recipes[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            inDegreeMap[recipes[i]] = ingredients[i].size();
        }
        
        for (auto& item : supplies) {
            q.push(item);
        }
        
        while (!q.empty()) {
            
            int len = q.size();
            while (len--) {
                
                string node = q.front();
                q.pop();
                
                for (auto& item : next[node]) {
                    inDegreeMap[item]--;
                    if (inDegreeMap[item] == 0) {
                        res.push_back(item);
                        q.push(item);
                    }
                }
            }
        }
        return res;
    }
};