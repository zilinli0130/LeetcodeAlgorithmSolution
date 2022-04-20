class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string res = "";
        int num = columnNumber;
        while (num > 0) {
            int remainder = num % 26;
            if (remainder == 0) {
                num--;
                remainder = num % 26 + 1;
            }
            char letter = (char)(remainder + 64);
            res.push_back(letter);
            num /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


