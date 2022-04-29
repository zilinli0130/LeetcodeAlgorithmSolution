class Solution {
public:
    int numSquares(int n) {
        
         int visited[n + 1];
        for (int i = 0; i <= n; i++) {
            visited[i] = 0;
        }
        vector<int> squareNumbers;
        for (int i = 1; i <= sqrt(n); i++) {
            if (i % 1 == 0) {
                squareNumbers.push_back(i*i);
            }
        }
        queue<int> q;
        q.push(n);
        
        int res = -1;
        while (!q.empty()) {
            
            res++;
            int len = q.size();
            while (len--) {
                
                int num = q.front();
                q.pop();
                
                if (visited[num] == 1) continue;
                visited[num] = 1;
                // cout << num << endl;
                
                if (num == 0) {
                    return res;
                }
                
                for (const auto& squareNumber : squareNumbers) {
                    
                    int diff = num - squareNumber;
                    if (diff < 0) continue;
                    if (visited[diff]) continue;
                    q.push(diff);
                }
            }
        }
        return -1;
    }
};