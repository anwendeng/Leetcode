<h2><a href="https://leetcode.com/problems/vowels-game-in-a-string">3227. Vowels Game in a String</a></h2><h3>Medium</h3><hr><p>Alice and Bob are playing a game on a string.</p>

<p>You are given a string <code>s</code>, Alice and Bob will take turns playing the following game where Alice starts <strong>first</strong>:</p>

<ul>
	<li>On Alice&#39;s turn, she has to remove any <strong>non-empty</strong> <span data-keyword="substring">substring</span> from <code>s</code> that contains an <strong>odd</strong> number of vowels.</li>
	<li>On Bob&#39;s turn, he has to remove any <strong>non-empty</strong> <span data-keyword="substring">substring</span> from <code>s</code> that contains an <strong>even</strong> number of vowels.</li>
</ul>

<p>The first player who cannot make a move on their turn loses the game. We assume that both Alice and Bob play <strong>optimally</strong>.</p>

<p>Return <code>true</code> if Alice wins the game, and <code>false</code> otherwise.</p>

<p>The English vowels are: <code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, and <code>u</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;leetcoder&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong><br />
Alice can win the game as follows:</p>

<ul>
	<li>Alice plays first, she can delete the underlined substring in <code>s = &quot;<u><strong>leetco</strong></u>der&quot;</code> which contains 3 vowels. The resulting string is <code>s = &quot;der&quot;</code>.</li>
	<li>Bob plays second, he can delete the underlined substring in <code>s = &quot;<u><strong>d</strong></u>er&quot;</code> which contains 0 vowels. The resulting string is <code>s = &quot;er&quot;</code>.</li>
	<li>Alice plays third, she can delete the whole string <code>s = &quot;<strong><u>er</u></strong>&quot;</code> which contains 1 vowel.</li>
	<li>Bob plays fourth, since the string is empty, there is no valid play for Bob. So Alice wins the game.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;bbcd&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong><br />
There is no valid play for Alice in her first turn, so Alice loses the game.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Alice wins if there exists some vowel in s. (See proof)
Use bit mask to judge whether c is a vowl
`((0x208222>>(c & 0x1f)) & 1);`
# Approach
<!-- Describe your approach to solving the problem. -->
1. Usually it can be implemented by a loop, but using `any_of` can be very short
2. The lambda function is given by `[](char c) { return ((0x208222>>(c & 0x1f)) & 1); }`
3. Add python 1-liner in the similar way.
4. a varriant for vowel bitmask is `((0x104111>>(c-'a'))&1)` 
5. the fact for Alice winning the game is proved as follows
# Proof of the Fact
3 cases to discuss:
1. If there is no vowel in s, Bob wins.
2. If there are odd number of vowels, Alice can take all at once, of cource she plays optimally gives no chance for Bob.
3. If there are even number of vowels, Alice takes any odd number of vowels; Bob can take an even number of vowels. At the 2nd turn, Alice takes the remaining odd number of vowels & wins. **Q.E.D.**
# Why bitmask method works?
Vowel mask method can solve also other LC's questions, in fact many [LC 3136. Valid Word](https://leetcode.com/problems/valid-word/solutions/6959558/bitmask-for-vowel-bitset-beats-100/)
[https://youtu.be/G3wTKtkRZFI?si=NG-SYVul9gLNcONR](https://youtu.be/G3wTKtkRZFI?si=NG-SYVul9gLNcONR)

The ascii code for `AEIOUaeiou` is
```
64+1, 64+5, 64+9, 64+15, 64+16+5,
64+32+1, 64+32+5, 64+32+9, 64+32+15, 64+32+16+5
```
c is a vowel $\iff$ (c & 0x1f)= 1,5,9,15,21
and `0x208222=0b1000001000001000100010`

Use the condition `(0x208222 >> (c & 31)) & 1`!!!
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
 $$O(n)$$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
 $$O(1)$$
# Code||0ms Beats 100%
```cpp []
class Solution {
public:
    static bool doesAliceWin(string& s) {
        return any_of(s.begin(), s.end(), [](char c) { return ((0x208222>>(c & 31)) & 1); });
    }
};
```
```Python []
class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any(((0x208222>>(ord(c)&31))&1) for c in s)
        
```
# 1-liner Variant||C++0ms
```
class Solution {
public:
    static bool doesAliceWin(string& s) {
        return any_of(s.begin(), s.end(), [](char c) { return ((0x104111>>(c-'a'))&1); });
    }
};
```
