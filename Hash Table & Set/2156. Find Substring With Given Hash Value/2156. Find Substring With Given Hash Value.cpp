using LL = long long;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {

        LL hash = 0;
        int res = -1;
        LL powerK = 1;
        int n = s.size();
        for (int i = 1; i <= k - 1; i++) {
            powerK = powerK * power % modulo;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            
            //len of substring = k + 1, remove the character at the most right side
            if (n - 1 - i + 1 > k) {
                hash = hash - (s[i + k]-'a' + 1) * powerK % modulo;
                hash = (hash + modulo) % modulo;
            }
            
            hash = hash * power % modulo;
            hash = (hash + s[i]-'a' + 1) % modulo;
            
            if (i + k - 1 <= n - 1 && hash == hashValue) {
                res = i;                
            }
        }
        return s.substr(res, k);
    }
};

