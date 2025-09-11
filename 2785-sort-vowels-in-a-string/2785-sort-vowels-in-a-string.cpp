class Solution {
public:
    static string sortVowels(string& s) {
        constexpr unsigned vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));
    //    cout<<hex<<vowMask<<endl;
        const int n=s.size();
        int freq[53]={0}; //'u'-'A'+1=53
        vector<int> pos;
        for(int i=0; i<n; i++){
            char c=s[i];
            if((vowMask>>(c&31))&1){
                freq[c-'A']++;
                pos.push_back(i);
            }
        }
    //    print(pos);
        int count=0, v=freq[0], j=0;

        for (int i: pos){
            while(count>=v)
                v+=freq[++j];
            s[i]='A'+j;
            count++;
        }
        return s;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();