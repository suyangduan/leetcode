class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        row = matrix.size();
        if (row == 0)
            return 0;
        column = matrix[0].size();
        
        result.resize(row,vector<int>(column));
        
        int longest = 0;
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                longest = max(longest, dfs(matrix, i, j));
            }
        
        return longest;
        
        
        
    }

private:
    int row;
    int column;
    vector<vector<int>> result;
    int dfs(vector<vector<int>> & matrix, int x, int y)
    {
        if (result[x][y])
            return result[x][y];
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto dir : dirs)
        {
            int xx = x + dir[0];
            int yy = y + dir[1];
            
            if (xx < 0 || yy < 0 || xx >= row || yy >= column)
                continue;
            if (matrix[xx][yy] <= matrix[x][y])
                continue;
            result[x][y] = max(result[x][y], dfs(matrix, xx, yy));
        }
        return ++result[x][y];
    }
};