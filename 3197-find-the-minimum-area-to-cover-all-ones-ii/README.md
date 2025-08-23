<h2><a href="https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii">3197. Find the Minimum Area to Cover All Ones II</a></h2><h3>Hard</h3><hr><p>You are given a 2D <strong>binary</strong> array <code>grid</code>. You need to find 3 <strong>non-overlapping</strong> rectangles having <strong>non-zero</strong> areas with horizontal and vertical sides such that all the 1&#39;s in <code>grid</code> lie inside these rectangles.</p>

<p>Return the <strong>minimum</strong> possible sum of the area of these rectangles.</p>

<p><strong>Note</strong> that the rectangles are allowed to touch.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,0,1],[1,1,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/14/example0rect21.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 280px; height: 198px;" /></p>

<ul>
	<li>The 1&#39;s at <code>(0, 0)</code> and <code>(1, 0)</code> are covered by a rectangle of area 2.</li>
	<li>The 1&#39;s at <code>(0, 2)</code> and <code>(1, 2)</code> are covered by a rectangle of area 2.</li>
	<li>The 1 at <code>(1, 1)</code> is covered by a rectangle of area 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,0,1,0],[0,1,0,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/14/example1rect2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 356px; height: 198px;" /></p>

<ul>
	<li>The 1&#39;s at <code>(0, 0)</code> and <code>(0, 2)</code> are covered by a rectangle of area 3.</li>
	<li>The 1 at <code>(1, 1)</code> is covered by a rectangle of area 1.</li>
	<li>The 1 at <code>(1, 3)</code> is covered by a rectangle of area 1.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either 0 or 1.</li>
	<li>The input is generated such that there are at least three 1&#39;s in <code>grid</code>.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
There are 6 different way to cut the `grid`: 2 vertical cuts, 2 horizontal cuts & 4 different T-shapes.

Use bitmask & bitwise operations to decrease the time complexity from quatic to cubic & its elapsed time is only 8ms.
# Approach
<!-- Describe your approach to solving the problem. -->
[Please turn on the Eglish subtitles if necessary]
[https://youtu.be/Xr_CbjD8E9M?si=tbLeopU88sgOEhaj](https://youtu.be/Xr_CbjD8E9M?si=tbLeopU88sgOEhaj)
1. Let 1D arrays `unsigned A[30], T[30]` be the bitwise packed forms for `grid` & its transpose
2. Define `void build_A_T(vector<vector<int>>& grid, int n, int m)` to build `A` & `T`. Since `grid` has only values either 0 or 1 & `1 <= grid.length, grid[i].length <= 30`, it can be used bitmask method to pack the whole row, col into 1 unsigned int. This part has TC $O(nm)$
3. Define `int minRect(int i0, int iN, int j0, int jN)` to compute the area of the bounding box of 1s in submatrix `[i0..iN][j0..jN]`. If none, just return a large int, say `1e8`. The computational way is to proceed in 4 directions from top, bottom, left & right, all bitwise operations, such as
```cpp
// find top row with any 1 in [j0..jN]
for (int i=i0; i<=iN; i++) {
    unsigned row=A[i];
    unsigned mRow=(row>>j0)<<j0;// remove the col k for k<j0
    mRow&=((1u<<(jN+1))-1u);    // remove the col k for k>jN
    if (mRow) { iMin=i; break; }
}
```
4. In `int minimumSum(vector<vector<int>>& grid)`, let `n=|grid|, m=|grid[0]` in matrix convention; then apply `build_A_T(grid, n, m)`
5. 6 different cases to discuss. 2 vertical cuts & 2 horizontal cuts are proceeded in double loop, such as
```cpp
//  2 vertical cuts
for (int c1=0; c1<m-2; c1++) {// 1st cut
    for (int c2=c1+1; c2<m-1; c2++) {// 2nd cut
        int a=minRect(0, n-1, 0,c1);
        int b=minRect(0, n-1, c1+1, c2);
        int c=minRect(0, n-1, c2+1, m-1);
        ans=min(ans, a+b+c);
    }
}
```
6. T-shapes (3-rectangle partitions) has 4 ways to cut. They can all be proceeded in a large double for-loop, such as
```cpp
// top, bottom-left & bottom-right
{
    int top=minRect(0, r, 0, m-1);
    int bl=minRect(r+1, n-1, 0, c);
    int br=minRect(r+1, n-1, c+1, m-1);
    ans=min(ans, top+bl+br);
}
```
7. return `ans`

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
Roughly speaking $O((n+m)^3)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(n+m)$
# Code
```cpp []
unsigned A[30], T[30];

class Solution {
public:
    static void build_A_T(vector<vector<int>>& grid, int n, int m) {
        fill(A, A+n, 0);// reset
        fill(T, T+m, 0);// reset transpose
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==0) continue;
                A[i]|=(1U<<j);  // row i
                T[j]|=(1U<<i);  // col j (transpose)
            }
        }
    }

    // area of the bounding box of 1s in submatrix [i0..iN][j0..jN]
    static int minRect(int i0, int iN, int j0, int jN){
        int iMin=30, iMax=-1, jMin=30, jMax=-1;

        // Proceed in 4 directions
        // find top row with any 1 in [j0..jN]
        for (int i=i0; i<=iN; i++) {
            unsigned row=A[i];
            unsigned mRow=(row>>j0)<<j0;
            mRow&=((1u<<(jN+1))-1u);
            if (mRow) { iMin=i; break; }
        }
        if (iMin==30) return 1e8; // no 1s in this submatrix

        // bottom row
        for (int i=iN; i>=iMin; i--) {
            unsigned row=A[i];
            unsigned mRow=(row>>j0)<<j0;
            mRow&=((1u<<(jN+1))-1u);
            if (mRow) { iMax=i; break; }
        }
        // left col
        for (int j=j0; j<=jN; j++) {
            unsigned col=T[j];
            unsigned mCol=(col>>i0)<<i0;
            mCol&=((1u<<(iN+1)) - 1u);
            if (mCol) { jMin=j; break; }
        }
        // right col
        for (int j=jN; j>=jMin; j--) {
            unsigned col=T[j];
            unsigned mCol=(col>>i0)<<i0;
            mCol&=((1u<<(iN+1)) - 1u);
            if (mCol) { jMax=j; break; }
        }
        return (iMax-iMin+1)*(jMax-jMin+1);
    }

    static int minimumSum(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        build_A_T(grid, n, m);

        int ans=INT_MAX;

        //  2 vertical cuts
        for (int c1=0; c1<m-2; c1++) {
            for (int c2=c1+1; c2<m-1; c2++) {
                int a=minRect(0, n-1, 0,c1);
                int b=minRect(0, n-1, c1+1, c2);
                int c=minRect(0, n-1, c2+1, m-1);
                ans=min(ans, a+b+c);
            }
        }

        // 2 horizontal cuts
        for (int r1=0; r1<n-2; r1++) {
            for (int r2=r1+1; r2<n-1; r2++) {
                int a=minRect(0, r1, 0, m-1);
                int b=minRect(r1+1, r2, 0, m-1);
                int c=minRect(r2+1, n-1, 0, m-1);
                ans=min(ans, a+b+c);
            }
        }

        // T-shapes (3-rectangle partitions)
        for (int r=0; r<n-1; r++) {
            for (int c=0; c<m-1; c++) {
                // top, bottom-left & bottom-right
                {
                    int top=minRect(0, r, 0, m-1);
                    int bl=minRect(r+1, n-1, 0, c);
                    int br=minRect(r+1, n-1, c+1, m-1);
                    ans=min(ans, top+bl+br);
                }
                // bottom, top-left & top-right
                {
                    int bottom=minRect(r+1, n-1, 0, m-1);
                    int tl=minRect(0, r, 0, c);
                    int tr=minRect(0, r, c+1, m-1);
                    ans=min(ans, bottom+tl+tr);
                }
                // left, top-right & bottom-right
                {
                    int left=minRect(0, n-1, 0, c);
                    int tr=minRect(0, r, c+1, m-1);
                    int br=minRect(r+1, n-1, c+1, m-1);
                    ans=min(ans, left+tr+br);
                }
                // right, top-left & bottom-left
                {
                    int right=minRect(0, n-1, c+1, m-1);
                    int tl=minRect(0, r, 0, c);
                    int bl=minRect(r+1, n-1, 0, c);
                    ans = min(ans, right+tl+bl);
                }
            }
        }

        return ans;
    }
};

```
