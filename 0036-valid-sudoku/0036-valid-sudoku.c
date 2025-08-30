bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    bool Col[9][9]={0};
    bool Row[9][9]={0};
    bool Block[9][9]={0};

    for(register int i=0; i<9; i++){
        for(register int j=0; j<9; j++){
            char c = board[i][j];
            if (c == '.') continue;
            int x=(c-'0')%9; 
            // Convert the character digit to an index (0-8) 0 for 9

            if (Row[i][x]==1) return 0;
            Row[i][x] = 1;

            if (Col[j][x]==1) return 0;
            Col[j][x] = 1;
                
            int bidx = (i / 3) * 3 + j / 3;
            if (Block[bidx][x]==1) return 0;
            Block[bidx][x] = 1;
        }
    }
    return 1;
}