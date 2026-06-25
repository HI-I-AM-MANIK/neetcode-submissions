class Solution {
public:
    vector<vector<int>>dir = {{-1,0},{0,-1},{0,1},{1,0}};
    int row,col;
    vector<vector<int>>dp;

    int dfs(vector<vector<int>>&matrix,int i,int j,int prev){
        if(i<0 || j<0 || i>=row || j>=col || matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1;
        for(auto d: dir){
            res=max(res,1+dfs(matrix,i+d[0],j+d[1],matrix[i][j]));
        }
        dp[i][j]=res;
        return res;
    }



    int longestIncreasingPath(vector<vector<int>>& matrix) {

        row=matrix.size(),col=matrix[0].size();
        dp = vector<vector<int>>(row,vector<int>(col,-1));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans=max(ans,dfs(matrix,i,j,INT_MIN));
            }
        }
        return ans;

    }
};
