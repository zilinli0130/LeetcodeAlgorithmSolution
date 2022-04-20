class Solution {
public:
    string toHex(int n) {
        
        if (n == 0) {
            return "0";
        }
        
        string res = "";
        unsigned int num = n;
        cout << num << endl;
        while (num > 0) {
            
            int remainder = num % (1<<4);
            char digit = remainder < 10 ? remainder + '0' : (remainder - 10) + 'a';
            res.push_back(digit);
            num /= (1<<4);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};