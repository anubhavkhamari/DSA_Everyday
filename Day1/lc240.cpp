class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start at the top-right corner
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true; 
            }
            else if (matrix[row][col] > target) {
                // Current value is too big -> eliminate this column
                col--;
            } 
            else {
                // Current value is too small -> eliminate this row
                row++;
            }
        }
        
        return false; // Out of bounds means the target doesn't exist
    }
};