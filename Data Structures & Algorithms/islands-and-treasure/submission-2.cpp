class Solution {
   public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return false;
        }
        return true;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (isValid(nrow, ncol, n, m) && grid[nrow][ncol] == INT_MAX) {
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};
