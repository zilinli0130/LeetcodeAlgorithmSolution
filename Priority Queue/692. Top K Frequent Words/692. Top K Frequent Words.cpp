typedef pair<string, int> PII;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> res;
        unordered_map<string, int> Map;
        for (const auto& word : words) {
            Map[word]++;
        }
        
        auto cmp = [](const PII& a, const PII& b) { 
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        
        
        //O(N*log(K))
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
        reverse(res.begin(), res.end());        
        return res;
    }
};
