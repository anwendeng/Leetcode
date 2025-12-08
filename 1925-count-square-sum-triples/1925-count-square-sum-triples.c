#pragma GCC optimize("O3, unroll-loops")
static int GCD[23][23]={{0}};
static void GCD_ini(){
    if (GCD[1][1]) return; // compute once
    const int N=23;
    for(int i=1; i<N; i++){
        GCD[i][0]=GCD[0][i]=GCD[i][i]=i;
        for(int j=i+1; j<N; j++){
            int r=j-i;
            GCD[i][j]=GCD[j][i]=GCD[i][r];
        }
    }
}
static int countTriples(int n) {
    GCD_ini();
    int cnt=0;
    int nsqrt=sqrt(n);
    for (int s=2; s<=nsqrt; s++) {
        for (int t=1+(s&1); t<s; t+=2) {
            if (GCD[s][t]!=1) continue;

            int c=s*s+t*t;

            if (c>n) break;

            // k multiples: ka, kb, kc
            int kmax=n/c;
            // count (a,b,c) and (b,a,c)
             cnt+=2*kmax;
        }
    }
    return cnt;
}