#pragma GCC optimize("O3,unroll-loops")
static unsigned long long know[501][8];

static inline void setBit(unsigned long long B[8], int i) {
    const int q=i>>6, r=i&63;
    B[q]|=(1ULL<<r);  
}

static inline bool isSet(unsigned long long B[8], int i) {
    const int q=i>>6, r=i&63;
    return (B[q]>>r)&1ULL;
}

static inline bool intersection(unsigned long long X[8], unsigned long long Y[8]) {
    for (int i=0; i<8; i++) {
        if (X[i] & Y[i]) return 1;
    }
    return 0;
}

static int minimumTeachings(int n, int** languages, int m, int* languagesColSize, int** friendships, int f, int* friendshipsColSize) {
    memset(know, 0, sizeof(unsigned long long)*(m+1)*8);   

    //known languages for each person
    for (int i=0; i <m; i++) {
        for (int j=0; j<languagesColSize[i]; j++) {
            setBit(know[i], languages[i][j]);
        }
    }

    // people need be taught
    unsigned long long need[8]={0};
    for (int i=0; i<f; i++) {
        int a=friendships[i][0]-1, b=friendships[i][1]-1;
        if (intersection(know[a], know[b])) continue;
        setBit(need, a);
        setBit(need, b);
    }

    int cnt=0;
    for (int i=0; i<8; i++) cnt += __builtin_popcountll(need[i]);
    if (cnt==0) return 0;// if no need

    int ans=INT_MAX;
    for (int lang=1; lang<= n; lang++) {
        cnt=0;
        for (int i=0; i< m; i++) {
            if (isSet(need, i) && !isSet(know[i], lang)) cnt++;
        }
        ans=fmin(ans, cnt);
    }

    return ans;
}
