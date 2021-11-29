class Solution {
    vector<int> Ancestor;
    static bool compare(vector<int>&a, vector<int>&b) {
        return a[2] < b[2];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        Ancestor.resize(n);
        for (int i = 1; i < n; i++) {
            Ancestor[i] = i;
        }
        Ancestor[firstPerson] = 0;
        unordered_set<int> Set({0, firstPerson});        
        sort(meetings.begin(), meetings.end(), compare);
        
        for (int i = 0; i < meetings.size(); i++) {
            
            int idx = i;
            unordered_set<int> members;
            while (idx < meetings.size() && meetings[i][2] == meetings[idx][2]) {
                
                int mem1 = meetings[idx][0];
                int mem2 = meetings[idx][1];
                
                if (FindAncestor(mem1) != FindAncestor(mem2)) {
                    Union(mem1, mem2);
                }
                members.insert(mem1);
                members.insert(mem2);
                idx++;
            }
            
            for (auto x : members) {
                
                if (FindAncestor(x) == 0) {
                    Set.insert(x);
                } else {
                    Ancestor[x] = x;
                }
            }
            i = idx - 1;
        }
        vector<int> res(Set.begin(), Set.end());
        return res;
    }
    
    int FindAncestor(int x) {
        
        if (Ancestor[x] != x) {
            Ancestor[x] = FindAncestor(Ancestor[x]);
        }
        return Ancestor[x];
    }
    
    void Union (int x, int y) {
        
        x = Ancestor[x];
        y = Ancestor[y];
        if (x <= y) {
            Ancestor[y] = x;
        } else {
            Ancestor[x] = y;
        }
    }
};