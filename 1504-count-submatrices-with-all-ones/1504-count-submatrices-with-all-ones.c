#pragma GCC optimize("O3, unroll-loops")
int st[150], top=-1;//mono stack
int cnt[150]={0};
int numSubmat(int** mat, int r, int* matColSize) {
    int c=*matColSize;
    int ans=0;
    for (int i=0; i<r; i++){
        int* h=mat[i];//height
        top=-1;// reset mono stack
        memset(cnt, 0, c*sizeof(int));
        for(int j=0; j<c; j++){
            if (h[j]==0){
                top=-1; // not 1 by 1, pop out at once O(1) time
                st[++top]=j;
                continue;                
            }
            if (i>0)
                h[j]+=mat[i-1][j];// height for mat[i][j]
                
            while(top>-1 && h[st[top]]>= h[j]) 
                top--;// pop
            int left=(top==-1)?-1:st[top];
            cnt[j]=(top>-1?cnt[left]:0)+h[j]*(j-left);
            ans+=cnt[j];
            st[++top]=j;// push j to stack
        }
    }
    return ans;
}