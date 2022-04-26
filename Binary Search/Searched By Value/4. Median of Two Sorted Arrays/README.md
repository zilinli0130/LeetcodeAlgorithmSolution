# 4. Median of Two Sorted Arrays

###### Tag: Binary Search, Searched by Value

###### Time: O(log(m + n))
###### Space: O(1)







```
Naive Approach by Min Heap
Time: O(m + n)
Space: O(m + n)

typedef vector<int> VII;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        priority_queue<VII, vector<VII>, greater<>> pq;
        if (nums1.size() > 0) {
            pq.push({nums1[0], 0, 1});
        }
        if (nums2.size() > 0) {
            pq.push({nums2[0], 0, 2});
        }
        
        if (pq.size() == 0) {
            return 0;
        }
        
        vector<int> temp;
        while (!pq.empty()) {
            
            int num = pq.top()[0];
            int idx = pq.top()[1];
            int label = pq.top()[2];
            pq.pop();
            
            temp.push_back(num);
            
            if (label == 1 && idx + 1 < nums1.size()) {
                pq.push({nums1[idx + 1], idx + 1, 1});
            } else if (label == 2 && idx + 1 < nums2.size()) {
                pq.push({nums2[idx + 1], idx + 1, 2});
            }
        }
        
        if (temp.size() % 2 == 0) {
            return (double)(temp[temp.size()/2] + temp[temp.size()/2-1])/2;
        }
        return (double)temp[temp.size()/2];
    }
};
```