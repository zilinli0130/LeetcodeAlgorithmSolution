# 692. Top K Frequent Words

###### Tag: Priority Queue, Hash Table

###### Time: O(N + Nlogk)
###### Space: O(N)

We can use priority queue of size `k` to keep track of the most `k` frequent words while looping throught the entire words array. The time compllexity
would be `O(N*log(K))`. Additionally, we need to store a hash table to record the appeared word and its frequency which costs `O(N)` space.


```
Follow-up" Quick Select

Time: O(n + Nlog(N)) if N is close to K, O(N + Klog(K)) if K << N
Space: O(N)

typedef pair<string, int> PII;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // Time: O(N)
        vector<PII> strList;
        unordered_map<string, int> map;
        for (const auto& word : words) {
            map[word]++;
        }
        
        for (const auto& item : map) {
            strList.push_back({item.first, item.second});
        }
        
        // Time: average O(N), worse case O(N^2) 
        quickSelect(strList, 0, strList.size() - 1, k);
        
        // Time: O(klogk) if k << n
        sort(strList.begin(), strList.end(), [](PII& s1, PII& s2) {
            if (s1.second == s2.second) {
                return s1.first < s2.first;
            }
            return s1.second > s2.second;
        });
        
        // Time: O(k)
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(strList[i].first);
        }
        return res;
    }
         
    void quickSelect(vector<PII>& strList, int low, int high, int k) {
        
        int pivot = strList[(low + high)/2].second;
        int leftIdx = low, midIdx = low, rightIdx = high;
        
        while (midIdx <= rightIdx) {
            
            if (strList[midIdx].second > pivot) {
                swap(strList[midIdx], strList[leftIdx]);
                leftIdx++;
                midIdx++;
            } else if (strList[midIdx].second < pivot) {
                swap(strList[midIdx], strList[rightIdx]);
                rightIdx--;
            } else {
                midIdx++;
            }
        }
        
        if (rightIdx == k - 1) {
            return;
        } else if (rightIdx < k - 1) {
            quickSelect(strList, rightIdx + 1, high, k);
        } else if (rightIdx > k - 1) {
            quickSelect(strList, low, rightIdx - 1, k);
        }
        return;
    }
};
```