# 347. Top K Frequent Elements
###### Tag: Priority Queue, Hash Table

Similar problem referring to [692. Top K Frequent Words](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/Priority%20Queue/692.%20Top%20K%20Frequent%20Words)

```
Follow-up: Quick Select
Time: O(N + KlogK) in average, O(NlogN) in worst case
Space: o(N)

typedef pair<int, int> PII;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<PII> temp;
        unordered_map<int, int> map;
        for (const auto& num : nums) {
            map[num]++;
        }
        
        for (const auto& item : map) {
            temp.push_back({item.first, item.second});
        }
        
        // Time: O(N) in average, O(N^2) in worse case
        quickSelect(temp, 0, temp.size() - 1, k);
        
        // Time: O(KlogK) in average, O(NlogN) in worst case
        if (k < temp.size()) {
            sort(temp.begin(), temp.begin() + k, [](PII& a, PII& b) {
                return a.second > b.second;
            });
        } else if (k == temp.size()) {
            sort(temp.begin(), temp.end(), [](PII& a, PII& b) {
                return a.second > b.second;
            });
        }
        
        // Time: O(k)
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(temp[i].first);
        }
        return res;
    }
    
    void quickSelect(vector<PII>& temp, int low, int high, int k) {
        
        int pivot = temp[(low + high)/2].second;
        int leftIdx = low, midIdx = low, rightIdx = high;
        
        while (midIdx <= rightIdx) {
            
            if (temp[midIdx].second > pivot) {
                swap(temp[midIdx], temp[leftIdx]);
                leftIdx++;
                midIdx++;
            } else if (temp[midIdx].second < pivot) {
                swap(temp[midIdx], temp[rightIdx]);
                rightIdx--;
            } else {
                midIdx++;
            }
        }
        
        if (rightIdx == k - 1) {
            return;
        } else if (rightIdx < k - 1) {
            quickSelect(temp, rightIdx + 1, high, k);
        } else if (rightIdx > k - 1) {
            quickSelect(temp, low, rightIdx - 1, k);
        }
        return;
    }
};

/*
1. Sort the entire array in non-increasing order based on the frequency of element
    Time: O(NlogN)
    Space: O(N)
    
2. Heap Sort (maintain a min heap with size of k based on the frequency of element)
    Time: O(N + NlogK)
    Space: O(N)

3. Quick Select
    Time: O(N + KlogK)
    Space: O(N)
*/
```