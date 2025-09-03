#pragma GCC optimize("O3",  "unroll-loops")
static inline int cmp(const void *a, const void *b) {
    const int *p = *(const int **)a;
    const int *q = *(const int **)b;
    return (p[0]==q[0])?(p[1]-q[1]):(q[0] - p[0]);
}
static int numberOfPairs(int** P, int n, int* pointsColSize) {
    *pointsColSize=2;
    qsort(P, n, sizeof(int*), cmp);
    int ans = 0;
    for(int i=0; i<n-1; i++){
        int y=INT_MAX, yi=P[i][1];
        for(int j = i+1; j<n; j++){
            const int yj=P[j][1];
            if (yj>=yi && y>yj){//P[j] cannot be in between
                ans++;
                y=yj;
                if (yi==yj) break;
            }
        }
    }
    return ans;  
}