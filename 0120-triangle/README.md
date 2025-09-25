<h2><a href="https://leetcode.com/problems/triangle/?envType=daily-question&envId=2025-09-25">120. Triangle</a></h2><h3>Medium</h3><hr><p>Given a <code>triangle</code> array, return <em>the minimum path sum from top to bottom</em>.</p>

<p>For each step, you may move to an adjacent number of the row below. More formally, if you are on index <code>i</code> on the current row, you may move to either index <code>i</code> or index <code>i + 1</code> on the next row.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The triangle looks like:
   <u>2</u>
  <u>3</u> 4
 6 <u>5</u> 7
4 <u>1</u> 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> triangle = [[-10]]
<strong>Output:</strong> -10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= triangle.length &lt;= 200</code></li>
	<li><code>triangle[0].length == 1</code></li>
	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
	<li><code>-10<sup>4</sup> &lt;= triangle[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you&nbsp;do this using only <code>O(n)</code> extra space, where <code>n</code> is the total number of rows in the triangle?

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Use recursion with memo to solve.
Later try other approach when having time.
Leetcode said:
> Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

The iterative one is simple which reuses `triangle` as the state matrix; that's just O(1) space
[The film shows how to do it. Please turn on the English subtitles if necessary]
[https://youtu.be/wow51Gqo9YM?si=iPBgxef-deRCV5Tt](https://youtu.be/wow51Gqo9YM?si=iPBgxef-deRCV5Tt)

Since someone has problems with the extra space O(1) by reusing `triangle`, make one  iterative version using $O(n)$ extra  space without reusing `triangle`.
# Approach
<!-- Describe your approach to solving the problem. -->
![LC120.png](https://assets.leetcode.com/users/images/37b9fef3-a285-4af7-9e3c-c4a042f14c9d_1758777375.238442.png)

1. let `vector<vector<int>> dp` be the member variable.
2. Declare `n` as a member variable.
3. define the recursive function `findMin(int i, int j, vector<vector<int>>& t)` to find the value for `dp[i][j]` as follows:
```cpp
if (dp[i][j] != INT_MAX) 
    return dp[i][j];// avoid of redudant computation
if (i==0) 
    return dp[0][0] = t[0][0];// base case for i==0
if (j==0) 
    return dp[i][j] = t[i][j] + findMin(i-1, j, t);// deal with j==0
if (i==j) 
    return dp[i][j] = t[i][j] + findMin(i-1,j-1, t);// deal with i==j
// otherwise
return dp[i][j] = 
        t[i][j] + min(findMin(i - 1, j, t), findMin(i - 1, j - 1, t));
```
4. In `int minimumTotal(vector<vector<int>>& triangle)` let `n=|triangle|`
5. Assign the initial values for `dp` with `INT_MAX`
6. Initialize `ans = INT_MAX`
7. Proceed a loop to find the min by using `ans = min(ans, findMin(n - 1, j, triangle))` for j=0 to n-1
8. return `ans`
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n^2)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(n^2)\to O(1)$
# Code iterative C++ with space O(1)|0ms |Py3 code done in flim
```cpp []
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        const int n=t.size();
        for(int i=1; i<n; i++){
            t[i][0]+=t[i-1][0];
            t[i][i]+=t[i-1][i-1];
            for(int j=1; j<i; j++){
                t[i][j]+=min(t[i-1][j], t[i-1][j-1]);
            }
        }
        return *min_element(t[n-1].begin(), t[n-1].end());
    }
};
```
```Python []
class Solution:
    def minimumTotal(self, t: List[List[int]]) -> int:
        n=len(t)
        for i in range(1, n):
            t[i][0]+=t[i-1][0]
            t[i][i]+=t[i-1][i-1]
            for j in range(1, i):
                t[i][j]+=min(t[i-1][j], t[i-1][j-1])
        return min(t[-1])
        
```
# Code||recursive C++ 0ms
```cpp []
class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int findMin(int i, int j, vector<vector<int>>& t) {
        if (dp[i][j] != INT_MAX) return dp[i][j];
        if (i == 0) return dp[0][0] = t[0][0];
        if (j == 0) return dp[i][j] = t[i][j] + findMin(i-1, j, t);
        if (i == j) return dp[i][j] = t[i][j] + findMin(i-1,j-1, t);
        return dp[i][j] = 
        t[i][j] + min(findMin(i - 1, j, t), findMin(i - 1, j - 1, t));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;  
        for (int j = 0; j < n; j++) {
            ans = min(ans, findMin(n - 1, j, triangle));
        }
        return ans;
    }      
};

```
# C++ O(n) space||0ms
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        const int n=t.size();
        vector<int> dp(n, t[0][0]);
        for(int i=1; i<n; i++){
            dp[i]=dp[i-1]+t[i][i];
            for(int j=i-1; j>=1; j--){
                dp[j]=t[i][j]+min(dp[j], dp[j-1]);
            }
            dp[0]+=t[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
```
