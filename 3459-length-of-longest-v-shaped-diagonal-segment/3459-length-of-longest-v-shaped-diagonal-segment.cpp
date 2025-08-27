constexpr int d[5] = {1, 1, -1, -1, 1}; // (1,1),(1,-1),(-1,-1),(-1,1)

class Solution {
public:
    static bool isOutSide(int i, int j, int n, int m) { 
        return i<0 || i>=n || j<0 || j>=m; 
    }

    static int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        vector<vector<array<short,4>>> dp(n, vector<array<short,4>>(m));

        // step (1,1)
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--)
                if ((grid[i+1][j+1]^2)==grid[i][j])
                    dp[i][j][0]=1+dp[i+1][j+1][0];
        // step (1,-1)
            for(int j=1; j<m; j++)
                if ((grid[i+1][j-1]^2)==grid[i][j])
                    dp[i][j][1]=1+dp[i+1][j-1][1];
        }
        // step (-1,-1)
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++)
                if ((grid[i-1][j-1]^2)==grid[i][j])
                    dp[i][j][2]=1+dp[i-1][j-1][2];
        // step (-1,1)
            for(int j=m-2; j>=0; j--)
                if ((grid[i-1][j+1]^2)==grid[i][j])
                    dp[i][j][3]=1+dp[i-1][j+1][3];
        }

        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) {
                    ans = max(ans, 1);
                    for (int dir=0; dir<4; dir++) {
                        int s=i+d[dir], t=j+d[dir+1];
                        if (isOutSide(s, t, n, m) || grid[s][t]!=2) continue;
                        const int newDir=(dir+1)&3;// same as %4
                        
                        for(int cnt=1; 
                        !isOutSide(s, t, n, m)&&grid[s][t]==2*(cnt&1);
                        cnt++, s+=d[dir], t+=d[dir+1]) {
                            ans=max(ans, cnt+dp[s][t][newDir]+1);  
                        }
                    }
                }
            }
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
