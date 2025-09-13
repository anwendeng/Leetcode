<h2><a href="https://leetcode.com/problems/find-most-frequent-vowel-and-consonant">3541. Find Most Frequent Vowel and Consonant</a></h2><h3>Easy</h3><hr><p>You are given a string <code>s</code> consisting of lowercase English letters (<code>&#39;a&#39;</code> to <code>&#39;z&#39;</code>). </p>

<p>Your task is to:</p>

<ul>
	<li>Find the vowel (one of <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, or <code>&#39;u&#39;</code>) with the <strong>maximum</strong> frequency.</li>
	<li>Find the consonant (all other letters excluding vowels) with the <strong>maximum</strong> frequency.</li>
</ul>

<p>Return the sum of the two frequencies.</p>

<p><strong>Note</strong>: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.</p>
The <strong>frequency</strong> of a letter <code>x</code> is the number of times it occurs in the string.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;successes&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The vowels are: <code>&#39;u&#39;</code> (frequency 1), <code>&#39;e&#39;</code> (frequency 2). The maximum frequency is 2.</li>
	<li>The consonants are: <code>&#39;s&#39;</code> (frequency 4), <code>&#39;c&#39;</code> (frequency 2). The maximum frequency is 4.</li>
	<li>The output is <code>2 + 4 = 6</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aeiaeia&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The vowels are: <code>&#39;a&#39;</code> (frequency 3), <code>&#39;e&#39;</code> ( frequency 2), <code>&#39;i&#39;</code> (frequency 2). The maximum frequency is 3.</li>
	<li>There are no consonants in <code>s</code>. Hence, maximum consonant frequency = 0.</li>
	<li>The output is <code>3 + 0 = 3</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>


# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Revise the old code without using if.
Use vowel mask again. Count freq
# Approach
<!-- Describe your approach to solving the problem. -->
1. let the array `freq[26]={0}` be given initially
2. count `freq` by a loop
3. let ` mask=1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'))` be given which runs in the compiling time.
4. declare `maxCV[2]={0}` where maxCV[0] for consonant maxCV[1] for vowel to avoid the if-branch in the following loop
5. for i=0 to 25 do the following:
```cpp
const bool idx=((1<<i) & mask)!=0;
maxCV[idx]=max(maxCV[idx], freq[i]);
```
6. The answer is `maxCV[0]+maxCV[1]`
7.  2nd variant reorganizes the code in 1 single loop.
8.  Add a Python code

Vowel mask method can solve also other LC's questions, in fact many [LC 3136. Valid Word](https://leetcode.com/problems/valid-word/solutions/6959558/bitmask-for-vowel-bitset-beats-100/)
[https://youtu.be/G3wTKtkRZFI?si=NG-SYVul9gLNcONR](https://youtu.be/G3wTKtkRZFI?si=NG-SYVul9gLNcONR)
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n+26)\to O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(26)$
# Code |C++ 0ms
```cpp []
class Solution {
public:
    int maxFreqSum(string& s) {
        int freq[26]={0};
        for(char c: s)
            freq[c-'a']++;
        constexpr unsigned mask=1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
    //    cout<<hex<<mask<<endl;
        int maxCV[2]={0};// [0] for consonant [1] for vowel
        for(int i=0; i<26; i++){
            const bool idx=((1<<i) & mask)!=0;
            maxCV[idx]=max(maxCV[idx], freq[i]);
        }
        return maxCV[0]+maxCV[1];
    }
};
```
```Python []
class Solution:
    def maxFreqSum(self, s: str) -> int:
        freq=Counter(s)
        maxCV=[0]*2
        for i, f in freq.items():
            idx=((1<<(ord(i)-97)) & 0x104111)!=0
            maxCV[idx]=max(maxCV[idx], f)
        return maxCV[0]+maxCV[1]
        
        
```
# 2nd variant 1 single loop|0ms
```cpp []
class Solution {
public:
    int maxFreqSum(string& s) {
        constexpr unsigned mask=1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
        int maxCV[2]={0};// [0] for consonant [1] for vowel
        int freq[26]={0};
        for(char c: s){
            const int x=c-'a';
            const bool idx=((1<<x) & mask)!=0;
            maxCV[idx]=max(maxCV[idx], ++freq[x]);
        }
        return maxCV[0]+maxCV[1];
    }
};
```
```Python []
class Solution:
    def maxFreqSum(self, s: str) -> int:
        mask=0x104111
        maxCV=[0]*2
        freq=[0]*26
        for c in s:
            x=ord(c)-97
            idx=((1<<x) & mask)!=0
            freq[x]+=1
            maxCV[idx]=max(maxCV[idx], freq[x])
        return maxCV[0]+maxCV[1]
        
```
