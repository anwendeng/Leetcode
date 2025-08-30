class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Use bitmask
        Col = [0]*9
        Row = [0]*9
        Block = [0]*9

        for i in range(9):
            for j in range(9):
                c=board[i][j]
                if c=='.': continue
                x=(ord(c)-ord('0'))%9

                if (Row[i]>>x)&1: return False
                Row[i]|=1<<x

                if (Col[j]>>x)&1: return False
                Col[j]|=1<<x

                bidx=i//3*3+j//3
                if (Block[bidx]>>x)&1: return False
                Block[bidx]|=1<<x
        return True