/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3, unroll-loops")
int* findDiagonalOrder(int** mat, int r, int* matColSize, int* returnSize) {
    int c=*matColSize;
    *returnSize=r*c;
    int* ans=(int*)malloc(r*c*sizeof(int));
    bool flip=0;
    for (int d=0, idx=0; d < r+c-1; d++, flip=!flip) {
        if (!flip) {// go NE
            for (int i=fmin(d, r-1), j=d-i; i>=0 && j<c; i--, j++) 
                ans[idx++]=mat[i][j];
        } 
        else {// go SW
            for (int j=fmin(d, c-1), i=d-j; j>=0 && i<r; i++, j--) {
                ans[idx++]=mat[i][j];
            }
        }
    }
    return ans;
}