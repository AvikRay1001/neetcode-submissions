class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        if(nrow<0 || nrow>=n || ncol<0 || ncol>=m){
            return false;
        }
        return true;
    }
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int x[4]={-1,1,0,0};
        int y[4]={0,0,1,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nrow=row+x[k];
                int ncol=col+y[k];

                if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==INT_MAX){
                    grid[nrow][ncol]=grid[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
};
