<h2><a href="https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2025-10-25">1716. Calculate Money in Leetcode Bank</a></h2><h3>Easy</h3><hr><p>Hercy wants to save money for his first car. He puts money in the Leetcode&nbsp;bank <strong>every day</strong>.</p>

<p>He starts by putting in <code>$1</code> on Monday, the first day. Every day from Tuesday to Sunday, he will put in <code>$1</code> more than the day before. On every subsequent Monday, he will put in <code>$1</code> more than the <strong>previous Monday</strong>.<span style="display: none;"> </span></p>

<p>Given <code>n</code>, return <em>the total amount of money he will have in the Leetcode bank at the end of the </em><code>n<sup>th</sup></code><em> day.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> 10
<strong>Explanation:</strong>&nbsp;After the 4<sup>th</sup> day, the total is 1 + 2 + 3 + 4 = 10.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 37
<strong>Explanation:</strong>&nbsp;After the 10<sup>th</sup> day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2<sup>nd</sup> Monday, Hercy only puts in $2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 20
<strong>Output:</strong> 96
<strong>Explanation:</strong>&nbsp;After the 20<sup>th</sup> day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Arithmetic Progression done before.
Consider the arithmetic progression 
$$
a, a+d, a+2d,\cdots, e=a+(r-1)d
$$
The sum is $\frac{(a+e)r}{2}$. 
Add a Python 1-liner.
# Approach
[Please turn on English subtitles if necessary]
[https://youtu.be/TqKZGAHLKdw?si=FzWxIkiRxqOtcOX8](https://youtu.be/TqKZGAHLKdw?si=FzWxIkiRxqOtcOX8)
![1716. Calculate Money in Leetcode Bank.jpg](https://assets.leetcode.com/users/images/6fd94b87-9f41-4587-9dfe-44679e67a996_1701823029.1111803.jpeg)

The 2nd version defines a function computing the sum for arithmetic progression
```
    int arithmeticProgression(int leading, int last, int terms){
        return (leading+last)*terms/2;
    }
```
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(1)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(1)$$
# Code |0ms
```C++ []
class Solution {
public:
    int totalMoney(int n) {
        auto [q, r]=div(n, 7);
        return 28*q+7*q*(q-1)/2+(2*q+r+1)*r/2;
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
```python []
class Solution:
    def totalMoney(self, n: int) -> int:
        q, r= divmod(n, 7)
        return 28*q+7*q*(q-1)//2+(2*q+r+1)*r//2
        
```
# Python 1-liner|0ms
```Python []
class Solution:
    def totalMoney(self, n: int) -> int:
        return 28*(q:=n//7)+7*q*(q-1)//2+(2*q+(r:=n%7)+1)*r//2
```
# 2nd C++ Version with function arithmeticProgression runs in 0ms & beats 100%

```python []
class Solution:
    def totalMoney(self, n: int) -> int:
        def arithmeticProgression(leading, last, terms):
            return (leading+last)*terms//2
        q, r= divmod(n, 7)
        return arithmeticProgression(28, 28+(q-1)*7, q)+arithmeticProgression(q+1, q+r, r)
        
```
```C++ []
class Solution {
public:
    int arithmeticProgression(int leading, int last, int terms){
        return (leading+last)*terms/2;
    }
    int totalMoney(int n) {
        auto [q, r]=div(n, 7);
        return arithmeticProgression(28, 28+(q-1)*7, q)+arithmeticProgression(q+1, q+r, r);
    }
};
```
