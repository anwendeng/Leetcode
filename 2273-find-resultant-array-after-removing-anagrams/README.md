<h2><a href="https://leetcode.com/problems/find-resultant-array-after-removing-anagrams">2273. Find Resultant Array After Removing Anagrams</a></h2><h3>Easy</h3><hr><p>You are given a <strong>0-indexed</strong> string array <code>words</code>, where <code>words[i]</code> consists of lowercase English letters.</p>

<p>In one operation, select any index <code>i</code> such that <code>0 &lt; i &lt; words.length</code> and <code>words[i - 1]</code> and <code>words[i]</code> are <strong>anagrams</strong>, and <strong>delete</strong> <code>words[i]</code> from <code>words</code>. Keep performing this operation as long as you can select an index that satisfies the conditions.</p>

<p>Return <code>words</code> <em>after performing all operations</em>. It can be shown that selecting the indices for each operation in <strong>any</strong> arbitrary order will lead to the same result.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, <code>&quot;dacb&quot;</code> is an anagram of <code>&quot;abdc&quot;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abba&quot;,&quot;baba&quot;,&quot;bbaa&quot;,&quot;cd&quot;,&quot;cd&quot;]
<strong>Output:</strong> [&quot;abba&quot;,&quot;cd&quot;]
<strong>Explanation:</strong>
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = &quot;bbaa&quot; and words[1] = &quot;baba&quot; are anagrams, we choose index 2 and delete words[2].
  Now words = [&quot;abba&quot;,&quot;baba&quot;,&quot;cd&quot;,&quot;cd&quot;].
- Since words[1] = &quot;baba&quot; and words[0] = &quot;abba&quot; are anagrams, we choose index 1 and delete words[1].
  Now words = [&quot;abba&quot;,&quot;cd&quot;,&quot;cd&quot;].
- Since words[2] = &quot;cd&quot; and words[1] = &quot;cd&quot; are anagrams, we choose index 2 and delete words[2].
  Now words = [&quot;abba&quot;,&quot;cd&quot;].
We can no longer perform any operations, so [&quot;abba&quot;,&quot;cd&quot;] is the final answer.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;,&quot;d&quot;,&quot;e&quot;]
<strong>Output:</strong> [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;,&quot;d&quot;,&quot;e&quot;]
<strong>Explanation:</strong>
No two adjacent strings in words are anagrams of each other, so no operations are performed.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Done before, modify the code & submit.
Use the following fact to solve.
`s` is an  Anagram of `t` $\iff$ `freq(s)=freq(t)`
[The following film shows how to use bitmask + 2-pointer to implement a Python code; please turn on the English subtiles if necessary]
[https://youtu.be/eQO89LrR8Bg?si=oEdM2pmcKzGh2MYc](https://youtu.be/eQO89LrR8Bg?si=oEdM2pmcKzGh2MYc)

# Approach
<!-- Describe your approach to solving the problem. -->
1. define the function `array<int, 26> freq(string& s)` to count the alphabet frequencies.
2. In `vector<string> removeAnagrams(vector<string>& words)` let `n=|words|`,  let `l=0, r=1` be the 2 pointers.
3. Initialize `vector<string> ans={words[0]}`
4. let `array<int, 26> f0=freq(words[0]))`
5. Use 1-loop as follows
```cpp
for( ; r<n; r++){// move r 
    string s=words[r]; // let s=wrod[r]
    auto x=move(freq(s)); // let x=freq(s)
    if (f0!=x){ // if f0 != x
        ans.push_back(s); // add s to ans
        l=r; //move l to r
        f0=x; // set f0=x
    }
}
```
6. return `ans`
7. Since Sergei & Kostiantyn Lazukin have mentioned their solutions, considering the constraints `1 <= words[i].length <= 10
words[i] consists of lowercase English letters.` each alphabet needs only 4-bits a variant using `uint128` bitmask is implemented. A variant reusing words is also presented.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(\sum_{s \in words}|s|)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(26)$
# Code|C++ 0ms
```cpp []
class Solution {
public:
    static array<int, 26> freq(string& s){
        array<int, 26> ans{};
        for(char c: s){
            ans[c-'a']++;
        }
        return ans;
    }
    static vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size(), l=0, r=1;
        vector<string> ans={words[0]};
        array<int, 26> f0=move(freq(words[0]));
        for( ; r<n; r++){
            string s=words[r];
            auto x=move(freq(s));
            if (f0!=x){
                ans.push_back(s);
                l=r;
                f0=x;
            }
        }
        return ans;
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
# C++ using uint128 & reuse words|0ms
```cpp []
// this version reuses words
class Solution {
public:
    using u128=__uint128_t;
    static u128 freq(string& s){
        u128 ans=0;
        for(char c: s){
            ans+=(u128(1)<<4*(c-'a'));
        }
        return ans;
    }
    static vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size(), l=0, r=1;
        int sz=1;
        u128 f0=freq(words[0]);
        for( ; r<n; r++){
            string s=words[r];
            auto x=freq(s);
            if (f0!=x){
                words[sz++]=s;
                l=r;
                f0=x;
            }
        }
        words.resize(sz);
        return words;
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
```cpp []
class Solution {
public:
    using u128=__uint128_t;
    static u128 freq(string& s){
        u128 ans=0;
        for(char c: s){
            ans+=(u128(1)<<4*(c-'a'));
        }
        return ans;
    }
    static vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size(), l=0, r=1;
        vector<string> ans={words[0]};
        u128 f0=freq(words[0]);
        for( ; r<n; r++){
            string s=words[r];
            auto x=freq(s);
            if (f0!=x){
                ans.push_back(s);
                l=r;
                f0=x;
            }
        }
        return ans;
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
# Python code
```
class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        def freq(s):
            ans=0
            for c in s:
                i=ord(c)-97
                ans+=(1<<4*i)
            return ans
        n, l=len(words), 0
        ans=[words[0]]
        f0=freq(words[0])
        for r in range(1, n):
            s=words[r]
            x=freq(s)
            if f0!=x:
                ans.append(s)
                l=r
                f0=x
        return ans
```
**Leetcode 49. Group Anagrams** is a typical one of such questions; there are a plenty many LC's question about Anagram; it is also solved by the fact above [ref](https://leetcode.com/problems/group-anagrams/solutions/4683930/4-approaches-freq-count-sort-compression-12ms-beats-99-82/). The following explains how to use this fact to solve, please turn on the English subtitles
[https://youtu.be/WjrWkPysfRM?si=vwdPIgBnThtrzRH8](https://youtu.be/WjrWkPysfRM?si=vwdPIgBnThtrzRH8)
