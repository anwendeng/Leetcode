class Solution {
public:
    using u128=__uint128_t;
    static u128 freq(string& s){
        u128 ans=0;
        for(char c: s){
            ans+=(u128(1)<<4*(c-'a'));
        }
        return ans;
    }
    static vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size(), l=0, r=1;
        int sz=1;
        u128 f0=freq(words[0]);
        for( ; r<n; r++){
            string s=words[r];
            auto x=freq(s);
            if (f0!=x){
                words[sz++]=s;
                l=r;
                f0=x;
            }
        }
        words.resize(sz);
        return words;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();