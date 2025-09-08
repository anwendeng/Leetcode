/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3, unroll-loops")
int* getNoZeroIntegers(int n, int* returnSize) {
    *returnSize=2;
    int* ans=(int*)malloc(sizeof(int)*2);
    memset(ans, 0, sizeof(ans));
    for (int tens=1; n>0; n/=10, tens*=10){
        int d=n%10;
        if (d==0){
            ans[0]+=5*tens;
            ans[1]+=5*tens;
            n-=10; 
        }
        else if (d==1 && n>=10){
            ans[0]+=6*tens;
            ans[1]+=5*tens;
            n-=10;
        }
        else{
            ans[0]+=(d-d/2)*tens;
            ans[1]+=(d/2)*tens;
        }
    }
    return ans;
}