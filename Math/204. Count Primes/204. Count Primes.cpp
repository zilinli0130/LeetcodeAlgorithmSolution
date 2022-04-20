class Solution {
public:
    int countPrimes(int n) {
        
        if (n < 3) {
            return 0;
        }
        
        vector<int> isPrime(n, 1);
        isPrime[0] = 0, isPrime[1] = 0;
        
        for (int i = 2; i <= sqrt(n); i++) {
            if (isPrime[i] == 0) {
                continue;
            }
            
            for (long j = i*i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }        
        return accumulate(isPrime.begin(), isPrime.end(), 0);
    }
};