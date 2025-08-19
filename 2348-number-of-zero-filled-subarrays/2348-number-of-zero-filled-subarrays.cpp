class Solution { 
public: 
    long long zeroFilledSubarray(vector<int>& nums) { 
        return accumulate(nums.begin(), nums.end() , 0LL, 
[&, len=0](long long sum, int x) mutable {
            return sum+=(len=(x!=0)?0:len+1);});}};