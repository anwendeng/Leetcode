class Solution {
public:
    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        int top=-1;
        for (int x : nums) {
            int cur=x;
            while (top!=-1) {
                int g=gcd(nums[top], cur);
                if (g==1) break;
                cur*=nums[top]/g;
                top--;// pop 
            }
            nums[++top]=cur;
        }
        nums.resize(top+1);
        return nums;
    }
};