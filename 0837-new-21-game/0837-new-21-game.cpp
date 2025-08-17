double dp[10001]={1};
class Solution {
public:
    static double new21Game(int n, int k, int maxPts) {
        if (k==0 || n>=k+maxPts-1) return 1;// edge case
        fill(dp+1, dp+(n+1), 0);
        double wsum=1, prob=0;
        // sliding window with window size maxPts
        for (int l=0, r=1; r<=n; r++) {
            dp[r]=wsum/maxPts;
            (r<k ?wsum:prob)+=dp[r];
            if (r>=maxPts) 
                wsum-=dp[l++];//move l
        }
        return prob;
    }
};
