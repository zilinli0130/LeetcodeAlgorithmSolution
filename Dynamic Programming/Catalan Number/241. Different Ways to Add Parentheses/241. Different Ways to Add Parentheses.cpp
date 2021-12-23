class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
    
    vector<int> dfs(string exp) {
        
        vector<int> res;
        for (int i = 0; i < exp.size(); i++) {
            
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                
                vector<int> left = dfs(exp.substr(0, i));
                vector<int> right = dfs(exp.substr(i + 1));
                
                for (auto l : left) {
                    for (auto r : right) {
                        if (exp[i] == '+') {
                            res.push_back(l + r);
                        } else if (exp[i] == '-') {
                            res.push_back(l - r);
                        } else if (exp[i] == '*') {
                            res.push_back(l * r);
                        }
                    }
                }
                
            }
        }
        //exp[i] is a number
        if (res.empty()) {
            res.push_back(stoi(exp));
        }
        return res;
    }
};