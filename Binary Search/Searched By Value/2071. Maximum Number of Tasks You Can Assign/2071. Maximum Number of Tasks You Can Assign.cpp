class Solution {
    vector<int> Tasks;
    vector<int> Workers;
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    
        
        int left = 0, right = tasks.size();
        sort(tasks.begin(), tasks.end()); 
        Tasks = tasks;
        Workers = workers;
        
        while (left < right) {
            
            int mid = right - (right - left) / 2;
            if (isCompleted(pills, strength, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    
    bool isCompleted(int pills, int strength, int mid) {
        
        if (mid > Workers.size()) return false;
        multiset<int> Set(Workers.begin(), Workers.end());
        
        for (int i = mid - 1; i >= 0; i--) {
            
            if (*Set.rbegin() >= Tasks[i]) {
                Set.erase(prev(Set.end()));
            } else {
                
                if (pills == 0) return false;
                auto Worker = Set.lower_bound(Tasks[i] - strength);
                if (Worker == Set.end()) return false;
                Set.erase(Worker);
                pills--;
            }
        }
        return true;
    }
};

