class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        // brute force solution
        // time complexity->O(n*m);
        // space complexity->O(1);
        // for(int i=0;i<n;i++){
        //     if(target>=matrix[i][0]&&target<=matrix[i][m-1]){
        //         for(int j=0;j<m;j++){
        //             if(matrix[i][j]==target){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        // for(int i=0;i<n;i++){
        //     if(target>=matrix[i][0]&&target<=matrix[i][m-1]){
        //         int left=0;
        //         int right=m-1;
        //         while(left<=right){
        //             int mid=(left+right)/2;
        //             if(matrix[i][mid]>target){
        //                 right=mid-1;
        //             }
        //             if(matrix[i][mid]<target){
        //                 left=mid+1;
        //             }
        //             if(matrix[i][mid]==target){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // Time complexity:nlong(n);
        int low = 0;
        int high = (n * m) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int i = mid / m;
            int j = mid % m;
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] < target)
            {
                low = mid + 1;
            }
            if (matrix[i][j] > target)
            {
                high = mid - 1;
            }
        }
        return false;
    }
};
// How to apply binary search on the 1D array without actually flattening the 2D matrix:
// 1. Treat the 2D matrix as a imaginary 1D array.
// 2. Apply binary search on the imaginary 1D array.
// 3. Convert the index of the imaginary 1D array back to the row and column indices of the 2D matrix.
// 4. The element at the index (mid) of the 1D array is matrix[mid / m][mid % m] in the 2D matrix.
// 5. The element at the index (i, j) of the 2D matrix is matrix[i][j] in the 1D array.
// 6. The row index i of the 2D matrix is calculated as i = mid / m.
// 7. The column index j of the 2D matrix is calculated as j = mid % m.
//Time complexity: O(log(n*m))
//Space complexity: O(1)