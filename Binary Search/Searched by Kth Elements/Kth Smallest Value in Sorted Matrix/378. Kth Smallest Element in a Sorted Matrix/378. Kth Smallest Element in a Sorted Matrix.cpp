class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int N = matrix.size();
        int left = matrix[0][0], right = matrix[N - 1][N - 1];
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            if (smallerOrEqual(matrix, N, mid) < k) {
                left = mid + 1; //(mid + 1, right)
            } else {
                right = mid; //(left, mid)
            }
        }
        return left;
    }
    
    int smallerOrEqual(vector<vector<int>>& matrix, int N, int mid) {
        
        int count = 0;
        int i = N - 1, j = 0;
        while (i >= 0 && j < N) {
            
            if (matrix[i][j] <= mid) {
                count += (i + 1);
                j++;
            } else {
                i--;
            }
        }
        return count;
    }
    
};

/*
[[1,5,9],
[10,11,13],
[12,13,15]]
*/