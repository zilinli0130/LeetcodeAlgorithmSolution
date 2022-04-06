typedef pair<int, int> PII;
class Solution {
public:
    string frequencySort(string s) {
        
        string res = "";
        unordered_map<char, int> Map;
        for (const auto& ch : s) {
            Map[ch]++;
        }
        
        auto cmp = [](const PII& a, const PII& b) {
            return a.second < b.second;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        
        for (const auto& item : Map) {
            pq.push(item);
        }
        
        while (!pq.empty()) {
            
            int count = 0;
            while (count < pq.top().second) {
                res += pq.top().first;
                count++;
            }
            pq.pop();
        }
        return res;
    }
};