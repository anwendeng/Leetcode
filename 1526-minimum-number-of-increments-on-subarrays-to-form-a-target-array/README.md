<h2><a href="https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/?envType=daily-question&envId=2025-10-30">1526. Minimum Number of Increments on Subarrays to Form a Target Array</a></h2><h3>Hard</h3><hr><p>You are given an integer array <code>target</code>. You have an integer array <code>initial</code> of the same size as <code>target</code> with all elements initially zeros.</p>

<p>In one operation you can choose <strong>any</strong> subarray from <code>initial</code> and increment each value by one.</p>

<p>Return <em>the minimum number of operations to form a </em><code>target</code><em> array from </em><code>initial</code>.</p>

<p>The test cases are generated so that the answer fits in a 32-bit integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> target = [1,2,3,2,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We need at least 3 operations to form the target array from the initial array.
[<strong><u>0,0,0,0,0</u></strong>] increment 1 from index 0 to 4 (inclusive).
[1,<strong><u>1,1,1</u></strong>,1] increment 1 from index 1 to 3 (inclusive).
[1,2,<strong><u>2</u></strong>,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> target = [3,1,1,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> [<strong><u>0,0,0,0</u></strong>] -&gt; [1,1,1,<strong><u>1</u></strong>] -&gt; [<strong><u>1</u></strong>,1,1,2] -&gt; [<strong><u>2</u></strong>,1,1,2] -&gt; [3,1,1,2]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> target = [3,1,5,4,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> [<strong><u>0,0,0,0,0</u></strong>] -&gt; [<strong><u>1</u></strong>,1,1,1,1] -&gt; [<strong><u>2</u></strong>,1,1,1,1] -&gt; [3,1,<strong><u>1,1,1</u></strong>] -&gt; [3,1,<strong><u>2,2</u></strong>,2] -&gt; [3,1,<strong><u>3,3</u></strong>,2] -&gt; [3,1,<strong><u>4</u></strong>,4,2] -&gt; [3,1,5,4,2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= target[i] &lt;= 10<sup>5</sup></code></li>
</ul>


# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The question can be easily solved by the following formula:
$$
ans=t[0]+\sum_{i>0}\max(t[i]-t[i-1], 0)
$$
[Explain how to write the codes; please turn on the English subtitles  if necessary]
[https://youtu.be/kdrpAkBczq0?si=i8-WpH8qipIcl9mC](https://youtu.be/kdrpAkBczq0?si=i8-WpH8qipIcl9mC)
# Approach
<!-- Describe your approach to solving the problem. -->
Several solutions.
1. the 1st one uses `adjacent_difference` to convert `target=[t[i] for i]` to the array `[t[0], t[1]-t[0], ...., t[i]-t[i-1],...,t[n-1]-t[n-2]]`
2. Then apply `accumulate` to the array with the lamba `[](int sum, int x){ return sum+=max(0,x);}`
3. 2nd solution is the easy loop version which is a 1-pass solution.
4. The 2nd C++ is the direct implementation of the formula given above
5. Add a Python 1-liner
6. Add a C code
7. Add a Java code
8. Add a Rust code
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code adjacent_difference+accumulate|0ms
```cpp []
class Solution {
public:
    static int minNumberOperations(vector<int>& target) {
        adjacent_difference(target.begin(), target.end(), target.begin());
        return accumulate(target.begin(), target.end(), 0,
        [](int sum, int x){ return sum+=max(0,x);});
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
```
# 1 pass|C/C++0ms|Java 3ms|Rust 0ms
```Rust []
impl Solution {
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        let n=target.len();
        let mut ans=target[0];
        for i in 1..n{
            ans+=(target[i]-target[i-1]).max(0);
        }
        ans
    }
}
```
```C []
#pragma GCC optimize("O3, unroll-loops")
int minNumberOperations(int* target, int n) {
    int ans=target[0];
    for(int i=1; i<n; i++){
        ans+=fmax(target[i]-target[i-1], 0);
    }
    return ans;
}
```
```cpp []
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size(), ans=target[0];
        for(int i=1; i<n; i++){
            ans+=max(target[i]-target[i-1], 0);
        }
        return ans;
    }
};

```
```Java []
class Solution {
    public int minNumberOperations(int[] target) {
        final int n=target.length;
        int ans=target[0];
        for(int i=1; i<n; i++)
            ans+=Math.max(target[i]-target[i-1], 0);
        return ans;
    }
}
```
# Python 1-liner
```Python []
class Solution:
    def minNumberOperations(self, t: List[int]) -> int:
        return t[0]+sum(max(x-y, 0) for x, y in zip(t[1:], t))
```
