class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        const int n=prices.size(), k2=k/2;
        vector<long long> sum(n+1, 0);
        for(int i=0; i<n; i++){
            sum[i+1]=sum[i]+1LL*strategy[i]*prices[i];
        }

        long long modify=accumulate(prices.begin()+k/2, prices.begin()+k, 0LL);
        long long profit=max(sum.back(), modify+sum.back()-sum[k]);

        for(int i=1; i+k<=n; i++){ 
            modify+=prices[i+k-1]-prices[i+k2-1];
            profit=max(profit, modify+sum.back()-sum[i+k]+sum[i]);
        }
        return profit;
    }
};

