<h2><a href="https://leetcode.com/problems/largest-triangle-area">812. Largest Triangle Area</a></h2><h3>Easy</h3><hr><p>Given an array of points on the <strong>X-Y</strong> plane <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>, return <em>the area of the largest triangle that can be formed by any three different points</em>. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png" style="height: 369px; width: 450px;" />
<pre>
<strong>Input:</strong> points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
<strong>Output:</strong> 2.00000
<strong>Explanation:</strong> The five points are shown in the above figure. The red triangle is the largest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> points = [[1,0],[0,0],[0,1]]
<strong>Output:</strong> 0.50000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 50</code></li>
	<li><code>-50 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 50</code></li>
	<li>All the given points are <strong>unique</strong>.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Let $P_i=(a_0, a_1), P_j=(b_0, b_1), P_k＝(c_0, c_1)$ be the the coordinates for the vertices of the triangle. The area is 
$\frac{|(b_0-a_0)(c_1-a_1)-(b_1-a_1)(c_0-a_0)|}{2}$ which is the in fact the half of the absolute value for the determinant of the vectors $P_j-P_i$ & $P_k-P_i$ (or cross product?); that I learned from the school Math.

Since several people gave comments on Hull convex, let me implement also a solution using Convex hull.
# Approach
<!-- Describe your approach to solving the problem. -->
Triple loop computes the formula given above & finds the max area.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n^3)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|C++ 0ms
```cpp []
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int n=points.size();
        double maxArea=0;
        for(int i=0; i<n-2; i++){
            const int a0=points[i][0], a1=points[i][1];
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    double area=0.5*((points[j][0]-a0)*(points[k][1]-a1)-(points[j][1]-a1)*(points[k][0]-a0));
                    if (area<0) area=-area;
                    maxArea=max(maxArea, area);

                }
            }
        }
        return maxArea;
    }
};
```
```Python []
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        n=len(points)
        maxA=0
        for i in range(n-2):
            a0, a1=points[i]
            for j in range(i+1, n-1):
                b0, b1=points[j]
                for k in range(j+1, n):
                    c0, c1=points[k]
                    area=(b0-a0)*(c1-a1)-(b1-a1)*(c0-a0)
                    maxA=max(maxA, abs(area))
        return 0.5*maxA
        
```
# Notes on Convex hull
Convex hull is a good idea & comes from algorithms on Geometry. It finds the points on the boundary of the convex polygon( All points are inside of this convex polygon); the rest is to do the same thing as a trple loop over these points. 

There are several different algoithms which are far beyond as marked "easy".
https://en.wikipedia.org/wiki/Convex_hull_algorithms
One doable method is so-called "Monotone chain" (https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain)
![Animation_depicting_the_Monotone_algorithm.gif](https://assets.leetcode.com/users/images/106dc982-38f6-4bed-be64-6a4f1898adca_1758958551.8845701.gif)
# Code using Convex Hull |0ms
```
class Solution {
public:
    using int2 = pair<short, short>;

    static int cross(const int2& O, const int2& P, const int2& Q){
        const auto& [a0, a1]=O; 
        const auto& [b0, b1]=P; 
        const auto& [c0, c1]=Q; 
        return (b0-a0)*(c1-a1)-(b1-a1)*(c0-a0);
    }

    static double maxArea(const vector<int2>& P, int n){
        double maxA=0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    double area=abs(cross(P[i],P[j],P[k]));
                    maxA=max(maxA, area);
                }
            }
        }
        return 0.5*maxA;
    }

    static double largestTriangleArea(vector<vector<int>>& points) {
        const int n=points.size();
        vector<int2> P(n);
        for(int i=0; i<n; i++) P[i]={points[i][0], points[i][1]};
        sort(P.begin(), P.end());

        vector<int2> Hull(2*n);
        int k=0;
        // lower hull
        for(int i=0; i<n; i++){
            while(k>=2 && cross(Hull[k-2], Hull[k-1], P[i])<=0)
                k--;
            Hull[k++]=P[i];
        }
        // upper hull
        for(int i=n-1, t=k+1; i>=0; i--){
            while(k>=t && cross(Hull[k-2], Hull[k-1], P[i])<=0) 
                k--;
            Hull[k++]=P[i];
        }
        // remove duplicate start point
        return maxArea(Hull, k-1);
    }
};

```
