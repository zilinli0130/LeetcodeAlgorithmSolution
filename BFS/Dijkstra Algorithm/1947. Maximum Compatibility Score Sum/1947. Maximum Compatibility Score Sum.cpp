typedef pair<int, int> PII; //{state, profit}
class Solution {
    int match[8][8];
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int n = students.size();
        int m = students[0].size();
        vector<int> visited((1<<n), 0);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, 0});
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int k = 0; k < m; k++) {
                    count += (students[i][k] == mentors[j][k]);
                }
                match[i][j] = m - count;
            }
        }
        
        while (!pq.empty()) {
            
            int cost = pq.top().first;
            int state = pq.top().second;
            pq.pop();
            
            if (visited[state]) continue;
            visited[state] = 1;
            
            int j = __builtin_popcount(state);
            if (j == n) {
                return n * m - cost;
            }
            
            for (int i = 0; i < n; i++) {
                if ((state>>i) & 1) continue;
                int nextState = state + (1<<i);
                if (visited[nextState]) continue;
                pq.push({cost + match[i][j], nextState});
            }
        }
        return -1;
    }
};


// state = 000
// state = 111
    
// state = 00101100 -> k bits of one in state represents that there
// are k students being paired with the [0:k-1] mentors

