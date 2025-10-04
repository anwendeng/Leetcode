<h2><a href="https://leetcode.com/problems/container-with-most-water">11. Container With Most Water</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>height</code> of length <code>n</code>. There are <code>n</code> vertical lines drawn such that the two endpoints of the <code>i<sup>th</sup></code> line are <code>(i, 0)</code> and <code>(i, height[i])</code>.</p>

<p>Find two lines that together with the x-axis form a container, such that the container contains the most water.</p>

<p>Return <em>the maximum amount of water a container can store</em>.</p>

<p><strong>Notice</strong> that you may not slant the container.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;" />
<pre>
<strong>Input:</strong> height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Very classical problem, done before.
[This film shows how to implement by using Python. Please turn on the  English subtitles if necessary]
[https://youtu.be/1pPC3uarDNA?si=4Bx_dyFPZBVyftgI](https://youtu.be/1pPC3uarDNA?si=4Bx_dyFPZBVyftgI)
# Approach
<!-- Describe your approach to solving the problem. -->
![question_11.jpg](https://assets.leetcode.com/users/images/f2dc13f3-c562-4535-9d46-11bdbf8cf22a_1759539689.56715.jpeg)

1. define the function `int area(int l, int r, vector<int>& height)` which computes `min(height[l], height[r])*(r-l)`, i.e. the water area for `l` & `r` can hold.
2. `n=|height|`
3. Starting 2-pointer `l=0 & r=n-1`
4. Let `A=area(l, r, height)`
5. Use a while loop do the following
```cpp
while (l<r){
    //update A with max of A & current area
    A=max(A, area(l, r, height));

    // move either r or l when its height is smaller
    if(height[r]<height[l]) r--;// moving r
    else l++;// moving l
}
```
6. return `A`
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|0ms
```C []
#pragma GCC optimize("O3, unroll-loops")
static int maxArea(int* height, int n) {
    int A=0;
    for(int l=0, r=n-1; l<r; ){
        A=fmax(A, fmin(height[l], height[r])*(r-l));
        if (height[r]<height[l]) r--;
        else l++;
    }
    return A;
}
```
```cpp []
class Solution {
public:
    static inline int area(int l, int r, vector<int>& height){
        return min(height[l], height[r])*(r-l);
    }
    static int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int A=area(l, r, height);
        while (l<r){
            A=max(A, area(l, r, height));
            if(height[r]<height[l]) r--;
            else l++;
        }
        return A;   
    }
};
```
# Python

```
class Solution:
    def maxArea(self, h: List[int]) -> int:
        n=len(h)
        A, l, r=0, 0, n-1
        while l<r:
            A=max(A, min(h[l], h[r])*(r-l))
            if h[r]<h[l]: r-=1
            else: l+=1
        return A
        
```
