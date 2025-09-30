<h2><a href="https://leetcode.com/problems/find-triangular-sum-of-an-array">2221. Find Triangular Sum of an Array</a></h2><h3>Medium</h3><hr><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>, where <code>nums[i]</code> is a digit between <code>0</code> and <code>9</code> (<strong>inclusive</strong>).</p>

<p>The <strong>triangular sum</strong> of <code>nums</code> is the value of the only element present in <code>nums</code> after the following process terminates:</p>

<ol>
	<li>Let <code>nums</code> comprise of <code>n</code> elements. If <code>n == 1</code>, <strong>end</strong> the process. Otherwise, <strong>create</strong> a new <strong>0-indexed</strong> integer array <code>newNums</code> of length <code>n - 1</code>.</li>
	<li>For each index <code>i</code>, where <code>0 &lt;= i &lt;&nbsp;n - 1</code>, <strong>assign</strong> the value of <code>newNums[i]</code> as <code>(nums[i] + nums[i+1]) % 10</code>, where <code>%</code> denotes modulo operator.</li>
	<li><strong>Replace</strong> the array <code>nums</code> with <code>newNums</code>.</li>
	<li><strong>Repeat</strong> the entire process starting from step 1.</li>
</ol>

<p>Return <em>the triangular sum of</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/22/ex1drawio.png" style="width: 250px; height: 250px;" />
<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong>
The above diagram depicts the process from which we obtain the triangular sum of the array.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
Since there is only one element in nums, the triangular sum is the value of that element itself.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Provide 2 solutions: 1 is $O(n^2)$ which is very easy just following the description. Other is using the following fact
$$
ans=\sum_{i=0}^{n-1}C_i^{n-1}nums[i] \pmod{10}
$$
Let's focus on the 2nd one.
It's to mention that 10 is not a prime; the modular arithmetic for that needs real task.
[The following film discusses the implementation for the hard one in detail, please turn on the English subtitles if necessary]
[https://youtu.be/4nvaOcMLY58?si=phvDIiKyZZMQILVQ](https://youtu.be/4nvaOcMLY58?si=phvDIiKyZZMQILVQ)
This approach can compute `nums` for any int not just the digits. Add a Python code without using mod 10 arithmetic
# Approach
<!-- Describe your approach to solving the problem. -->
![2221Pascal.png](https://assets.leetcode.com/users/images/66754cf2-50c6-4ce2-9536-6e20d5ff73cb_1759191137.0080855.png)
1. The integer among [0, 9] there are only the numbers 1,3,7,9 having modular inverses mod 9. Build an global array `static array<int, 10> inv{}` where `inv[1]=1, inv[3]=7, inv[7]=3, inv[9]=9;`
2. Define the function ` factor(unsigned x)` to factor x to $x=2^{e_2}5^{e_5}y$ where $y$ is coprime to 10; $y$ has mod inverse mod 10; the returning tuple is `(e2, e5, y)`
3. Define `int3 mul(const int3& x, const int3& y)` as the multiplication for the factorization tuples x & y by `(x[0]+y[0], x[1]+y[1], x[2]*y[2]%10)`
4. Define `int3 div(const int3& x, const int3& y)` as the division for the factorization tuples x& y by `(x[0]-y[0], x[1]-y[1], x[2]*inv[y[2]]%10)`
5. Define `int Pow(int b, int exp)` in a recursive fast way.
6. Define `int toInt(const int3& x)` which converts the factorization to its product
7. Compute the combinatorial number $C_i^n$ for i=0,...,n in $O(n)$ as follows (which is in fact using the same recurrence in solving[119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/solutions/4173219/0ms-beats-100-easy-c-pascal-using-2-term-recurrence-formula/))
```cpp
static vector<int> Comb(int n){
    vector<int3> a(n+1, {0, 0, 0});// a=the array over tuples 
    vector<int> A(n+1); // A is int array
    a[0]=a[n]={0, 0, 1}; 
    A[0]=A[n]=1;
    for(int k=1; k<=n/2; k++){
        // do the mod 10  arithmetic 
        a[k]=a[n-k]=div(mul(a[k-1], factor(n-k+1)), factor(k));
        A[k]=A[n-k]=toInt(a[k]);// convert to its product
    }
    return  A;
}
```
8. In `int triangularSum(vector<int>& nums)` let `n=|nums|-1`
9. apply `inv_mod10()`
10. Let `A=Comb(n)`
11. Proceed the following loop to finish the job:
```cpp
for(int i=0; i<=n; i++){
    ans=(ans+A[i]*nums[i])%10;
}
return ans;
```
12. Python support very long int; it doesn't use mod 10 arithmetic, the code is fairly easy.
13. Use a variant for `toInt(const int3& x)` which can remove `Pow`
```cpp
static int toInt(const int3& x){// use only for binomial coeff
    if (x[0]>0 && x[1]>0) return 0;// x already has 10 as a factor
    if (x[1]>0) return  5*x[2]%10;// x has no factor 2, but 5
    return  (x[2]<<x[0])%10; // x has no factor 5
}
```
14. the variant C++ is slightly optimized for dealing only with digits
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n)$ 
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(n)$
# Code| fast solution |0ms
```cpp []
// this variant version removes Pow
// & redefines int toInt(const int3& x) 
static array<int, 10> inv{};
class Solution {
public:
    //(exponent 2, exponent 5, factor coprime to 2, 5 mod 10)
    using int3=array<int, 3>; 
    static void inv_mod10(){
        if (inv[1]==1) return;
        inv[1]=1, inv[3]=7, inv[7]=3, inv[9]=9;
    }
    static int3 factor(unsigned x){
        int exp2=countr_zero(x);
        x>>=exp2;
        int exp5=0;
        for (;x%5==0; x/=5) exp5++;
        x%=10;
        return {exp2, exp5, int(x)};
    }
    static int3 mul(const int3& x, const int3& y){
        return {x[0]+y[0], x[1]+y[1], x[2]*y[2]%10};
    }
    static int3 div(const int3& x, const int3& y){
        return {x[0]-y[0], x[1]-y[1], x[2]*inv[y[2]]%10};
    }
    static int toInt(const int3& x){
        if (x[0]>0 && x[1]>0) return 0;
        if (x[1]>0) return  5*x[2]%10;
        return  (x[2]<<x[0])%10;
    }
    static vector<int> Comb(int n){
        vector<int3> a(n+1, {0, 0, 0});
        vector<int> A(n+1);
        a[0]=a[n]={0, 0, 1};
        A[0]=A[n]=1;
        for(int k=1; k<=n/2; k++){
            a[k]=a[n-k]=div(mul(a[k-1], factor(n-k+1)), factor(k));
            A[k]=A[n-k]=toInt(a[k]);
        }
        return  A;
    }
    static int triangularSum(vector<int>& nums) {
        const int n=nums.size()-1;
        inv_mod10();
        auto A=Comb(n);
        int ans=0;
        for(int i=0; i<=n; i++){
            ans=(ans+A[i]*nums[i])%10;
        }
        return ans;
    }
};
```
```cpp []
static array<int, 10> inv{};
class Solution {
public:
    //(exponent 2, exponent 5, factor coprime to 2, 5 mod 10)
    using int3=array<int, 3>; 
    static void inv_mod10(){
        if (inv[1]==1) return;
        inv[1]=1, inv[3]=7, inv[7]=3, inv[9]=9;
    }
    static int3 factor(unsigned x){
        int exp2=countr_zero(x);
        x>>=exp2;
        int exp5=0;
        for (;x%5==0; x/=5) exp5++;
        x%=10;
        return {exp2, exp5, int(x)};
    }
    static int3 mul(const int3& x, const int3& y){
        return {x[0]+y[0], x[1]+y[1], x[2]*y[2]%10};
    }
    static int3 div(const int3& x, const int3& y){
        return {x[0]-y[0], x[1]-y[1], x[2]*inv[y[2]]%10};
    }
    static int Pow(int b, int exp){
        if(exp==0) return 1;
        int y=(exp&1)?b:1;
        return Pow(b*b, exp>>1)*y;
    }
    static int toInt(const int3& x){
        return (Pow(5, x[1])<<x[0])*x[2]%10;
    }
    static vector<int> Comb(int n){
        vector<int3> a(n+1, {0, 0, 0});
        vector<int> A(n+1);
        a[0]=a[n]={0, 0, 1};
        A[0]=A[n]=1;
        for(int k=1; k<=n/2; k++){
            a[k]=a[n-k]=div(mul(a[k-1], factor(n-k+1)), factor(k));
            A[k]=A[n-k]=toInt(a[k]);
        }
        return  A;
    }
    static int triangularSum(vector<int>& nums) {
        const int n=nums.size()-1;
        inv_mod10();
        auto A=Comb(n);
        int ans=0;
        for(int i=0; i<=n; i++){
            ans=(ans+A[i]*nums[i])%10;
        }
        return ans;
    }
};
```
# C++ O(n^2) solution|50ms
```
class Solution {
public:
    int triangularSum(vector<int>& nums) {
       int n=nums.size();
       for (int i=n-1; i>=1; i--){
           for(int j=0; j<i; j++){
               nums[j]=(nums[j]+nums[j+1])%10;
           }
       }
       return nums[0]; 
    }
};
```
# Python using Pascal's triangle|18ms
```
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n=len(nums)-1
        ans, A=nums[0], 1
        for k in range(1, n+1):
            A=A*(n-k+1)//k
            ans=(ans+nums[k]*A)%10
        return ans
        
```
