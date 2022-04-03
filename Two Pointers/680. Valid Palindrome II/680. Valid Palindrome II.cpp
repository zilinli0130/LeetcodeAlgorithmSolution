class Solution {
public:
    bool validPalindrome(string s) {
        
        int flag = 0;
        int l = 0, r = s.size() - 1;
        
        while (l < r) {
            
            if (s[l] != s[r]) {
                
                int tempL = l;
                int tempR = r;
                flag = 1;
                if (s[l + 1] == s[r]) {
                    
                    l++;
                    while (l < r) {
                        if (s[l] != s[r]) {
                            flag = 2;
                            break;
                        }
                        l++;
                        r--;
                       
                    }
                    if (flag == 1) {
                        return true;
                    }
                }
                l = tempL;
                r = tempR;

                if (s[l] == s[r - 1]) {
                    r--;
                    while (l < r) {
                        if (s[l] != s[r]) {
                            return false;
                        }
                        l++;
                        r--;
                    }
                    return true;
                }
                return false;
                
            } else if (s[l] == s[r]) {
                l++;
                r--;
            }
        }
        return true;
    }
};