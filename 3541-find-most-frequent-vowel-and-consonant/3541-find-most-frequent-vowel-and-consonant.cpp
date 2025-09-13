class Solution {
public:
    int maxFreqSum(string& s) {
        int freq[26]={0};
        for(char c: s)
            freq[c-'a']++;
        constexpr unsigned mask=1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
    //    cout<<hex<<mask<<endl;
        int maxCV[2]={0};// [0] for consonant [1] for vowel
        for(int i=0; i<26; i++){
            const bool idx=((1<<i) & mask)!=0;
            maxCV[idx]=max(maxCV[idx], freq[i]);
        }
        return maxCV[0]+maxCV[1];
    }
};