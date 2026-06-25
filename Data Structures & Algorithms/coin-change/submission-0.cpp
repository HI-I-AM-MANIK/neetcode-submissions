class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,1e9));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                int p=1e9;
                int np = dp[i-1][j];
                if(coins[i-1]<=j){
                    p = dp[i][j-coins[i-1]]+1;
                }
                dp[i][j]=min(p,np);

            }
        }        
        return dp[n][k] == 1e9 ? -1:dp[n][k];
    }
};
