class Solution {
private:
    // Helper function to find the row index of the maximum element in a specific column
    int findMaxRowInColumn(vector<vector<int>>& mat, int col, int m) {
        int maxVal = -1;
        int maxRow = -1;
        for (int row = 0; row < m; row++) {
            if (mat[row][col] > maxVal) {
                maxVal = mat[row][col];
                maxRow = row;
            }
        }
        return maxRow;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Find the absolute maximum element in the middle column
            int maxRow = findMaxRowInColumn(mat, mid, m);
            
            // Fetch values of left and right neighbors, defaulting to -1 if out-of-bounds
            int leftNeighbor = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightNeighbor = (mid + 1 < n) ? mat[maxRow][mid + 1] : -1;
            
            // Check if the column maximum is greater than its horizontal neighbors
            if (mat[maxRow][mid] > leftNeighbor && mat[maxRow][mid] > rightNeighbor) {
                return {maxRow, mid}; // Found a 2D peak!
            }
            // If the left neighbor is bigger, shift search space to the left half
            else if (leftNeighbor > mat[maxRow][mid]) {
                high = mid - 1;
            }
            // Otherwise, shift search space to the right half
            else {
                low = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};