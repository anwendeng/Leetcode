class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        const int n=order.size();
        bitset<101> hasF=0;
        for(int f: friends) hasF[f]=1;
        vector<int> ans;
        for(int i: order){
            if (hasF[i]) ans.push_back(i);
        }
        return ans;
    }
};