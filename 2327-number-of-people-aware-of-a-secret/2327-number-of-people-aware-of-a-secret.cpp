class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        constexpr int mod=1e9+7;
        vector<long long> dp(n, 0);
        dp[0]=1;
        long long sum=0, cnt=0;
        for(int r=delay; r<n; r++){
            sum+=dp[r-delay]-(r>=forget?dp[r-forget]:0);
            dp[r]=(sum+mod)%mod;
            cnt+=(r>=n-forget)?sum:0;
        }
        cnt+=(forget==n);
        return cnt%mod;
    }
};