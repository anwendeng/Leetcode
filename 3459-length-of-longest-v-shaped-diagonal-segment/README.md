<h2><a href="https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment">3459. Length of Longest V-Shaped Diagonal Segment</a></h2><h3>Hard</h3><hr><p>You are given a 2D integer matrix <code>grid</code> of size <code>n x m</code>, where each element is either <code>0</code>, <code>1</code>, or <code>2</code>.</p>

<p>A <strong>V-shaped diagonal segment</strong> is defined as:</p>

<ul>
	<li>The segment starts with <code>1</code>.</li>
	<li>The subsequent elements follow this infinite sequence: <code>2, 0, 2, 0, ...</code>.</li>
	<li>The segment:
	<ul>
		<li>Starts <strong>along</strong> a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).</li>
		<li>Continues the<strong> sequence</strong> in the same diagonal direction.</li>
		<li>Makes<strong> at most one clockwise 90-degree</strong><strong> turn</strong> to another diagonal direction while <strong>maintaining</strong> the sequence.</li>
	</ul>
	</li>
</ul>

<p><img alt="" src="https://assets.leetcode.com/uploads/2025/01/11/length_of_longest3.jpg" style="width: 481px; height: 202px;" /></p>

<p>Return the <strong>length</strong> of the <strong>longest</strong> <strong>V-shaped diagonal segment</strong>. If no valid segment <em>exists</em>, return 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/matrix_1-2.jpg" style="width: 201px; height: 192px;" /></p>

<p>The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: <code>(0,2) &rarr; (1,3) &rarr; (2,4)</code>, takes a <strong>90-degree clockwise turn</strong> at <code>(2,4)</code>, and continues as <code>(3,3) &rarr; (4,2)</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/matrix_2.jpg" style="width: 201px; height: 201px;" /></strong></p>

<p>The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: <code>(2,3) &rarr; (3,2)</code>, takes a <strong>90-degree clockwise turn</strong> at <code>(3,2)</code>, and continues as <code>(2,1) &rarr; (1,0)</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/matrix_3.jpg" style="width: 201px; height: 201px;" /></strong></p>

<p>The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: <code>(0,0) &rarr; (1,1) &rarr; (2,2) &rarr; (3,3) &rarr; (4,4)</code>.</p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: <code>(0,0)</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>m == grid[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 500</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code>, <code>1</code> or <code>2</code>.</li>
</ul>

<hr/>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Provide 2 approaches, 1 is top-down design, other is bottom-up design.
[Explaining the iterative approach, please turn on English subtitles if necessary]
[https://youtu.be/4KJe9sGVcng?si=jkyNT9bxyEXDzho3](https://youtu.be/4KJe9sGVcng?si=jkyNT9bxyEXDzho3)
The V-shaped path can define the V-shaped distance ( not considering  the condition on 1,2,0,2,0...)as 
$ \max(|a-i|,|b-j|)$ where $(a, b) & (i, j)$ are 2 cells with $a+b\equiv i+j \pmod{2}$.
![V_D2.png](https://assets.leetcode.com/users/images/ffefbeb3-c2ff-4225-92a4-50937a37381b_1756255683.6918142.png)
# Approach
<!-- Describe your approach to solving the problem. -->
1. Declare global variable `int d[5] = {1, 1, -1, -1, 1}` which can be used to standard for directions `(1,1),(1,-1),(-1, -1),(-1, 1)` by the cyclic moves.
2. For the recursive DP, declare `dp[500][500][4][2]` where `dp[i][j][dir][turn]` denotes the max length of V-path for position `(i, j)` in direction `dir` & `turn=0` denotes this path has no turn, `turn=1` has turned 90 degree somewhere.
3. define `bool isOutSide(int i, int j)` to check whether `(i, j)` is outside of the grid
4. define the recursive function `int dfs(int i, int j, int dir, bool turn, int nxt, vector<vector<int>>& grid)` to compute the value `dp[i][j][dir][turn]` as follows
```cpp
int dfs(int i, int j, int dir, bool turn, int nxt, vector<vector<int>>& grid) {// nxt should be 0 or 2
    if (dp[i][j][dir][turn]!=-1) 
        return dp[i][j][dir][turn];// avoid of redundant computation
        
    int ans=1, x=grid[i][j];//count length not V-shaped dist

    // Move in the current direction
    int s=i+d[dir], t=j+d[dir+1];
    if (!isOutSide(s, t)) { 
        int y=grid[s][t];
        if (nxt==y)  // continue moving in the same diagonal
            // note 2^0=2, 2^2=0
            ans=max(ans, 1+dfs(s, t, dir, turn, nxt^2, grid));
    }

    // Try turning to the next diagonal direction
    if (!turn) { 
        const int newDir=(dir+1)&3;// same %4
        int u=i+d[newDir], v=j+d[newDir+1];
        if (!isOutSide(u, v)) {
            const int z=grid[u][v];
            if (nxt==z)  // to turn to the next diagonal
                ans=max(ans, 1+dfs(u, v, newDir, 1, nxt^2, grid));
        }
    }
    return dp[i][j][dir][turn]=ans;
}
```
5. in `lenOfVDiagonal` let `n=grid.size(), m=grid[0].size()`
6. fill `dp` with -1
7. Use a loop to finish the job to give `ans`
```cpp
int ans=0;
for (int i=0; i<n; i++) {// trasverse the grid to find value 1
    for (int j=0; j<m; j++) {
        if (grid[i][j]==1) { // Start from cells that are part of the path
            for (int d=0; d<4; d++) // 4 directions
                // call dfs & update ans 
                ans=max(ans, dfs(i, j, d, 0, 2,  grid));
        }
    }
}
```
8. 2nd approach is the iterative one where 3D state matrix `dp[i][j][dir]` denote the max V-shaped dist to `(i, j)` with direction `dir`
9. Proceed 4 passes to compute  `dp[n][m][4]`
10. for each `(i,j)` with `grid[i][j]==1` to proceed the following procedure:
```cpp 
ans=max(ans, 1);// ans>=1
for (int dir=0; dir<4; dir++) {// 4 directions
    int s=i+d[dir], t=j+d[dir+1];// next possible move
    if (isOutSide(s, t, n, m) || grid[s][t]!=2) 
        continue;//impossible to move
    const int newDir=(dir+1)&3;// compute newDir, &3 is same as %4
                        
    for(int cnt=1; 
        !isOutSide(s, t, n, m) && grid[s][t]==2*(cnt&1);// 2,0,2,0...
        cnt++, s+=d[dir], t+=d[dir+1]) {// (s,t) is the turning cell
        ans=max(ans, cnt+dp[s][t][newDir]+1); // V-shaped path size 
    }
}
```
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(nm)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(nm)$
# Code|DFS |C++ 109ms Beats 95.72%
```cpp []
constexpr int d[5] = {1, 1, -1, -1, 1};//(1,1),(1,-1),(-1, -1),(-1, 1)
int dp[500][500][4][2];
class Solution {
public:
    int n, m;
    bool isOutSide(int i, int j) { 
        return i<0 || i>=n || j<0 || j>=m; 
    }
    int dfs(int i, int j, int dir, bool turn, int nxt, vector<vector<int>>& grid) {
        if (dp[i][j][dir][turn]!=-1) return dp[i][j][dir][turn];
        
        int ans=1, x=grid[i][j];

        // Move in the current direction
        int s=i+d[dir], t=j+d[dir+1];
        if (!isOutSide(s, t)) { 
            int y=grid[s][t];
            if (nxt==y)  // continue moving in the same diagonal
                ans=max(ans, 1+dfs(s, t, dir, turn, nxt^2, grid));
        }

        // Try turning to the next diagonal direction
        if (!turn) { 
            const int newDir=(dir+1)&3;// same %4
            int u=i+d[newDir], v=j+d[newDir+1];
            if (!isOutSide(u, v)) {
                const int z=grid[u][v];
                if (nxt==z)  // to turn to the next diagonal
                    ans=max(ans, 1+dfs(u, v, newDir, 1, nxt^2, grid));
            }
        }

        return dp[i][j][dir][turn]=ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        
        for (int i=0; i<n; i++)// fill dp 
            for(int j=0; j<m; j++)
                memset(dp[i][j], -1, sizeof(dp[i][j]));

        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) { // Start from cells that are part of the path
                    for (int d=0; d<4; d++) 
                        ans=max(ans, dfs(i, j, d, 0, 2,  grid));
                }
            }
        }
        return ans;
    }
};
```
# C++ bottom-up iteration|63ms Beats 97.33%
```cpp []
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
```
