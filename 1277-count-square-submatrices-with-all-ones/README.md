<h2><a href="https://leetcode.com/problems/count-square-submatrices-with-all-ones">1277. Count Square Submatrices with All Ones</a></h2><h3>Medium</h3><hr><p>Given a <code>m * n</code> matrix of ones and zeros, return how many <strong>square</strong> submatrices have all ones.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> matrix =
[
&nbsp; [0,1,1,1],
&nbsp; [1,1,1,1],
&nbsp; [0,1,1,1]
]
<strong>Output:</strong> 15
<strong>Explanation:</strong> 
There are <strong>10</strong> squares of side 1.
There are <strong>4</strong> squares of side 2.
There is  <strong>1</strong> square of side 3.
Total number of squares = 10 + 4 + 1 = <strong>15</strong>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
<strong>Output:</strong> 7
<strong>Explanation:</strong> 
There are <b>6</b> squares of side 1.  
There is <strong>1</strong> square of side 2. 
Total number of squares = 6 + 1 = <b>7</b>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 300</code></li>
	<li><code>1 &lt;= arr[0].length&nbsp;&lt;= 300</code></li>
	<li><code>0 &lt;= arr[i][j] &lt;= 1</code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Reuse matrix as state matrix. Let `matrix[i][j]` hold the number of all 1s squares with  bottom-right corner (i, j)-term. It's to note that the number of such squares is the the width of the biggest square  with this corner.

[Please turn on the English subtitles if necessary]
[https://youtu.be/HhckuZwDVe8?si=z1eDE49UUi2AMqou](https://youtu.be/HhckuZwDVe8?si=z1eDE49UUi2AMqou)
Recursive solution also included. The recurrence can be derived from the following figure
![1277.png](https://assets.leetcode.com/users/images/cc11dfc3-d08a-4ab5-bf08-df572f1dc5bd_1755657914.5041687.png)

# Approach
<!-- Describe your approach to solving the problem. -->
1. let `r=|matrix|` `c=matrix[0]`
2. let `cnt=0` initially
3. add number of 1s in 0th row to `cnt`; all submatrices `[1]` are to be counted
4. add number of 1s in 0th col to `cnt`( `matrix[0][0]` exclusive)
5. A double loop finishes the job
```cpp
for(int i=1; i<r; i++)
    for(int j=1; j<c; j++){
        if (matrix[i][j]==0) continue;
        // consider the the left-up, up, left & [matrix[i][j]]
        matrix[i][j]=1+min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]});
        cnt+=matrix[i][j];// add it to cnt
    }
return cnt;
```
6. Add a Python code in the iterative version
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(rc)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code iterative DP||0ms
```cpp []
class Solution {
public:
    static int countSquares(vector<vector<int>>& matrix) {
        const int r=matrix.size(), c=matrix[0].size();
        int cnt=0;
        cnt=count(matrix[0].begin(), matrix[0].end(), 1);
        for(int i=1; i<r; i++) 
            cnt+=matrix[i][0];;
        
        for(int i=1; i<r; i++)
            for(int j=1; j<c; j++){
                if (matrix[i][j]==0) continue;
                matrix[i][j]=1+min(matrix[i-1][j], min(matrix[i-1][j-1], matrix[i][j-1]));
                cnt+=matrix[i][j];
            }
        return cnt;
    }
};


```
```Python []
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        r, c=len(matrix), len(matrix[0])
        cnt=matrix[0].count(1)
        for i in range(1, r): 
            cnt+=matrix[i][0]
        for i in range(1, r):
            for j in range(1, c):
                if matrix[i][j]==0: continue
                matrix[i][j]=1+min(matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1])
                cnt+=matrix[i][j]
        return cnt

        
```
# Recursion with memo
```cpp []
class Solution {
public:
    int dp[300][300];
    int f(int i, int j, vector<vector<int>>& matrix){
        if (i<0||j<0|| matrix[i][j]==0 ) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({f(i-1, j, matrix),f(i-1, j-1, matrix),f(i, j-1, matrix)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        const int r=matrix.size(), c=matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int cnt=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cnt+=f(i, j, matrix);
        return cnt;
    }
};

```
