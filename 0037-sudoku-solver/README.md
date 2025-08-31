<h2><a href="https://leetcode.com/problems/sudoku-solver">37. Sudoku Solver</a></h2><h3>Hard</h3><hr><p>Write a program to solve a Sudoku puzzle by filling the empty cells.</p>

<p>A sudoku solution must satisfy <strong>all of the following rules</strong>:</p>

<ol>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each row.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each column.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each of the 9 <code>3x3</code> sub-boxes of the grid.</li>
</ol>

<p>The <code>&#39;.&#39;</code> character indicates empty cells.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height:250px; width:250px" />
<pre>
<strong>Input:</strong> board = [[&quot;5&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;],[&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;],[&quot;.&quot;,&quot;9&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;],[&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;3&quot;],[&quot;4&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;3&quot;,&quot;.&quot;,&quot;.&quot;,&quot;1&quot;],[&quot;7&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;6&quot;],[&quot;.&quot;,&quot;6&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;2&quot;,&quot;8&quot;,&quot;.&quot;],[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;.&quot;,&quot;.&quot;,&quot;5&quot;],[&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;.&quot;,&quot;8&quot;,&quot;.&quot;,&quot;.&quot;,&quot;7&quot;,&quot;9&quot;]]
<strong>Output:</strong> [[&quot;5&quot;,&quot;3&quot;,&quot;4&quot;,&quot;6&quot;,&quot;7&quot;,&quot;8&quot;,&quot;9&quot;,&quot;1&quot;,&quot;2&quot;],[&quot;6&quot;,&quot;7&quot;,&quot;2&quot;,&quot;1&quot;,&quot;9&quot;,&quot;5&quot;,&quot;3&quot;,&quot;4&quot;,&quot;8&quot;],[&quot;1&quot;,&quot;9&quot;,&quot;8&quot;,&quot;3&quot;,&quot;4&quot;,&quot;2&quot;,&quot;5&quot;,&quot;6&quot;,&quot;7&quot;],[&quot;8&quot;,&quot;5&quot;,&quot;9&quot;,&quot;7&quot;,&quot;6&quot;,&quot;1&quot;,&quot;4&quot;,&quot;2&quot;,&quot;3&quot;],[&quot;4&quot;,&quot;2&quot;,&quot;6&quot;,&quot;8&quot;,&quot;5&quot;,&quot;3&quot;,&quot;7&quot;,&quot;9&quot;,&quot;1&quot;],[&quot;7&quot;,&quot;1&quot;,&quot;3&quot;,&quot;9&quot;,&quot;2&quot;,&quot;4&quot;,&quot;8&quot;,&quot;5&quot;,&quot;6&quot;],[&quot;9&quot;,&quot;6&quot;,&quot;1&quot;,&quot;5&quot;,&quot;3&quot;,&quot;7&quot;,&quot;2&quot;,&quot;8&quot;,&quot;4&quot;],[&quot;2&quot;,&quot;8&quot;,&quot;7&quot;,&quot;4&quot;,&quot;1&quot;,&quot;9&quot;,&quot;6&quot;,&quot;3&quot;,&quot;5&quot;],[&quot;3&quot;,&quot;4&quot;,&quot;5&quot;,&quot;2&quot;,&quot;8&quot;,&quot;6&quot;,&quot;1&quot;,&quot;7&quot;,&quot;9&quot;]]
<strong>Explanation:</strong>&nbsp;The input board is shown above and the only valid solution is shown below:

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png" style="height:250px; width:250px" />
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> is a digit or <code>&#39;.&#39;</code>.</li>
	<li>It is <strong>guaranteed</strong> that the input board has only one solution.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
This solution is different from the old ones 2 years ago.
During this time period, LC added more testcases to make old solutions slow; so make a new one by using bitmask & not using the solution for [LC 36](https://leetcode.com/problems/valid-sudoku/solutions/7136621/bitset-vs-bool-array-vs-hashsetbeats-100-nai4/)
[Please turn on the English subtitles if necessary]
[https://youtu.be/tgTMYqXuXlE?si=_RNJFUntJue7NJhI](https://youtu.be/tgTMYqXuXlE?si=_RNJFUntJue7NJhI)
# Approach
<!-- Describe your approach to solving the problem. -->
1. No need to construct a function like `isValid` to check 27 conditions; insteadly use bitmask `unsigned Row[9]={0};
    unsigned Col[9]={0};
    unsigned Block[9]={0};` Using `isValid` it needs to test numbers 1-9 & to backtack, but using bitmask can reduce the times of testings.
2. Define the function `set3Cond(int i, int j,  int x)` to update the bitmasks as follows
```cpp
void set3Cond(int i, int j,  int x){
    const int x2=1<<x;
	Row[i]|=x2;
    Col[j]|=x2;
    const int bidx=(i/3)*3 +j/3;
    Block[bidx]|=x2;
}
```
3. define the function `setup(vector<vector<char>>& board)` to setup for `(i, j)`: if `board[i][j]=='.'` add the pair `(i, j)` to `uncertain`; otherwise `set3Cond(i, j, c-'1')`
4. Use recursive DFS way to define the backtracking function `bool solve(vector<vector<char>>& board, int idx)`
    - `idx` is the index for `uncertain`
    - base case: `idx==uncertain.size()`  return true
    - let `[i, j]=uncertain[idx]`, `bidx=(i/3)*3 +j/3`; let the bitmask `notMask=~(Row[i]|Col[j]|Block[bidx]) & 0b111111111` which denotes the bitmask for possible candidate for filling numbers
    - let `Bit` denote the most significant bit of  `notMask`
    -  the key loop is as follows (but if the loop is through return false)
```cpp
for (; notMask; notMask^=Bit) {// ^Bit removes the msb bit
    Bit=bit_floor(notMask);// msb of notMask
    const int x=countr_zero(Bit);// x=0...8

    board[i][j]='1'+x; // filling number
    Row[i]|=Bit; Col[j]|=Bit; Block[bidx]|=Bit;
    if (solve(board, idx+1)) return 1;
    Row[i]^=Bit; Col[j]^=Bit; Block[bidx]^=Bit;// backtracking
    board[i][j]='.';
}
```
5. in `solveSudoku(vector<vector<char>>& board)` proceed
```
setup(board);
solve(board, 0);
```

# Old solutions
Old solutions [ref](https://leetcode.com/problems/sudoku-solver/solutions/3622243/beats-99-27-c-c-solves-via-backtracking-bool-arrays-in-3-ms/)
[https://youtu.be/_B8ihi2SVSU](https://youtu.be/_B8ihi2SVSU)
[Please turn on the English subtitle]
[https://youtu.be/wviWrbbOdYE?si=hGEiKIs8j4nvrHdq](https://youtu.be/wviWrbbOdYE?si=hGEiKIs8j4nvrHdq)
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(9^{81})$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(27+|uncertain|)$
# Code|9ms Beats 98.17%
```cpp []
class Solution {
	unsigned Row[9]={0};
    unsigned Col[9]={0};
    unsigned Block[9]={0};
    vector<pair<char, char>> uncertain;
public:
     void print(vector<vector<char>>& board){
        for(vector<char>& row: board){
            for(char& c: row)
                cout<<c;
            cout<<endl;
        }
        cout<<"===========\n";
    }
    void set3Cond(int i, int j,  int x){
        const int x2=1<<x;
		Row[i]|=x2;
        Col[j]|=x2;
        const int bidx=(i/3)*3 +j/3;
        Block[bidx]|=x2;
	}

    void setup(vector<vector<char>>& board) {
        uncertain.reserve(81);
        for (int i=0; i<9; i++) {
            for (int j=0; j< 9; j++) {
                char c=board[i][j];
                if ( c== '.') {
                    uncertain.emplace_back(i, j);
                }
                else {
                    set3Cond(i, j, c-'1');
                }
            }
        }
    }

    bool solve(vector<vector<char>>& board, int idx) {
        if (idx==uncertain.size()) return 1; 
        auto [i, j]=uncertain[idx];
        const int  bidx=(i/3)*3 +j/3;
        unsigned notMask=~(Row[i]|Col[j]|Block[bidx]) & 0b111111111;
        unsigned Bit=0;
        for (; notMask; notMask^=Bit) {
            Bit=bit_floor(notMask);
            const int x=countr_zero(Bit);

            board[i][j]='1'+x;
            Row[i]|=Bit; Col[j]|=Bit; Block[bidx]|=Bit;
            if (solve(board, idx+1)) return 1;
            Row[i]^=Bit; Col[j]^=Bit; Block[bidx]^=Bit;// backtracking
            board[i][j]='.';
        }
        return 0; 
    }

    void solveSudoku(vector<vector<char>>& board) {
    //    print(board);
        setup(board);
        solve(board, 0);
    //    print(board);
    }
};
```
# Old solutions use valid checking |C++ 379ms|C 198ms
```C []
bool Col[9][9];
bool Row[9][9];
bool Block[9][9];

void set3Cond(int i, int j, int x, bool val) {
    Row[i][x] = val;
    Col[j][x] = val;
    int bidx = (i / 3) * 3 + j / 3;
    Block[bidx][x] = val;
}

void setup(char** board) {
    memset(Col, 0, sizeof(Col));
    memset(Row, 0, sizeof(Row));
    memset(Block, 0, sizeof(Block));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int x = (c - '0') % 9;
            set3Cond(i, j, x, 1);
        }
    }
}

bool isValid(char** board, int i, int j, char c) {
    int x = (c - '0') % 9;
    return !Row[i][x] && !Col[j][x] && !Block[(i / 3) * 3 + j / 3][x];
}

bool solve(char** board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        int x = (c - '0') % 9;
                        set3Cond(i, j, x, 1);

                        if (solve(board))
                            return true;

                        // Backtracking
                        board[i][j] = '.';
                        set3Cond(i, j, x, 0);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    setup(board);
    solve(board);
}
```
```C++ []
class Solution {
    bool Col[9][9]={0};
    bool Row[9][9]={0};
    bool Block[9][9]={0};

public:
	void set3Cond(int i, int j,  int x, bool val=1){
		Row[i][x] = val;
        Col[j][x] = val;
        int bidx = (i/3)*3 +j/3;
        Block[bidx][x] = val;
	}
	
	void setup(vector<vector<char>>& board){
		for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
            
                char c = board[i][j];
                if (c == '.') continue;
        		
				int x=(c-'0')%9; 
                set3Cond(i, j, x);
        	}	
    	}	
	}
	
	void print(vector<vector<char>>& board){
		for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) 
            	cout<<board[i][j];
            cout<<endl;
    	}
		cout<<"============\n";	
	} 
	
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            int x=(c-'0')%9; 
                			set3Cond(i, j, x);

                            if (solve(board)) 
                                return 1;

                            // Backtracking
                            board[i][j] = '.';
                			set3Cond(i, j, x, 0);
                        }
                    }
                    return 0;
                }
            }
        }  
        return 1; 
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
    	int x=(c-'0')%9;
        return !Row[i][x] && !Col[j][x] && !Block[(i/3)*3+j/3][x];
    }

    void solveSudoku(vector<vector<char>>& board) {
    //	print(board);
    	setup(board);
        solve(board);
    //  print(board);
    }
};
```
