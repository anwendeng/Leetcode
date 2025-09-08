<h2><a href="https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers">1317. Convert Integer to the Sum of Two No-Zero Integers</a></h2><h3>Easy</h3><hr><p><strong>No-Zero integer</strong> is a positive integer that <strong>does not contain any <code>0</code></strong> in its decimal representation.</p>

<p>Given an integer <code>n</code>, return <em>a list of two integers</em> <code>[a, b]</code> <em>where</em>:</p>

<ul>
	<li><code>a</code> and <code>b</code> are <strong>No-Zero integers</strong>.</li>
	<li><code>a + b = n</code></li>
</ul>

<p>The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> [1,1]
<strong>Explanation:</strong> Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 11
<strong>Output:</strong> [2,9]
<strong>Explanation:</strong> Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Basically, use the concept of subtraction to split; when digit=0, 1, it might borrow from the next digit like subtracton.
[Python is done in the film. Please turn on the english subtitles if necessary]
[https://youtu.be/yb7SsUXX2_U?si=uNnz6h2tLjMkmaF4](https://youtu.be/yb7SsUXX2_U?si=uNnz6h2tLjMkmaF4)
# Approach
<!-- Describe your approach to solving the problem. -->
1. let `a=0, b= 0, tens=1`
2. Proceed a loop to finish the  job:
```cpp
for (; n>0; n/=10, tens*=10) {
    int d=n%10;
    if (d==0) {
        // borrow from next higher digit: 5+5
        a+=5*tens;
        b+=5*tens;
        n-=10;  // subtract from the next digit
    } 
    else if (d==1 && n>=10) {
        // borrow from next higher digit: 6+5
        a+=6*tens;
        b+=5*tens;
        n-=10;  // subtract from the next digit
    } 
    else {
        // normal split, no borrow
        a+=(d-d/2)*tens;
        b+=(d/2)*tens;
    }
}
```
3. return `{a, b}`
4. Python code is added
5. C code is done
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(\log n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|C++ Py3 C 0ms
```cpp []
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0, b= 0, tens=1;
        for (; n>0; n/=10, tens*=10) {
            int d=n%10;
            if (d==0) {
                // borrow from next higher digit: 5+5
                a+=5*tens;
                b+=5*tens;
                n-=10;  // subtract from the next digit
            } 
            else if (d==1 && n>=10) {
                a+=6*tens;
                b+=5*tens;
                n-=10;  // borrow
            } 
            else {
                // normal split
                a+=(d-d/2)*tens;
                b+=(d/2)*tens;
            }
        }
        return {a, b};
    }
};



```
```Python []
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        a, b, tens=0, 0, 1
        while n>0:
            n, d=divmod(n, 10)
            if d==0:
                a+=5*tens
                b+=5*tens
                n-=1
            elif d==1 and n>=1:
                a+=6*tens
                b+=5*tens
                n-=1
            else:
                a+=(d-d//2)*tens
                b+=(d//2)*tens
            tens*=10

        return [a, b]
        
```
```C []
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3, unroll-loops")
int* getNoZeroIntegers(int n, int* returnSize) {
    *returnSize=2;
    int* ans=(int*)malloc(sizeof(int)*2);
    memset(ans, 0, sizeof(ans));
    for (int tens=1; n>0; n/=10, tens*=10){
        int d=n%10;
        if (d==0){
            ans[0]+=5*tens;
            ans[1]+=5*tens;
            n-=10; 
        }
        else if (d==1 && n>=10){
            ans[0]+=6*tens;
            ans[1]+=5*tens;
            n-=10;
        }
        else{
            ans[0]+=(d-d/2)*tens;
            ans[1]+=(d/2)*tens;
        }
    }
    return ans;
}
```
