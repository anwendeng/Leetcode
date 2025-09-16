/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3, unroll-loops")
static inline int gcd(int x, int y){
    int bz=fmin(__builtin_ctz(x), __builtin_ctz(y));
    if (bz>0) return gcd(x>>bz, y>>bz)<<bz;
    int r=x%y;
    return r?gcd(y, r):y;
}
static int* replaceNonCoprimes(int* nums, int n, int* returnSize) {
    int top=-1;
    for(int i=0; i<n; i++){
        int cur=nums[i];
        while(top!=-1){
            int g=gcd(nums[top], cur);
            if (g==1) break;
            cur*=nums[top]/g;// lcm
            top--;
        }
        nums[++top]=cur;
    }
    int* ans=nums;
    *returnSize=top+1;
    return ans;
}