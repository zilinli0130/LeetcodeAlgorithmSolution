class Solution {
    string s;
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        
        this->s = s;
        string curStr = "";
        dfs(curStr, 0, 0);
        return res;
    }
    
    void dfs(string& curStr, int curIdx, int curPart) {
        
        if (curPart > 4) {
            return;
        }
        
        if (curIdx == s.size()) {
            if (curPart == 4) {
                res.push_back(curStr);
            }
            return;
        }
        
        for (int len = 1; len <= min(3, (int)s.size() - curIdx + 1); len++) {
            
            string tempStr = s.substr(curIdx, len);
            int num = stoi(tempStr);
            if (!(num >= 0 && num <= 255)) continue;
            if (tempStr.size() > 1 && tempStr[0] == '0') continue;
            
            int flag = 0;
            if (curStr.size() > 0) {
                curStr += '.';
                flag = 1;
            }
            curStr += tempStr;
            dfs(curStr, curIdx + len, curPart + 1);
            if (flag == 1) {
                curStr = curStr.substr(0, curStr.size() - tempStr.size() - 1);
            } else {
                curStr = curStr.substr(0, curStr.size() - tempStr.size());
            }
        }
    }
};