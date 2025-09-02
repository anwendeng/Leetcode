<h2><a href="https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i">3025. Find the Number of Ways to Place People I</a></h2><h3>Medium</h3><hr><p>You are given a 2D array <code>points</code> of size <code>n x 2</code> representing integer coordinates of some points on a 2D plane, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>Count the number of pairs of points <code>(A, B)</code>, where</p>

<ul>
	<li><code>A</code> is on the <strong>upper left</strong> side of <code>B</code>, and</li>
	<li>there are no other points in the rectangle (or line) they make (<strong>including the border</strong>).</li>
</ul>

<p>Return the count.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">points = [[1,1],[2,2],[3,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2024/01/04/example1alicebob.png" style="width: 427px; height: 350px;" /></p>

<p>There is no way to choose <code>A</code> and <code>B</code> so <code>A</code> is on the upper left side of <code>B</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">points = [[6,2],[4,4],[2,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><img height="365" src="https://assets.leetcode.com/uploads/2024/06/25/t2.jpg" width="1321" /></p>

<ul>
	<li>The left one is the pair <code>(points[1], points[0])</code>, where <code>points[1]</code> is on the upper left side of <code>points[0]</code> and the rectangle is empty.</li>
	<li>The middle one is the pair <code>(points[2], points[1])</code>, same as the left one it is a valid pair.</li>
	<li>The right one is the pair <code>(points[2], points[0])</code>, where <code>points[2]</code> is on the upper left side of <code>points[0]</code>, but <code>points[1]</code> is inside the rectangle so it&#39;s not a valid pair.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">points = [[3,1],[1,3],[1,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2024/06/25/t3.jpg" style="width: 1269px; height: 350px;" /></p>

<ul>
	<li>The left one is the pair <code>(points[2], points[0])</code>, where <code>points[2]</code> is on the upper left side of <code>points[0]</code> and there are no other points on the line they form. Note that it is a valid state when the two points form a line.</li>
	<li>The middle one is the pair <code>(points[1], points[2])</code>, it is a valid pair same as the left one.</li>
	<li>The right one is the pair <code>(points[1], points[0])</code>, it is not a valid pair as <code>points[2]</code> is on the border of the rectangle.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 50</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= points[i][0], points[i][1] &lt;= 50</code></li>
	<li>All <code>points[i]</code> are distinct.</li>
</ul>
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Same solution as solving [3027. Find the Number of Ways to Place People II](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/) which can pass the hard one, it passes this medium one with the elapsed time 0ms
[Solving LC 3027. Please turn on the English subtitles if necessary]
[https://youtu.be/hQcQJAb2s-k?si=_sl9qmrYzrACZ12C](https://youtu.be/hQcQJAb2s-k?si=_sl9qmrYzrACZ12C)
# Approach
<!-- Describe your approach to solving the problem. -->
1. Define the `bool cmp(vector<int>& p, vector<int>& q)` ordered by `(x, >)` , if p[0]==q[0], ordered by `(y, <`)
2. In `int numberOfPairs(vector<vector<int>>& P)` sort `P` according to `cmp`
3. let `n=|P|` `ans=0`
4. Proceed the double loop
```cpp
for(int i=0; i<n-1; i++){
    int y=INT_MAX;
    for(int j = i+1; j<n; j++){
        //P[j] has y-coordinate in [P[j][1], y)
        if (P[j][1]>=P[i][1] && y>P[j][1]){
            ans++;
            y=P[j][1];
        }
    }
}
```
5. Add a Python code 
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n^2)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|C++ 0ms
```cpp []
// this version is slight modified for LC 3027
class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
    static int numberOfPairs(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), cmp);
        int n = P.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX, yi=P[i][1];
            for(int j = i+1; j<n; j++){
                const int yj=P[j][1];
                if (yj>=yi && y>yj){//P[j] cannot be in between
                    ans++;
                    y=yj;
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
```cpp []
class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }

    int numberOfPairs(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), cmp);
        int n = P.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX;
            for(int j = i+1; j<n; j++){
                if (P[j][1]>=P[i][1] && y>P[j][1]){
                    ans++;
                    y=P[j][1];
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
```Python []
class Solution:
    def numberOfPairs(self, P: List[List[int]]) -> int:
        P.sort(key=lambda p: (-p[0], p[1]))
        n, ans=len(P), 0
        for i in range(n-1):
            y=1<<31
            for j in range(i+1, n):
                if y>P[j][1]>=P[i][1]:
                    ans+=1
                    y=P[j][1]
        return ans
```
