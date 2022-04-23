class Solution {
public:
    string addBinary(string a, string b){
        
        string res = "";
        int carry = 0;
        int aIdx = a.size() - 1, bIdx = b.size() - 1;
        while (carry == 1|| aIdx >= 0 || bIdx >= 0) {
            
            if (aIdx >= 0 && a[aIdx--] == '1') {
                carry++;
            }
            if (bIdx >= 0 && b[bIdx--] == '1') {
                carry++;
            }
            res += to_string(carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};