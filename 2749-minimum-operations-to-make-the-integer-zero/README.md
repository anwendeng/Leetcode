<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/">2749. Minimum Operations to Make the Integer Zero</a></h2><h3>Medium</h3><hr><p>You are given two integers <code>num1</code> and <code>num2</code>.</p>

<p>In one operation, you can choose integer <code>i</code> in the range <code>[0, 60]</code> and subtract <code>2<sup>i</sup> + num2</code> from <code>num1</code>.</p>

<p>Return <em>the integer denoting the <strong>minimum</strong> number of operations needed to make</em> <code>num1</code> <em>equal to</em> <code>0</code>.</p>

<p>If it is impossible to make <code>num1</code> equal to <code>0</code>, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num1 = 3, num2 = -2
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make 3 equal to 0 with the following operations:
- We choose i = 2 and subtract 2<sup>2</sup> + (-2) from 3, 3 - (4 + (-2)) = 1.
- We choose i = 2 and subtract 2<sup>2</sup>&nbsp;+ (-2) from 1, 1 - (4 + (-2)) = -1.
- We choose i = 0 and subtract 2<sup>0</sup>&nbsp;+ (-2) from -1, (-1) - (1 + (-2)) = 0.
It can be proven, that 3 is the minimum number of operations that we need to perform.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num1 = 5, num2 = 7
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be proven, that it is impossible to make 5 equal to 0 with the given operation.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1 &lt;= 10<sup>9</sup></code></li>
	<li><code><font face="monospace">-10<sup>9</sup>&nbsp;&lt;= num2 &lt;= 10<sup>9</sup></font></code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
If `num2`=0, it's very easy to finish in O(1) time, & just return `bitcount(num2)` otherwise follow the hint to iterate at most 60 times to count bits what remains after successive subtractions by `num2`.
[Please turn on the English subtitles if necessary]
[https://youtu.be/TGWzwzBrJFM?si=b1OxuPSkQJ_M_65H](https://youtu.be/TGWzwzBrJFM?si=b1OxuPSkQJ_M_65H)
# Approach
<!-- Describe your approach to solving the problem. -->
1. Special case for `num2=0` return `bitcount(num2)`
2. Initialize `x=num1` as `long long`; for setting `int`, it will overflow for some testcases
3. To obtain 0 by taking min operations k times $\iff$ it satisfies the following 2 conditions:
    - the remaining `x>=k`; if `x<k` there are too few 1s
    - the  bits in `x` is `<=k`
4. According to this fact to iterate at most 60 times 
```cpp
for(int k=1; k<61; k++){
    x-=num2;// in fact x=num1-k*num1
    if (x<k) return -1;// too few 1s
    if (x>=0 && k>=popcount((unsigned long long)(x))) //x>=0 is checked, for the case num2<0
        return k;
}
```
5. when the loop is through, return -1
6. Python code integrates the num2==0 into the loop
7. Instead of for-loop, use a conditional while loop which does not lead to a infinite loop.
8. C code is added
9. Add Rust
# Real Run for some testcases
Consider the testcase `112577768
-501662198` the process for the code
```
k=1 x=614239966 bitcount(x)=16
k=2 x=1115902164 bitcount(x)=11
k=3 x=1617564362 bitcount(x)=12
k=4 x=2119226560 bitcount(x)=14
k=5 x=2620888758 bitcount(x)=18
k=6 x=3122550956 bitcount(x)=16
k=7 x=3624213154 bitcount(x)=12
k=8 x=4125875352 bitcount(x)=20
k=9 x=4627537550 bitcount(x)=17
k=10 x=5129199748 bitcount(x)=13
k=11 x=5630861946 bitcount(x)=15
k=12 x=6132524144 bitcount(x)=16
k=13 x=6634186342 bitcount(x)=18
k=14 x=7135848540 bitcount(x)=15
k=15 x=7637510738 bitcount(x)=17
k=16 x=8139172936 bitcount(x)=15
```
Consider the custom testcase `num1=268435455 num2=-536870912`, in fact  `num1`=$2^{28}-1$ `num2=`$-2^{29}$ . The procees is as follows:
```
k=1 x=805306367 bitcount(x)=29
k=2 x=1342177279 bitcount(x)=29
k=3 x=1879048191 bitcount(x)=30
k=4 x=2415919103 bitcount(x)=29
k=5 x=2952790015 bitcount(x)=30
k=6 x=3489660927 bitcount(x)=30
k=7 x=4026531839 bitcount(x)=31
k=8 x=4563402751 bitcount(x)=29
k=9 x=5100273663 bitcount(x)=30
k=10 x=5637144575 bitcount(x)=30
k=11 x=6174015487 bitcount(x)=31
k=12 x=6710886399 bitcount(x)=30
k=13 x=7247757311 bitcount(x)=31
k=14 x=7784628223 bitcount(x)=31
k=15 x=8321499135 bitcount(x)=32
k=16 x=8858370047 bitcount(x)=29
k=17 x=9395240959 bitcount(x)=30
k=18 x=9932111871 bitcount(x)=30
k=19 x=10468982783 bitcount(x)=31
k=20 x=11005853695 bitcount(x)=30
k=21 x=11542724607 bitcount(x)=31
k=22 x=12079595519 bitcount(x)=31
k=23 x=12616466431 bitcount(x)=32
k=24 x=13153337343 bitcount(x)=30
k=25 x=13690208255 bitcount(x)=31
k=26 x=14227079167 bitcount(x)=31
k=27 x=14763950079 bitcount(x)=32
k=28 x=15300820991 bitcount(x)=31
k=29 x=15837691903 bitcount(x)=32
k=30 x=16374562815 bitcount(x)=32
k=31 x=16911433727 bitcount(x)=33
k=32 x=17448304639 bitcount(x)=29
```
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(60)$ To be more precisely. 
    1. num2=0: $O(1)$
    2. num2>0: $O(num1/num2)$
    3. num2<0: $O(60)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|C++ 0ms|Py3 0ms|C 0ms|Rust 0ms
```cpp []
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num2==0) return popcount(unsigned(num1));
        long long x=num1;
        for(int k=1; k<61; k++){
            x-=num2;
            if (x<k) return -1;
            if (x>=0 && k>=popcount((unsigned long long)(x))) return k;
        }
        return -1;
    }
};
```
```Python []
class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        x, k=num1, 1
        while True:
            x-=num2
            if x<k: return -1
            if k>=x.bit_count():
                return k
            k+=1
        return -1

        
```
```C []
#pragma GCC optimize("O3, unroll-loops")
int makeTheIntegerZero(int num1, int num2) {
    long long x=num1;
    for(int k=1; ;k++){
        x-=num2;
        if (x<k) return -1;
        if (k>=__builtin_popcountll(x))
            return k;
    }
    return -1;
}
```
```Rust []
impl Solution {
    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {
        let mut x:i64=num1 as i64;
        for k in 1..61{
            x-=num2 as i64;
            if x<k { return -1}
            if k>=x.count_ones() as i64{
                return k as i32
            }
        }
        -1
    }
}
```
# Notes on num2<0 & k is finite
It's to mention that $x=num1-k(num2)$ grows linear, & $bitcount(x)$ has logarithmic growth, but with an error term $O(bitcount(-num2))$. These two will meet somewhere, say $k_0$ which is for sure $k_0<\infty$. The sharp upperbound for $k_0$ needs some more math consideration which is far beyond the scope.
