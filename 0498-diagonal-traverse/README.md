<h2><a href="https://leetcode.com/problems/diagonal-traverse">498. Diagonal Traverse</a></h2><h3>Medium</h3><hr><p>Given an <code>m x n</code> matrix <code>mat</code>, return <em>an array of all the elements of the array in a diagonal order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg" style="width: 334px; height: 334px;" />
<pre>
<strong>Input:</strong> mat = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,4,7,5,3,6,8,9]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mat = [[1,2],[3,4]]
<strong>Output:</strong> [1,2,3,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Go along the lines i+j=d for d=0,1,..
The direction is going NE then flip to SW, then flip to NE etc
# Approach
<!-- Describe your approach to solving the problem. -->
1. let `r=|mat|`, `c=|mat[0]|`
2. declare the 2D vector `ans(r*c)`
3. initialize `flip=false`
4. Proceed the loop as follows:
```cpp
// along the line i+j=d for d=0,1, r+c-2; flip after each iteration
for (int d=0, idx=0; d < r+c-1; d++, flip=!flip) {
    if (!flip) {// go NE
        // initital with i=min(d, r-1), j=d-i
        // do while i>=0 && j<c; change i--, j++ 
        for (int i=min(d, r-1), j=d-i; i>=0 && j<c; i--, j++) 
            ans[idx++]=mat[i][j];
    } 
    else {// go SW
        // initial with j=min(d, c-1), i=d-j
        // do while j>=0 && i<r; change i++, j--
        for (int j=min(d, c-1), i=d-j; j>=0 && i<r; i++, j--) {
            ans[idx++]=mat[i][j];
        }
    }
}
```
5. return `ans`
6. Python code is made in the similar way
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(rc)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
Extra space $O(1)$ not counting `ans` ($O(rc)$)
# Code
```cpp []
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int r=mat.size(), c=mat[0].size();
        vector<int> ans(r*c);
        bool flip=0;

        for (int d=0, idx=0; d < r+c-1; d++, flip=!flip) {
            if (!flip) {// go NE
                for (int i=min(d, r-1), j=d-i; i>=0 && j<c; i--, j++) 
                    ans[idx++]=mat[i][j];
            } 
            else {// go SW
                for (int j=min(d, c-1), i=d-j; j>=0 && i<r; i++, j--) {
                    ans[idx++]=mat[i][j];
                }
            }
        }
        return ans;
    }
};


```
# Python||3ms
```
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        r, c=len(mat), len(mat[0])
        ans=[0]*(r*c)
        flip, idx=0, 0
        for d in range(r+c-1):
            if flip==0:
                i=min(d, r-1)
                j=d-i
                while i>=0 and j<c:
                    ans[idx]=mat[i][j]
                    i-=1
                    j+=1
                    idx+=1
            else:
                j=min(d, c-1)
                i=d-j
                while j>=0 and i<r:
                    ans[idx]=mat[i][j]
                    i+=1
                    j-=1
                    idx+=1
            flip=1-flip
        return ans  
```
