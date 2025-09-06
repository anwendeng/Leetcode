<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero">3495. Minimum Operations to Make Array Elements Zero</a></h2><h3>Hard</h3><hr><p>You are given a 2D array <code>queries</code>, where <code>queries[i]</code> is of the form <code>[l, r]</code>. Each <code>queries[i]</code> defines an array of integers <code>nums</code> consisting of elements ranging from <code>l</code> to <code>r</code>, both <strong>inclusive</strong>.</p>

<p>In one operation, you can:</p>

<ul>
	<li>Select two integers <code>a</code> and <code>b</code> from the array.</li>
	<li>Replace them with <code>floor(a / 4)</code> and <code>floor(b / 4)</code>.</li>
</ul>

<p>Your task is to determine the <strong>minimum</strong> number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">queries = [[1,2],[2,4]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>For <code>queries[0]</code>:</p>

<ul>
	<li>The initial array is <code>nums = [1, 2]</code>.</li>
	<li>In the first operation, select <code>nums[0]</code> and <code>nums[1]</code>. The array becomes <code>[0, 0]</code>.</li>
	<li>The minimum number of operations required is 1.</li>
</ul>

<p>For <code>queries[1]</code>:</p>

<ul>
	<li>The initial array is <code>nums = [2, 3, 4]</code>.</li>
	<li>In the first operation, select <code>nums[0]</code> and <code>nums[2]</code>. The array becomes <code>[0, 3, 1]</code>.</li>
	<li>In the second operation, select <code>nums[1]</code> and <code>nums[2]</code>. The array becomes <code>[0, 0, 0]</code>.</li>
	<li>The minimum number of operations required is 2.</li>
</ul>

<p>The output is <code>1 + 2 = 3</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">queries = [[2,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>For <code>queries[0]</code>:</p>

<ul>
	<li>The initial array is <code>nums = [2, 3, 4, 5, 6]</code>.</li>
	<li>In the first operation, select <code>nums[0]</code> and <code>nums[3]</code>. The array becomes <code>[0, 3, 4, 1, 6]</code>.</li>
	<li>In the second operation, select <code>nums[2]</code> and <code>nums[4]</code>. The array becomes <code>[0, 3, 1, 1, 1]</code>.</li>
	<li>In the third operation, select <code>nums[1]</code> and <code>nums[2]</code>. The array becomes <code>[0, 0, 0, 1, 1]</code>.</li>
	<li>In the fourth operation, select <code>nums[3]</code> and <code>nums[4]</code>. The array becomes <code>[0, 0, 0, 0, 0]</code>.</li>
	<li>The minimum number of operations required is 4.</li>
</ul>

<p>The output is 4.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>queries[i] == [l, r]</code></li>
	<li><code>1 &lt;= l &lt; r &lt;= 10<sup>9</sup></code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Use Math recurrence to solve.
It's good to know that $\lfloor \log_4(x)\rfloor=$`(31-countl_zero(x))/2`
Count firstly the summation  of exponent+1 of base 4 for each x in `[1...4^i]` where i=0,...,17. i.e.
$$
expSum4[i]=expSum(4^i) \quad \text{ where}\\
expSum(x)=\sum_{i=1}^x(\lfloor \log_4(x)\rfloor+1)
$$
The other is easy to find its corresponding summation  of exponent+1 of base 4, that is
[Please turn on the English subtiles if necessary]
[https://youtu.be/O4k1UL7G9RY?si=km5r7pMD5tSuv1Qw](https://youtu.be/O4k1UL7G9RY?si=km5r7pMD5tSuv1Qw)
# Approach
<!-- Describe your approach to solving the problem. -->
1. Declare the array `expSum4[18]={1}`
2. Define the function `long long expSum(unsigned x)` to compute the corresponding summation  of exponent+1 of base 4; this function uses the following equation to compute:
$$
expSum(x)=expSum4[\lfloor \log_4(x)\rfloor]+r(\lfloor \log_4(x)\rfloor+1)
$$ 
where $r=x-4^{\lfloor \log_4(x)\rfloor}$
3. In the function `long long minOperations(vector<vector<int>>& queries)` compute `expSum4[i]`  the summation  of exponent+1 of base 4 for each x in `[1...4^i]` where i=0,...,17 in a loop; use the followingformula to compute:
$$
expSum4[i]=expSum4[i-1]+3\times i \times (4^{i-1})+1
$$
4. let `op=0`
5. Use a loop to proceed `op+=(expSum(r)-expSum(l)+1)/2;` for `l+1, r in queries`
6. `op` is the answer.
7. C code is made in the same way which beats 100%.
8. Py3 code is made which beats 100%
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(18)$$
# Code||C++ 0ms beats 100%|Py3 155ms 100%|C beats 100%
```cpp []
// this version computes expSum4[] only once by suggestion of @Sergei
long long expSum4[18]={0};
class Solution {
public:
    static long long expSum(unsigned x){
        if (x==0) return 0;
        int log4=(31-countl_zero(x))/2;
        int r=x-(1<<(2*log4));
        return expSum4[log4]+r*(log4+1LL);
    }
    static void precompute(){
        if (expSum4[0]==1) return;
        expSum4[0]=1;
        for(int i=1; i<18; i++){
            expSum4[i]=expSum4[i-1]+3LL*i*(1LL<<(2*(i-1)))+1;
        //    cout<<i<<"->"<<expSum4[i]<<", ";
        }
    }
    static long long minOperations(vector<vector<int>>& queries) {
        precompute();
        long long op=0;
        for(auto& q: queries){
            int l=q[0]-1, r=q[1];
            op+=(expSum(r)-expSum(l)+1)/2;// ceiling of (expSum(r)-expSum(l))/2
        }
        return op;
    }
};
```
```cpp []
class Solution {
public:
    long long expSum4[18]={1};
    long long expSum(unsigned x){
        if (x==0) return 0;
        int log4=(31-countl_zero(x))/2;
        int r=x-(1<<(2*log4));
        return expSum4[log4]+r*(log4+1LL);
    }
    long long minOperations(vector<vector<int>>& queries) {
        for(int i=1; i<18; i++){
            expSum4[i]=expSum4[i-1]+3LL*i*(1LL<<(2*(i-1)))+1;
        //    cout<<i<<"->"<<expSum4[i]<<", ";
        }
        long long op=0;
        for(auto& q: queries){
            int l=q[0]-1, r=q[1];
            op+=(expSum(r)-expSum(l)+1)/2;// ceiling of (expSum(r)-expSum(l))/2
        }
        return op;
    }
};
```
```Python []
class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        expSum4=[1]+[0]*17
        def expSum(x):
            if x==0: return 0
            log4=(x.bit_length()-1)>>1
            r=x-(1<<(log4<<1))
            return expSum4[log4]+r*(log4+1)
        for i in range(1,18):
            expSum4[i]=expSum4[i-1]+3*i*(1<<(2*(i-1)))+1
        op=0
        for l1, r in queries:
            op+=(expSum(r)-expSum(l1-1)+1)>>1

        return op
```
```C []
#pragma GCC optimize("O3, unroll-loops")
static long long expSum4[18]={1};
static long long expSum(unsigned x){
    if (x==0) return 0;
    int log4=(31-__builtin_clz(x))/2;
    int r=x-(1<<(2*log4));
    return expSum4[log4]+r*(log4+1LL);
}

static long long minOperations(int** queries, int qz, int* queriesColSize) {
    for(int i=1; i<18; i++){
        expSum4[i]=expSum4[i-1]+3LL*i*(1LL<<(2*(i-1)))+1;
    }
    long long op=0;
    for(int i=0; i<qz; i++){
        const int* q=queries[i];
        int l=q[0]-1, r=q[1];
        op+=(expSum(r)-expSum(l)+1)/2;// ceiling of (expSum(r)-expSum(l))/2
    }
    return op;
    
}
```
