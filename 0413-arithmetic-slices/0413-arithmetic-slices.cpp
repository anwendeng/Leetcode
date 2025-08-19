#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return 0;
        int prev=nums[1]-nums[0], ans=0, len=0;
        for(int i=2; i<n; i++){
            int diff=nums[i]-nums[i-1];
            if (diff==prev){
                len++;
            }
            else{
                len=0;
                prev=diff;
            }
            ans+=len;
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();