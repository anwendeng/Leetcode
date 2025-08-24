<h2><a href="https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element">1493. Longest Subarray of 1's After Deleting One Element</a></h2><h3>Medium</h3><hr><p>Given a binary array <code>nums</code>, you should delete one element from it.</p>

<p>Return <em>the size of the longest non-empty subarray containing only </em><code>1</code><em>&#39;s in the resulting array</em>. Return <code>0</code> if there is no such subarray.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1&#39;s.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,1,1,0,1,1,0,1]
<strong>Output:</strong> 5
<strong>Explanation:</strong> After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1&#39;s is [1,1,1,1,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You must delete one element.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Done long ago.
Revise it to a code with mininum branches, without if, tenary.
Sliding window in one single loop.
# Approach
<!-- Describe your approach to solving the problem. -->
1. let `n=|nums|`
2. Initialize `zeros=0, ans=0`
3. Proceed the sliding window with 2 pointers `r, l` as follows
```cpp
for(int l=0, r=0; r<n; r++){// move r
    zeros+=(nums[r]==0);// increase zeros by 1 if nums[r]==0

    // decrease zeros by 1 if zeros>1 && nums[l]==0;
    // i.e. delete nums[l]
    // move l by l++
    zeros-=(zeros>1 && nums[l++]==0); 

    ans=max(ans, r-l);// update the ans by taking max with r-l
}
```
4. return `ans`
5. Add the nested loop version of sliding window for comparison.
6. Python code is added but with if-branch
# Note on std::max
`std::max` might have branch, depending on the complier. But there is a way to define custom max without branch.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code| single loop ||C++ no if 0ms
```cpp []
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int zeros=0, ans=0;
        for(int l=0, r=0; r<n; r++){
            zeros+=(nums[r]==0);
            zeros-=(zeros>1 && nums[l++]==0);
            ans=max(ans, r-l);
        }
        return ans; 
    }
};
```
```Python []
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n, l, zeros, ans=len(nums), 0, 0, 0
        for r, x in enumerate(nums):
            zeros+=(x==0)
            if zeros>1:
                zeros-=(nums[l]==0)
                l+=1
            ans=max(ans, r-l)
        return ans
            
        
```
# Code |nested loop version|C++0ms
```cpp []
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int zeros=0, ans=0;
        for(int l=0, r=0; r<n; r++){
            zeros+=(nums[r]==0);
            while(zeros>1 && nums[l++]==0){
                zeros--;
            }
            ans=max(ans, r-l);
        }
        return ans; 
    }
};
```
```Python []
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n, l, zeros, ans=len(nums), 0, 0, 0
        for r, x in enumerate(nums):
            zeros+=(x==0)
            while zeros>1:
                zeros-=nums[l]==0
                l+=1
            ans=max(ans, r-l)
        return ans
 ```           
        
# Sliding window in 1 single loop can solve [2379. Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/6510851/sliding-window-with-fixed-len-beats-100/)
[Please Turn on the english subtitles if necessary]
[https://youtu.be/bJaIasNR-Hw?si=Qz8TfB4Rzj5a4zrh](https://youtu.be/bJaIasNR-Hw?si=Qz8TfB4Rzj5a4zrh)
