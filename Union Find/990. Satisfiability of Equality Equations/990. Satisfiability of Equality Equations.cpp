class Solution {
    unordered_map<char,char> Ancestors;
    
    char FindAncestor(char x) {
        if (Ancestors[x] != x) {
            Ancestors[x] = FindAncestor(Ancestors[x]);
        }
        return Ancestors[x];
    }
    
    void Union(char x, char y) {
        x = Ancestors[x];
        y = Ancestors[y];
        if (x < y) {
            Ancestors[y] = x;
        } else {
            Ancestors[x] = y;

        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        
        vector<string> inEqs;
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                inEqs.push_back(eq);
                Ancestors[eq[0]] = eq[0];
                Ancestors[eq[3]] = eq[3];
                continue;
            }
            Ancestors[eq[0]] = eq[0];
            Ancestors[eq[3]] = eq[3];
        }
        
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                continue;
            }
            if (FindAncestor(eq[0]) != FindAncestor(eq[3])) {
                Union(eq[0], eq[3]);
            }
        }
        
        for (auto& node : Ancestors) {
            FindAncestor(node.first);
        }
        
        for (auto& inEq : inEqs) {
            
            char c1 = inEq[0];
            char c2 = inEq[3];
            if (FindAncestor(c1) == FindAncestor(c2)) {
                return false;
            }
        }
        return true;
    }
};