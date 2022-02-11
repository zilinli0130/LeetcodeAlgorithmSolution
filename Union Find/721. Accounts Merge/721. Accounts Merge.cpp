class Solution {
    unordered_map<string,string> Owners; //email -> name    
    unordered_map<string,string> Ancestors; //email -> root email
    unordered_map<string,set<string>> tempResult; //root email -> set of emails
    
    string FindAncestor(string x) {
        if (Ancestors[x] != x) {
            Ancestors[x] = FindAncestor(Ancestors[x]);
        }
        return Ancestors[x];
    }
    
    void Union(string x, string y) {
        
        x = Ancestors[x];
        y = Ancestors[y];
        if (x < y) {
            Ancestors[y] = x;
        } else {
            Ancestors[x] = y;    
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for (auto& account : accounts) {
            
            sort(account.begin() + 1, account.end());
            for (int i = 1; i < account.size(); i++) {
                Owners[account[i]] = account[0];
                if (Ancestors.find(account[i]) == Ancestors.end()) {
                    Ancestors[account[i]] = account[i];
                }
            }
            
            for (int i = 2; i < account.size(); i++) {
                if (FindAncestor(account[i]) != FindAncestor(account[1])) {
                    Union(account[i], account[1]);
                }
            }
        }
        
        for (auto& item : Ancestors) {
            string rootEmail = FindAncestor(item.second);
            tempResult[rootEmail].insert(item.first);
        }
        
        vector<vector<string>> res;
        for (auto& item : tempResult) {
            
            vector<string> temp{Owners[item.first]};
            for (auto& email : item.second) {
                temp.push_back(email);
            }
            res.push_back(temp);
        }
       return res;
    }
};