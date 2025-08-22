class Solution {
public:
    static int minimumArea(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        int iMin=1000, iMax=-1, jMin=1000, jMax=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) continue;
                iMin=min(iMin, i);
                iMax=max(iMax, i);
                jMin=min(jMin, j);
                jMax=max(jMax, j);
            }
        }
        return (iMax-iMin+1)*(jMax-jMin+1);
    }
};




auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();