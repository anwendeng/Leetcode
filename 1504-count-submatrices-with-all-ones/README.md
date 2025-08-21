<h2><a href="https://leetcode.com/problems/count-submatrices-with-all-ones">1504. Count Submatrices With All Ones</a></h2><h3>Medium</h3><hr><p>Given an <code>m x n</code> binary matrix <code>mat</code>, <em>return the number of <strong>submatrices</strong> that have all ones</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/27/ones1-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[1,0,1],[1,1,0],[1,1,0]]
<strong>Output:</strong> 13
<strong>Explanation:</strong> 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/27/ones2-grid.jpg" style="width: 324px; height: 245px;" />
<pre>
<strong>Input:</strong> mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
<strong>Output:</strong> 24
<strong>Explanation:</strong> 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 150</code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
1. reuse mat to compute the heights 
2. Use mono stack to find the widths 
3. Consider the area of the rectangle with right bottom  corner `(i, j)` which is the number of all its subrectangles with this corner. more is shown in the figure
![mnostack.png](https://assets.leetcode.com/users/images/dadb659f-5a46-4ba1-910f-b0da584a4fac_1755757898.1883192.png)

Let `h[j]` denote height for `mat[i][j]`; Use the mono stack for for heights, it will pop out all index `top` until `h[j]>(or >=) h[left]` ( due to implementation) where `left=st[top]`. The new added rectangle has width=`j-left` & height `h[j]`; all rectangles with right-bottom corner at `(i, left)` can be 1-1 extended to the rectangles with right-bottom corner at `(i, j)` as shown with dash in the figure
# Approach
<!-- Describe your approach to solving the problem. -->
1. use C array with  variable `top` to implement stack `st`
2. use a nested loop to solve. The outter loop has control  variable  i from 0 to r-1,  let `h=mat[i]` by ref. Compute the heights for `mat[i][j]`
3.  for each i, reset the stack st by setting  `top=-1;` reset the array `cnt `
4. use mono stack/ while loop  to find the index left on the top for `h[j]` which is the last one such that `h[left]<=h[j]`
5. the rectangle has the area `(j-left)h[j]` compute `cnt[j]=cnt[left]+(j-left)h[j]` if `st` is not empty; otherwise `left=-1 cnt[-1]=0`
6.  add `cnt[j]` to `ans`
7. return `ans`
8. The mono stack `st` can pop out all its element when `h[j]=0` by setting `top=-1`, then push `j` to `st`; a variant is made. That's the advantage of implementation by C-array, to clear the stack it takes only 1 operation.
# mono stack used like solving hard [LC 42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/solutions/5010020/monotonic-stack-vs-priority-queue-using-pyplot-explain-3ms-beats-99-10/) 
[![影片縮圖](https://img.youtube.com/vi/IERpc-YJIT0/0.jpg)](https://www.youtube.com/watch?v=IERpc-YJIT0)
[https://youtu.be/IERpc-YJIT0?si=0-HCtnRgN2iG1i0g](https://youtu.be/IERpc-YJIT0?si=0-HCtnRgN2iG1i0g)
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$
O(rc )
$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$
O (150)
$$
# Code|C++ all 0m
```cpp []
// variant
int st[150], top=-1;//mono stack
int cnt[150]={0};
class Solution {
public:
    static int numSubmat(vector<vector<int>>& mat) {
        const int r=mat.size(), c=mat[0].size();
 
        int ans=0;
        for (int i=0; i<r; i++){
            auto& h=mat[i];//height
            top=-1;// reset mono stack
            fill(cnt, cnt+c, 0);
            for(int j=0; j<c; j++){
                if (h[j]==0){
                    top=-1; // not 1 by 1, pop out at once O(1) time
                    st[++top]=j;
                    continue;                
                }
                if (i>0)
                    h[j]+=mat[i-1][j];// height for mat[i][j]
                
                while(top>-1 && h[st[top]]>= h[j]) 
                    top--;// pop
                int left=(top==-1)?-1:st[top];
                cnt[j]=(top>-1?cnt[left]:0)+h[j]*(j-left);
                ans+=cnt[j];
                st[++top]=j;// push j to stack
            }
        }
        return ans;
    }
}; 
```
```cpp []
int st[150], top=-1;//mono stack
int cnt[150]={0};
class Solution {
public:
    static int numSubmat(vector<vector<int>>& mat) {
        const int r=mat.size(), c=mat[0].size();
 
        int ans=0;
        for (int i=0; i<r; i++){
            auto& h=mat[i];//height
            top=-1;// reset mono stack
            fill(cnt, cnt+c, 0);
            for(int j=0; j<c; j++){
                if (i>0 && h[j]>0) 
                    h[j]+=mat[i-1][j];// height for mat[i][j]
                
                while(top>-1 && h[st[top]]> h[j]) 
                    top--;// pop
                int left=(top==-1)?-1:st[top];
                cnt[j]=(top>-1?cnt[left]:0)+h[j]*(j-left);
                ans+=cnt[j];
                st[++top]=j;// push j to stack
            }
        }
        return ans;
    }
};
