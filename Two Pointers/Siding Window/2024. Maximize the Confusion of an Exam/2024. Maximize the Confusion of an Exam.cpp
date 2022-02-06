class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int res = 0;
        int n = answerKey.size();
        answerKey = '#' + answerKey;
        vector<int> prefixSumT(n + 1, 0);
        vector<int> prefixSumF(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSumT[i] = prefixSumT[i - 1] + (answerKey[i] == 'T'? 1 : 0);
            prefixSumF[i] = prefixSumF[i - 1] + (answerKey[i] == 'F'? 1 : 0);
        }
        
        //Flip 'F'
        int i = 1;
        for (int j = 1; j <= n; j++) {
            
            if ((j - i + 1) - (prefixSumT[j] - prefixSumT[i - 1]) <= k) {
                
                while (i <= n && j <= n && (j - i + 1) - (prefixSumT[j] - prefixSumT[i - 1]) <= k) {
                    j++;
                }
                j--;
                res = max(res, j - i + 1);
            }
            i++;
        }
        
        //Flip 'T'
        i = 1;
        for (int j = 1; j <= n; j++) {
            
            if ((j - i + 1) - (prefixSumF[j] - prefixSumF[i - 1]) <= k) {
                
                while (i <= n && j <= n && (j - i + 1) - (prefixSumF[j] - prefixSumF[i - 1]) <= k) {
                    j++;
                }
                j--;
                res = max(res, j - i + 1);
            }
            i++;
        }
        return res;
    }
};