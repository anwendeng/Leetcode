<h2><a href="https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle">3000. Maximum Area of Longest Diagonal Rectangle</a></h2><h3>Easy</h3><hr><p>You are given a 2D <strong>0-indexed </strong>integer array <code>dimensions</code>.</p>

<p>For all indices <code>i</code>, <code>0 &lt;= i &lt; dimensions.length</code>, <code>dimensions[i][0]</code> represents the length and <code>dimensions[i][1]</code> represents the width of the rectangle<span style="font-size: 13.3333px;"> <code>i</code></span>.</p>

<p>Return <em>the <strong>area</strong> of the rectangle having the <strong>longest</strong> diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the <strong>maximum</strong> area.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> dimensions = [[9,3],[8,6]]
<strong>Output:</strong> 48
<strong>Explanation:</strong> 
For index = 0, length = 9 and width = 3. Diagonal length = sqrt(9 * 9 + 3 * 3) = sqrt(90) &asymp;<!-- notionvc: 882cf44c-3b17-428e-9c65-9940810216f1 --> 9.487.
For index = 1, length = 8 and width = 6. Diagonal length = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10.
So, the rectangle at index 1 has a greater diagonal length therefore we return area = 8 * 6 = 48.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> dimensions = [[3,4],[4,3]]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Length of diagonal is the same for both which is 5, so maximum area = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dimensions.length &lt;= 100</code></li>
	<li><code><font face="monospace">dimensions[i].length == 2</font></code></li>
	<li><code><font face="monospace">1 &lt;= dimensions[i][0], dimensions[i][1] &lt;= 100</font></code></li>
</ul>
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Done long ago.
Find the Max squared diagonal (not taking sqrt for $w^2+h^2$), update the max Area

[Please turn on the English subtitles if necessary]

[![影片縮圖](https://img.youtube.com/vi/keBcbyh4Z7A/0.jpg)](https://www.youtube.com/watch?v=keBcbyh4Z7A)
[https://youtu.be/keBcbyh4Z7A?si=WSv9Wypw-S9Iar3Q](https://youtu.be/keBcbyh4Z7A?si=WSv9Wypw-S9Iar3Q)
2nd approach defines a custom `cmp` to give the ordering based on the pair $(w^2+h^2, wh)$, then uses `max_element` which is also fast; Python code is made in the similar way in 2 lines.
# Approach
<!-- Describe your approach to solving the problem. -->
1. let `maxArea=0, Mdia2=0` be given initially where `Mdia` denoe the Max squared diagonal.
2. Proceed the loop
```cpp
for (auto& r: dimensions){// Trasverse all elements in dimension
    // compute the w, h & square diagonal
    int w=r[0], h=r[1], dia2=w*w+h*h;

    if (Mdia2<dia2){// if Mdia2<dia2
        Mdia2=dia2;// update Mdia
        maxArea=0; // reset maxArea
    }
    if (dia2==Mdia2) //if dia2==Mdia2
        //update maxArea by taking max with current area w*h
        maxArea=max(maxArea, w*h);
}
```
3. 2nd approach defines the custom lamba cmp as follows
```cpp
auto cmp=[](vector<int>& r1, vector<int>& r2){
    const int w1=r1[0], h1=r1[1], w2=r2[0], h2=r2[1];
    return make_pair(w1*w1+h1*h1, w1*h1)<make_pair(w2*w2+h2*h2, w2*h2);
};
```
4. let the iterator `it=max_element(dimensions.begin(), dimensions.end(), cmp)`
5. `(*it)[0]*(*it)[1]` is the answer
6. 2-line Python code is done.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$ O(|dimension|)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|C++0ms
```cpp []
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0, Mdia2=0;
        for (auto& r: dimensions){
            int w=r[0], h=r[1], dia2=w*w+h*h;
            if (Mdia2<dia2){
                Mdia2=dia2;
                maxArea=0;
            }
            if (dia2==Mdia2)
                maxArea=max(maxArea, w*h);
        }
        return maxArea;
    }
};

```
# 2nd appraoch |0ms
```cpp 
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        auto cmp=[](vector<int>& r1, vector<int>& r2){
            const int w1=r1[0], h1=r1[1], w2=r2[0], h2=r2[1];
            return make_pair(w1*w1+h1*h1, w1*h1)<make_pair(w2*w2+h2*h2, w2*h2);
        };
        auto it=max_element(dimensions.begin(), dimensions.end(), cmp);
        return (*it)[0]*(*it)[1];
    }
};
```
# 2-line Python||0ms
```Python 
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        it=max(dimensions, key=lambda r:(r[0]**2+r[1]**2, r[0]*r[1]))
        return it[0]*it[1]
        
```
