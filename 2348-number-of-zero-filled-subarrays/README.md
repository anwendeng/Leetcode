<h2><a href="https://leetcode.com/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-19">2348. Number of Zero-Filled Subarrays</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code>, return <em>the number of <strong>subarrays</strong> filled with </em><code>0</code>.</p>

<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,0,0,2,0,0,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,0,0,2,0,0]
<strong>Output:</strong> 9
<strong>Explanation:
</strong>There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,10,2019]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no subarray filled with 0. Therefore, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Done long ago. 

Let's begin with the very case for nums=[0,0,0,0].
There are 4 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There are 2 occurrence of [0,0,0] as a subarray.
There is 1 occurrence of [0,0,0,0 ] as a subarray.
4+3+2+1=4*(4+1)/2=10

In a similar way, when nums is filled with N times 0, it is not hard to conclude that there are exactly N*(N+1)/2 subarrays filled with 0.

[LC. 605. Please turn on English subtitles if necessary]
[![影片縮圖](https://img.youtube.com/vi/0TLqEanwcV0/0.jpg)](https://www.youtube.com/watch?v=0TLqEanwcV0)
(https://www.youtube.com/watch?v=0TLqEanwcV0)
I also used the similar idea to solve the problem "can-place-flowers"!
https://leetcode.com/problems/can-place-flowers/solutions/7097087/nn120ms-by-anwendeng-jglu/)

# Approach
<!-- Describe your approach to solving the problem. -->
To reduce the if-branch, 1 is appended to the array nums.
Use the loop to find out the lengths N's of  maximal subarrays filling with 0. Then use the formula N*(N+1)/2 to sum up.

Add a new C++ by using 2-pointer method also the formula
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code
```cpp []
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(1);
        const int s=nums.size();
        int a_len=0 , prev=1;
        long long sum=0;
        for (int i=0; i<s; i++){
            if (nums[i]==0){
                 a_len++;
                 prev=0;
            }     
            else if (prev==0)
            {
                sum+=(long long)a_len*(a_len+1)/2;
                a_len=0;
                prev=nums[i];
            }
        }
        return sum;
    }
};
```
# 2nd Approach||C++ 0ms
```
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        const int n=nums.size();
        long long sum=0, a_len=0;
        for (int l=0, r=0; l<n; ){
            if (nums[l]!=0){
                l++;
                continue;
            }
            for(r=l; r<n && nums[r]==0; r++);
            a_len=(r-l);
            sum+=(a_len+1LL)*a_len/2;
            l=r;
        }
        return sum;
    }
};
```
