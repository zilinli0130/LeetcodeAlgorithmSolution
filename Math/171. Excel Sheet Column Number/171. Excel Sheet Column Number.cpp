class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int res = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            char letter = columnTitle[i];
            int remainder = (int)(letter - 'A' + 1);
            res = res*26 + remainder;   
        }        
        return res;
    }
};