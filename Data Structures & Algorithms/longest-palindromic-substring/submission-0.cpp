class Solution {
public:
/*
        dp



*/
    string longestPalindrome(string s) {
        int idx=0,res=0;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] and (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=1;

                    if(res<(j-i+1)){
                        idx=i;
                        res=j-i+1;
                    }
                }
            }
        }
        return s.substr(idx,res);
        
    }
};
