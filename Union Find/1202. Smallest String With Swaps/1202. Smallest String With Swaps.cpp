class Solution {
    int Ancestor[100001];
    int FindAncestor(int x) {
        
        if (Ancestor[x] != x) {
            Ancestor[x] = FindAncestor(Ancestor[x]);
        }
        return Ancestor[x];
    }
    
    void Union(int x, int y) {
        
        x = Ancestor[x];
        y = Ancestor[y];
        if (x < y) {
            Ancestor[y] = x;
        } else {
            Ancestor[x] = y;
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        for (int i = 0; i < n; i++) {
            Ancestor[i] = i;
        }
        
        for (auto& pair : pairs) {
            if (FindAncestor(pair[0]) != FindAncestor(pair[1])) {
                Union(pair[0],pair[1]);
            }
        }
        
        unordered_map<int, vector<int>> unionMap;
        for (int i = 0; i < n; i++) {
            unionMap[FindAncestor(i)].push_back(i);
        }
        
        for (auto item : unionMap) {
            
            string temp;
            for (auto& i : item.second) {
                temp.push_back(s[i]);
            }
            sort(temp.begin(), temp.end());
            
            int j = 0;
            for (auto& i : item.second) {
                s[i] = temp[j++];
            }
        }
        return s;
    }
};