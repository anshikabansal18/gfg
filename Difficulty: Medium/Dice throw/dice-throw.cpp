class Solution {
  public:
    int solve(int m , int n , int sum, int i ,vector<vector<int>>&dp ){
        if(sum==0&&i==n+1){return 1;}
        if(i>=n+1||sum<0){return 0;}
        if(dp[i][sum]!=-1)return dp[i][sum];
        int count=0;
        //taking all the possiblilites for the current dice as the sum
        for(int tempsum=1;tempsum<=m;tempsum++){
            count += solve(m,n,sum-tempsum,i+1,dp);
        }
         dp[i][sum] = count;
        return count;
    }
    int noOfWays(int m, int n, int x) {
        // i --->1 - n+2
        //sum --->x - 0
        vector<vector<int>>dp(n+2,vector<int>(x+1,-1));
        int i=1;
        int count=solve(m, n, x, i,dp);
        return count;       
    }
};