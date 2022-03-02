class Solution {
    int n = 10000;
    unordered_map<int,int> Ancestors;
    unordered_map<int,vector<int>> rowMap;
    unordered_map<int,vector<int>> colMap;
    
    int FindAncestor(int x) {
        
        if (Ancestors[x] != x) {
            Ancestors[x] = FindAncestor(Ancestors[x]);
        }
        return Ancestors[x];
    }
    
    void Union(int x, int y) {
        
        x = Ancestors[x];
        y = Ancestors[y];
        if (x < y) {
            Ancestors[y] = x;
        } else {
            Ancestors[x] = y;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        
        for (auto& stone : stones) {
            
            int i = stone[0];
            int j = stone[1];
            int num = i * n + j;
            Ancestors[num] = num;
            rowMap[i].push_back(num);
            colMap[j].push_back(num);
        }
        
        for (auto& item: rowMap) {
            
            int rootStoneNum = item.second[0];
            for (int i = 1; i < item.second.size(); i++) {
                
                int stoneNum = item.second[i];
                if (FindAncestor(rootStoneNum) != FindAncestor(stoneNum)) {
                    Union(rootStoneNum, stoneNum);                  
                }
            }
        }
        
        for (auto& item: colMap) {
            
            int rootStoneNum = item.second[0];
            for (int i = 1; i < item.second.size(); i++) {
                
                int stoneNum = item.second[i];
                if (FindAncestor(rootStoneNum) != FindAncestor(stoneNum)) {
                    Union(rootStoneNum, stoneNum);                  
                }
            }
        }
        
        unordered_set<int> unionSet;
        for (auto& item : Ancestors) {
            int rootStoneNum = FindAncestor(item.first);
            unionSet.insert(rootStoneNum);
        }        
        return stones.size() - unionSet.size();
    }
};