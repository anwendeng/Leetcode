// this version merges the collection of fruits for child 2, 3 in 1 loop
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n=fruits.size();
        int diag=0;
        for (int i=0; i<n; i++) diag+=fruits[i][i];

        // fill fruits[i][j] with 0 for i+j=n-2, i+j=n-3 
        for(int i=0; i<n-2; i++){
            fruits[i][n-2-i]=fruits[i][n-3-i]=0;
        }
        fruits[n-2][0]=0;

        // Proceed collecting fruits on the triangle east & triangle south simultaneously
        for (int i=1; i<n-1; i++) {
            int j0=max(i+1, n-i-1);
            for (int j=j0; j<n-1; j++) {
                fruits[i][j]+=max(fruits[i-1][j-1],
                    max(fruits[i-1][j], fruits[i-1][j+1]));
                fruits[j][i]+=max(fruits[j-1][i-1],
                    max(fruits[j][i-1], fruits[j+1][i-1]));
            }
            fruits[i][n-1]+=max(fruits[i-1][n-2], fruits[i-1][n-1]);
            fruits[n-1][i]+=max(fruits[n-2][i-1], fruits[n-1][i-1]);
        }
        return diag+fruits[n-2][n-1]+fruits[n-1][n-2];
    }
};
