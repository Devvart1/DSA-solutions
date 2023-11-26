 int numTilings(int n) {
        vector<int> dp(n+1,0);
dp[0]=0;
dp[1]=1;
dp[2]=2;
dp[3]=5;

for(int i=4;i<=n;++i)
{
    dp[i]= 2*dp[i-1] + dp[i-3];
}
        return dp[n];
    }