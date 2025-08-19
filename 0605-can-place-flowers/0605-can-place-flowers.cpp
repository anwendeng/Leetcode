class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n==0) return 1;
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        int s=flowerbed.size();
        int a_len=1, sum=0;
        for(int i=0; i<s; i++)
        {
            if (flowerbed[i]==0){
                a_len++;
            } 
            else{
                sum+=(a_len-1)/2;
                if (sum>=n) return 1;
                a_len=0;
            }
        }
        return sum>=n;
    }
};