#pragma GCC optimize("O3, unroll-loops")
int countSquares(int** matrix, int r, int* c) {
    int cnt=0;
    for(int i=0; i<*c; i++)
        cnt+=matrix[0][i];
    for(int i=1; i<r; i++) 
        cnt+=matrix[i][0];
        
    for(int i=1; i<r; i++)
        for(int j=1; j<*c; j++){
            if (matrix[i][j]==0) continue;
            matrix[i][j]=1+fmin(matrix[i-1][j], fmin(matrix[i-1][j-1], matrix[i][j-1]));
            cnt+=matrix[i][j];
        }
    return cnt;
    
}