<h2><a href="https://leetcode.com/problems/valid-sudoku/?envType=daily-question&envId=2025-08-30">36. Valid Sudoku</a></h2><h3>Medium</h3><hr><p>Determine if a&nbsp;<code>9 x 9</code> Sudoku board&nbsp;is valid.&nbsp;Only the filled cells need to be validated&nbsp;<strong>according to the following rules</strong>:</p>

<ol>
	<li>Each row&nbsp;must contain the&nbsp;digits&nbsp;<code>1-9</code> without repetition.</li>
	<li>Each column must contain the digits&nbsp;<code>1-9</code>&nbsp;without repetition.</li>
	<li>Each of the nine&nbsp;<code>3 x 3</code> sub-boxes of the grid must contain the digits&nbsp;<code>1-9</code>&nbsp;without repetition.</li>
</ol>

<p><strong>Note:</strong></p>

<ul>
	<li>A Sudoku board (partially filled) could be valid but is not necessarily solvable.</li>
	<li>Only the filled cells need to be validated according to the mentioned&nbsp;rules.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height:250px; width:250px" />
<pre>
<strong>Input:</strong> board = 
[[&quot;5&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
,[&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
,[&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;]
,[&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;]
,[&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;]
,[&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;]
,[&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;]
,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;]
,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> board = 
[[&quot;8&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
,[&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;]
,[&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;]
,[&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;]
,[&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;]
,[&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;]
,[&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;]
,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;]
,[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Same as Example 1, except with the <strong>5</strong> in the top left corner being modified to <strong>8</strong>. Since there are two 8&#39;s in the top left 3x3 sub-box, it is invalid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> is a digit <code>1-9</code> or <code>&#39;.&#39;</code>.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Done very long ago. Very classical question. This question is the 1st part, the 2nd part is to solve Sudoku [37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/solutions/3622243/beats-99-27-c-c-solves-via-backtracking-bool-arrays-in-3-ms/)

[Please turn on English subtitles if neccessary]
[https://youtu.be/hkXrewUTqyc](https://youtu.be/hkXrewUTqyc)

# Approach
<!-- Describe your approach to solving the problem. -->
From {1, 2,..., 9} there are 2**9=512 different ways to choose each
digit once or none.
There are 27 conditions need to check.
3 kinds of conditions: columns , rows and blocks.
Each board[i][j] lies exactly in one column, one row and one block.
bitset<9>, boolean arrays or sets suffice to use for recording and checking and play the role of hash tables!! 

Leetcode 37. Sudoku Solver is also solved in the similar manner.
[https://leetcode.com/problems/sudoku-solver/solutions/3622243/w-explain-c-c-solves-via-backtracking-bool-arrays-in-3-ms/](https://leetcode.com/problems/sudoku-solver/solutions/3622243/w-explain-c-c-solves-via-backtracking-bool-arrays-in-3-ms/)

Add a bitmask solution 
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(81)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(81)$
# Code C++ 0ms|C 0ms|Py3 2ms
```C++ []
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> Col[9];
        bitset<9> Row[9];
        bitset<9> Block[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if (c == '.') continue;
                int x=(c-'0')%9; 
                // Convert the character digit to an index (0-8) 0 for 9

                if (Row[i][x]) return 0;
                Row[i][x] = 1;

                if (Col[j][x]) return 0;
                Col[j][x] = 1;
                
                int bidx = (i / 3) * 3 + j / 3;
                if (Block[bidx][x]) return 0;
                Block[bidx][x] = 1;
            }
        }
        return 1;
    }
};
```
```C []
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    bool Col[9][9]={0};
    bool Row[9][9]={0};
    bool Block[9][9]={0};

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
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
```
```Python []
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Use sets
        Col = [set() for _ in range(9)]
        Row = [set() for _ in range(9)]
        Block = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                c=board[i][j]
                if c=='.': continue
                x=(ord(c)-ord('0'))%9

                if x in Row[i]: return False
                Row[i].add(x)

                if x in Col[j]: return False
                Col[j].add(x)

                idx=i//3*3+j//3
                if x in Block[idx]: return False
                Block[idx].add(x)
        return True'
```
Another approach uses C++ unordered_set for strings.
# C++ solution uses unordered_set
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> C;
        int n=0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if (c != '.') {
                    n++;
                    string row="row"+to_string(i)+c;
                    string col="col"+to_string(j)+c;
                    int bidx = (i / 3) * 3 + j / 3;
                    string block="block"+to_string(bidx)+c;
                    C.insert(row);
                    C.insert(col);
                    C.insert(block);
                }
            }
        }
        return C.size()==3*n;
    }
};
```
# Bitmask |C++0ms
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        short Col[9]={0};
        short Row[9]={0};
        short Block[9]={0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if (c == '.') continue;
                int x=(c-'0')%9; 
                // Convert the character digit to an index (0-8) 0 for 9

                if ((Row[i]>>x)&1) return 0;
                Row[i]|=1<<x;

                if ((Col[j]>>x)&1) return 0;
                Col[j]|=1<<x;
                
                int bidx = (i / 3) * 3 + j / 3;
                if ((Block[bidx]>>x)&1) return 0;
                Block[bidx]|=1<<x;
            }
        }
        return 1;
    }
};
```
Next step is to use backtracking solving it!
[https://youtu.be/_B8ihi2SVSU](https://youtu.be/_B8ihi2SVSU)
