<h2><a href="https://leetcode.com/problems/sort-matrix-by-diagonals">3446. Sort Matrix by Diagonals</a></h2><h3>Medium</h3><hr><p>You are given an <code>n x n</code> square matrix of integers <code>grid</code>. Return the matrix such that:</p>

<ul>
	<li>The diagonals in the <strong>bottom-left triangle</strong> (including the middle diagonal) are sorted in <strong>non-increasing order</strong>.</li>
	<li>The diagonals in the <strong>top-right triangle</strong> are sorted in <strong>non-decreasing order</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,7,3],[9,8,2],[4,5,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[[8,2,3],[9,6,7],[4,5,1]]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/29/4052example1drawio.png" style="width: 461px; height: 181px;" /></p>

<p>The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:</p>

<ul>
	<li><code>[1, 8, 6]</code> becomes <code>[8, 6, 1]</code>.</li>
	<li><code>[9, 5]</code> and <code>[4]</code> remain unchanged.</li>
</ul>

<p>The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:</p>

<ul>
	<li><code>[7, 2]</code> becomes <code>[2, 7]</code>.</li>
	<li><code>[3]</code> remains unchanged.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[0,1],[1,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[[2,1],[1,0]]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/29/4052example2adrawio.png" style="width: 383px; height: 141px;" /></p>

<p>The diagonals with a black arrow must be non-increasing, so <code>[0, 2]</code> is changed to <code>[2, 0]</code>. The other diagonals are already in the correct order.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[[1]]</span></p>

<p><strong>Explanation:</strong></p>

<p>Diagonals with exactly one element are already in order, so no changes are needed.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>grid.length == grid[i].length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>-10<sup>5</sup> &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>
<br/>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
A very easy question on matrix with tiny testcases, even much smaller than the similar question `1329. Sort the Matrix Diagonally`
Reuse `grid`; C++ & Python are made.
[Please turn on the English subtiltles, the Python code is made during filming]
[https://youtu.be/09QTQ-kHSSY?si=wcD1Rpja3rowCkJN](https://youtu.be/09QTQ-kHSSY?si=wcD1Rpja3rowCkJN)
# Approach
<!-- Describe your approach to solving the problem. -->
1. Declare `diag[10]` as the global variable as the temp array
2. let `n=|grid|`
3. Compute the upper triangle part `i<=j` as follows
```cpp
// skip grid[0][n-1]
for(int d=n-2; d>0; d--){// diagonal with j=i+d
    for(int i=0; i<n-d; i++)
        diag[i]=grid[i][i+d];// put grid[i][i+d] into diag
    sort(diag, diag+(n-d));// sort diag w.r.t. ascending order
    for(int i=0; i<n-d; i++)
        grid[i][i+d]=diag[i]; // obtain sorted grid[i][i+d] from diag
}
```
4. The lower triangle part `i>j` is proceeding in the similar way; but sort `diag` w.r.t. the descending order
5. return `grid`
6. Since `diag` has at most 10 elements, it's no need to replace `std::sort` by other sorting method(but for the size<=4, bubble sort is the most efficient one)
7. Python code is done in the simila way.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n^2\log n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(10)$
# Code||C++ 0ms|Py3 10ms
```cpp []
int diag[10];
class Solution {
public:
    static vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int n=grid.size();
        for(int d=n-2; d>0; d--){
            for(int i=0; i<n-d; i++)
                diag[i]=grid[i][i+d];
            sort(diag, diag+(n-d));
            for(int i=0; i<n-d; i++)
                grid[i][i+d]=diag[i];
        }
        for (int d=0; d<n-1; d++){
            for(int j=0; j<n-d; j++)
                diag[j]=grid[j+d][j];
            sort(diag, diag+(n-d), greater<>());
            for(int j=0; j<n-d; j++)
                grid[j+d][j]=diag[j];
        }
        return grid;
    }
};
```
```Python []
class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n=len(grid)
        # upper right triangle j=i+d
        for d in range(n-2, -1, -1):
            diag=sorted(grid[i][i+d] for i in range(n-d))
            for i, x in enumerate(diag):
                grid[i][i+d]=x
        # lower left triangle i=j+d
        for d in range(n-1):
            diag=sorted((grid[j+d][j] for j in range(n-d)), reverse=True)
            for j, x in enumerate(diag):
                grid[j+d][j]=x
        return grid
        
        
        
```
