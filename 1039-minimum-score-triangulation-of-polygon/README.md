<h2><a href="https://leetcode.com/problems/minimum-score-triangulation-of-polygon">1039. Minimum Score Triangulation of Polygon</a></h2><h3>Medium</h3><hr><p>You have a convex <code>n</code>-sided polygon where each vertex has an integer value. You are given an integer array <code>values</code> where <code>values[i]</code> is the value of the <code>i<sup>th</sup></code> vertex in <strong>clockwise order</strong>.</p>

<p><strong>Polygon</strong> <strong>triangulation</strong> is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in <code>n - 2</code> triangles.</p>

<p>You will <strong>triangulate</strong> the polygon. For each triangle, the <em>weight</em> of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these <em>weights</em> over all <code>n - 2</code> triangles.</p>

<p>Return the<em> minimum possible score </em>that you can achieve with some<em> </em><strong>triangulation</strong><em> </em>of the polygon.</p>


<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="http://127.0.0.1:49174/shape1.jpg" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">values = [1,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong> The polygon is already triangulated, and the score of the only triangle is 6.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="http://127.0.0.1:49174/shape2.jpg" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">values = [3,7,4,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">144</span></p>

<p><strong>Explanation:</strong> There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.<br />
The minimum score is 144.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<p><img alt="" src="http://127.0.0.1:49174/shape3.jpg" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">values = [1,3,1,4,1,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">13</span></p>

<p><strong>Explanation:</strong> The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == values.length</code></li>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= values[i] &lt;= 100</code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Use Divide & Conquer to solve this question which can be written a top-down design.

The iterative way is also based on the same recurrence implemented.
[This film explains how to implement Python code in the iterative way, please turn on the English subtitles]
[https://youtu.be/MDlLpRRMazo?si=lrbXjZd8JvwT2lMT](https://youtu.be/MDlLpRRMazo?si=lrbXjZd8JvwT2lMT)
# Approach
<!-- Describe your approach to solving the problem. -->
1. let the state matrix be given `dp[i][j]`=min weight for convex polygon `v[i..j]`
2. Let's first consider the recursive function `int f(int i, int j, vector<int>& v)` as follows
```cpp
static int f(int i, int j, vector<int>& v){
    if (dp[i][j]!=-1) 
        return dp[i][j];// avoid of redudant computation
    if (j-i<=1) 
        return dp[i][j]=0; // only 2 sides
    if (j-i==2) 
        return dp[i][j]=v[i]*v[i+1]*v[i+2];// triangle
    // consider the edge v[i], v[j]
    const int e=v[i]*v[j];
    int ans=INT_MAX;
    for(int k=i+1; k<j; k++)
        ans=min(ans, e*v[k]+f(i, k, v)+f(k, j, v));// recursion
    return dp[i][j]=ans;
}
```
3. In `minScoreTriangulation(vector<int>& v)` deals with the special case when n=3 to return `v[0]*v[1]*v[2]`
4. Fill with`dp` with -1
5. return `f(0, n-1, v)`
6. The iterative one uses 2 loops
7. first loop computes the areas of  all triangles formed by 3 consective vertiices `v[i], v[i+1], v[i+2]`
8. The 2nd loop is a triple loop in the following:
```
for (int d=3; d<=n-1; d++){//d-polygons 
    for(int i=0; i<n-d; i++){
        const int j=i+d;
        int w=INT_MAX, e=v[i]*v[j];
        for(int k=i+1; k<j; k++)
            w=min(w, e*v[k]+dp[i][k]+dp[k][j]);
        dp[i][j]=w;
    } 
}
```
![polygon.png](https://assets.leetcode.com/users/images/5e50846b-c6f1-4153-93d3-ba17350547b0_1759106101.6130614.png)

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n^3)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(n^2)$
# Code|iterative DP |0ms
```cpp []
// simplied verion using 1-loop
class Solution {
public:
    static int minScoreTriangulation(vector<int>& v) {
        const int n=v.size();
        if (n==3) return v[0]*v[1]*v[2];

        // dp[i][j]=min weight for convex v[i..j]
        vector<vector<int>> dp(n-1, vector<int>(n, 0));

        for (int d=2; d<=n-1; d++){
            for(int i=0; i<n-d; i++){
                const int j=i+d;
                int w=INT_MAX, e=v[i]*v[j];
                for(int k=i+1; k<j; k++)
                    w=min(w, e*v[k]+dp[i][k]+dp[k][j]);
                dp[i][j]=w;
            } 
        }
        return dp[0][n-1];
    }
};
```
```cpp []
class Solution {
public:
    static int minScoreTriangulation(vector<int>& v) {
        const int n=v.size();
        if (n==3) return v[0]*v[1]*v[2];

        // dp[i][j]=min weight for convex v[i..j]
        vector<vector<int>> dp(n-1, vector<int>(n, 0));
        for(int i=0; i<n-2; i++)
            dp[i][i+2]=v[i]*v[i+1]*v[i+2];
        for (int d=3; d<=n-1; d++){
            for(int i=0; i<n-d; i++){
                const int j=i+d;
                int w=INT_MAX, e=v[i]*v[j];
                for(int k=i+1; k<j; k++)
                    w=min(w, e*v[k]+dp[i][k]+dp[k][j]);
                dp[i][j]=w;
            } 
        }
        return dp[0][n-1];
    }
};
```
# Code| recursion+memo|0ms
```
int dp[50][50];// dp[i][j]=min weight for convex v[i..j]
class Solution {
public:
    static int f(int i, int j, vector<int>& v){
        if (dp[i][j]!=-1) return dp[i][j];
        if (j-i<=1) return dp[i][j]=0; // only 2 sides
        if (j-i==2) return dp[i][j]=v[i]*v[i+1]*v[i+2];
        // consider the edge v[i], v[j]
        const int e=v[i]*v[j];
        int ans=INT_MAX;
        for(int k=i+1; k<j; k++)
            ans=min(ans, e*v[k]+f(i, k, v)+f(k, j, v));
        return dp[i][j]=ans;
    }
    static int minScoreTriangulation(vector<int>& v) {
        const int n=v.size();
        if (n==3) return v[0]*v[1]*v[2];
        for(int i=0; i<n; i++)
            memset(dp[i], -1, 4*n);
        return f(0, n-1, v);
    }
};
```
# Python 
```
# dp[i][j]=min weight for convex v[i..j]
class Solution:
    def minScoreTriangulation(self, v: List[int]) -> int:
        n=len(v)
        if n==3: return v[0]*v[1]*v[2]
        dp=[[0]*n for _ in range(n-1)]

        for d in range(2, n):
            for i in range(n-d):
                j=i+d
                w, e=1<<32, v[i]*v[j]
                for k in range(i+1, j):
                    w=min(w, e*v[k]+dp[i][k]+dp[k][j])
                dp[i][j]=w
        return dp[0][-1]
        
```
