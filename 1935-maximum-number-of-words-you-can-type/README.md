<h2><a href="https://leetcode.com/problems/maximum-number-of-words-you-can-type">1935. Maximum Number of Words You Can Type</a></h2><h3>Easy</h3><hr><p>There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.</p>

<p>Given a string <code>text</code> of words separated by a single space (no leading or trailing spaces) and a string <code>brokenLetters</code> of all <strong>distinct</strong> letter keys that are broken, return <em>the <strong>number of words</strong> in</em> <code>text</code> <em>you can fully type using this keyboard</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> text = &quot;hello world&quot;, brokenLetters = &quot;ad&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> We cannot type &quot;world&quot; because the &#39;d&#39; key is broken.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> text = &quot;leet code&quot;, brokenLetters = &quot;lt&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> We cannot type &quot;leet&quot; because the &#39;l&#39; and &#39;t&#39; keys are broken.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> text = &quot;leet code&quot;, brokenLetters = &quot;e&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> We cannot type either word because the &#39;e&#39; key is broken.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= brokenLetters.length &lt;= 26</code></li>
	<li><code>text</code> consists of words separated by a single space without any leading or trailing spaces.</li>
	<li>Each word only consists of lowercase English letters.</li>
	<li><code>brokenLetters</code> consists of <strong>distinct</strong> lowercase English letters.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Use mask for brokenLetters to test whether the char is broken.

2nd Approach is using bitset.
3rd C++ has no branch, neither if nor ternary.
# Approach
<!-- Describe your approach to solving the problem. -->
1. Use a loop to build the `mask`: `mask|=(1<<(c-'a'))` for c in brokenLetters
2. Let `cnt=0`, `word=true` be given initially
3. To simplify the logic, append a ' ' to `text`
4. Proceed the loop as follows
```cpp
for(char c: text){// trasverse the whole text
    if (c==' '){ if c is a space
        cnt+=word;// if word=true add 1 to cnt
        word=1;  // set word=true
    }
    else if (mask &(1<<(c-'a'))) // if c in brokenLetters
        word=0;  // set word=false
}
```
5. `cnt` is the answer
6. 2nd approach is bitset
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(|text|+|brokenLetters|)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
# Code|C++ 0ms
```cpp []
class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        unsigned mask=0;
        for(char c: brokenLetters)
            mask|=(1<<(c-'a'));
        int cnt=0;
        bool word=1;
        text.push_back(' ');
        for(char c: text){
            if (c==' '){
                cnt+=word;
                word=1;
            }
            else if (mask &(1<<(c-'a'))) word=0;  
        }
        return cnt;
    }
};
```
# C++ bitset|0ms
```
class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        const int n=text.size();
        bitset<128> broken=0;
        for(char c: brokenLetters)
            broken[c]=1;
        int cnt=0;
        bool word=1;
        text.push_back(' ');
        for(char c: text){
            if (broken[c]) word=0;
            else if (c==' '){
                cnt+=word;
                word=1;
            }
        }
        return cnt;
    }
};
```
# 3rd C++ no branch||0ms
```
class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        const int n=text.size();
        bitset<128> broken=0;
        for(char c: brokenLetters)
            broken[c]=1;
        int cnt=0;
        bool word=1;
        text.push_back(' ');
        for(char c: text){
            word&=(!broken[c]);
            bool isspace=c==' ';
            cnt+=(word && isspace);
            word|=isspace;
        }
        return cnt;
    }
};
```
