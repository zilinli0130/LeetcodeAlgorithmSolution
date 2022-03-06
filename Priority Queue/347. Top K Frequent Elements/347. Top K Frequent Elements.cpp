typedef pair<int, int> PII;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        unordered_map<int, int> Map;
        for (const auto& num : nums) {
            Map[num]++;
        }
        
        auto cmp = [](const PII& a, const PII& b) {
            return a.second > b.second;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        
        for (const auto& item : Map) {
            pq.push(item);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};