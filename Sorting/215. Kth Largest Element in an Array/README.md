# 215. Kth Largest Element in an Array
###### Tag: Heap Sort, Binary Search

###### Time: O(Nlog(K))
###### Space: O(K) 

We could maintain a min heap with size of `k` and loop through the array. The `Kth` largest element would
be the top element of the min heap after finishing the loop.

Follow-up: Binary Search (Searched by Value)

if we assume that the number `m` is the `kth` largest element, then the count of numbers which are greater than or equal to `m` must be greater than or equal to `k`. Ohterwise, the number `m` must not be the `kth` largest element.


```
Time: at most O(N*32)
Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        long left = INT_MIN, right = INT_MAX;
        while (left < right) {
            
            int mid = right - (right - left)/2;
            if (count(nums, mid) >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }  
        return left;
    }

    int count(vector<int>&nums, int m) {
        int res = 0;
        for (auto num: nums) {
            res += (num >= m);
        }
        return res;
    }
};
```
