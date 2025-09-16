<h2><a href="https://leetcode.com/problems/replace-non-coprime-numbers-in-array">2197. Replace Non-Coprime Numbers in Array</a></h2><h3>Hard</h3><hr><p>You are given an array of integers <code>nums</code>. Perform the following steps:</p>

<ol>
	<li>Find <strong>any</strong> two <strong>adjacent</strong> numbers in <code>nums</code> that are <strong>non-coprime</strong>.</li>
	<li>If no such numbers are found, <strong>stop</strong> the process.</li>
	<li>Otherwise, delete the two numbers and <strong>replace</strong> them with their <strong>LCM (Least Common Multiple)</strong>.</li>
	<li><strong>Repeat</strong> this process as long as you keep finding two adjacent non-coprime numbers.</li>
</ol>

<p>Return <em>the <strong>final</strong> modified array.</em> It can be shown that replacing adjacent non-coprime numbers in <strong>any</strong> arbitrary order will lead to the same result.</p>

<p>The test cases are generated such that the values in the final array are <strong>less than or equal</strong> to <code>10<sup>8</sup></code>.</p>

<p>Two values <code>x</code> and <code>y</code> are <strong>non-coprime</strong> if <code>GCD(x, y) &gt; 1</code> where <code>GCD(x, y)</code> is the <strong>Greatest Common Divisor</strong> of <code>x</code> and <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,4,3,2,7,6,2]
<strong>Output:</strong> [12,7,6]
<strong>Explanation:</strong> 
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [<strong><u>12</u></strong>,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [<strong><u>12</u></strong>,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [<strong><u>12</u></strong>,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,<u><strong>6</strong></u>].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,1,1,3,3,3]
<strong>Output:</strong> [2,1,1,3]
<strong>Explanation:</strong> 
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,<u><strong>3</strong></u>,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,<u><strong>3</strong></u>].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [<u><strong>2</strong></u>,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>The test cases are generated such that the values in the final array are <strong>less than or equal</strong> to <code>10<sup>8</sup></code>.</li>

 # Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
It's to know that $xy=\gcd(x,y)\text{lcm}(x, y)$
[This film has the English subtitles, please turn on if necessary]
[https://youtu.be/my83uM-J94U?si=WOjtkJ9gQCuAVfOf](https://youtu.be/my83uM-J94U?si=WOjtkJ9gQCuAVfOf)
Use the suitable container to implement stack holding the numbers.
3 implementations: 1 uses vector, other uses C-array, or just reuse `nums`
C implementation needs an implemenation for GCD, just use binary Euclidean algorithm to build it in the recursive way.(In fact, variants of Euclidean algorithm are important for number theory/cryptography)
**Reusing `nums` is a good idea thanks to the suggestion by @Kostiantyn Lazukin**.
Add a Python code.
# Approach
<!-- Describe your approach to solving the problem. -->
1. Define the function `lcm` by using $xy=\gcd(x,y)\text{lcm}(x, y)$; `gcd` is the builtin math function
2. Let `st` be the stack holding the numbers; it can be done in several different ways.
3. Use a nested loop to proceed like the following pseudo code
```c
for (int x : nums) {// trasverse all x in nums
    cur=x;
    while (st is not empty) {
        g=gcd(st[top], cur);
        if (g==1) break;
        cur=lcm(st[top], cur);
        st.pop();// pop 
    }
    st.push(cur);
}
```
4. The answer is the vector for `st`
5. 2 different implementations for `st` is made; 1 uses C-array+ 1variable for top, other uses vector
6. C implemenation is howeverdifferent from C++. It reuse `nums` thanks to the suggestion by @Kostiantyn Lazukin. Since there is no builtin GCD in C, let's build it in the binary Euclidean algorithm as follows
```c
int gcd(int x, int y){
    int bz=fmin(__builtin_ctz(x), __builtin_ctz(y));
    if (bz>0) return gcd(x>>bz, y>>bz)<<bz;
    int r=x%y;
    return r?gcd(y, r):y;
}
```
7. Reuse `nums`, so there is no need for mallocation; just use pointer `int* ans=nums`.
8. Since Python has gcd, lcm in math, the Python solution is super easy.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(n)$
# Code lcm+stack|elasped time 14ms~17ms
```cpp []
static int st[100000], top=-1;
class Solution {
public:
    static int lcm(int x, int y) {
        return x/gcd(x, y)*y;
    }

    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        top=-1;// reset st
        for (int x : nums) {
            int cur=x;
            while (top!=-1) {
                int g=gcd(st[top], cur);
                if (g==1) break;
                cur=lcm(st[top], cur);
                top--;// pop 
            }
            st[++top]=cur;
        }

        return vector<int>(st, st+top+1);
    }
};
```
```cpp []
class Solution {
public:
    static int lcm(int x, int y) {
        return x/gcd(x, y)*y;
    }

    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            int cur=x;
            while (st.size()) {
                int g=gcd(st.back(), cur);
                if (g==1) break;
                cur=lcm(st.back(), cur);
                st.pop_back();// pop 
            }
            st.push_back(cur);
        }

        return st;
    }
};

```
# C implementation
```C []
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3, unroll-loops")
static inline int gcd(int x, int y){
    int bz=fmin(__builtin_ctz(x), __builtin_ctz(y));
    if (bz>0) return gcd(x>>bz, y>>bz)<<bz;
    int r=x%y;
    return r?gcd(y, r):y;
}
static inline int lcm(int x, int y) {
    return x/gcd(x, y)*y;
}
static int* replaceNonCoprimes(int* nums, int n, int* returnSize) {
    int top=-1;
    for(int i=0; i<n; i++){
        int cur=nums[i];
        while(top!=-1){
            int g=gcd(nums[top], cur);
            if (g==1) break;
            cur=lcm(nums[top], cur);
            top--;
        }
        nums[++top]=cur;
    }
    int* ans=nums;
    *returnSize=top+1;
    return ans;
}
```
# C++ defines gcd & reuses nums 9ms|Py3 reuse nums
```cpp []
class Solution {
public:
    static inline int gcd(int x, int y){
        int bz=min(__builtin_ctz(x), __builtin_ctz(y));
        if (bz>0) return gcd(x>>bz, y>>bz)<<bz;
        int r=x%y;
        return r?gcd(y, r):y;
    }
    static int lcm(int x, int y) {
        return x/gcd(x, y)*y;
    }

    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        int top=-1;
        for (int x : nums) {
            int cur=x;
            while (top!=-1) {
                int g=gcd(nums[top], cur);
                if (g==1) break;
                // the following can replace by cur=nums[top]/g*cur;
                // which computes lcm directly, 
                // no need for function lcm thanks to @hj-core
                cur=lcm(nums[top], cur);
                top--;// pop 
            }
            nums[++top]=cur;
        }
        nums.resize(top+1);
        return nums;
    }
};
```
```Python []
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        top=-1
        for x in nums:
            cur=x
            while top!=-1:
                g=gcd(nums[top], cur)
                if g==1: break
                cur=nums[top]//g*cur
                top-=1
            top+=1
            nums[top]=cur
        return nums[:top+1]
        
```
</ul>
