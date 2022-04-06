# 215. Kth Largest Element in an Array
###### Tag: Heap Sort, Binary Search

###### Time: O(Nlog(K))
###### Space: O(K) 

We could maintain a min heap with size of `k` and loop through the array. The `Kth` largest element would
be the top element of the min heap after finishing the loop.

Follow-up 1: Binary Search (Searched by Value)

If we assume that the number `m` is the `kth` largest element, then the count of numbers which are greater than or equal to `m` must be greater than or equal to `k`. Ohterwise, the number `m` must not be the `kth` largest element.


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
```
Follow-up 2: Quick Select
Time: average O(N), worst O(N^2)
Space: recursion call stack depth

We could find a pivot and put all the numbers which are smaller than pivot to the left and put all the numbers which are greater than the pivot
to the right. Afterward, we need to recursively find the Kth element inside nums based on the size of small nunber subarray, pivot subarray and
large number subarray.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
    int quickSelect(vector<int>& nums, int st, int en, int k) {
        
        int pivot = nums[(st + en)/2];
        int leftIdx = st, midIdx = st, rightIdx = en;
        
        while (midIdx <= rightIdx) {
            
            if (nums[midIdx] < pivot) {
                swap(nums[midIdx], nums[leftIdx]);
                leftIdx++;
                midIdx++;
            } else if (nums[midIdx] > pivot) {
                swap(nums[midIdx], nums[rightIdx]);
                rightIdx--;
            } else {
                midIdx++;
            }
        }
        
        if (en - rightIdx >= k) {
            return quickSelect(nums, rightIdx + 1, en, k);
        } else if (en - leftIdx + 1 >= k) {
            return pivot;
        } else {
            return quickSelect(nums, st, leftIdx - 1, k - (en - leftIdx + 1));
        }
        
    }
};

```
