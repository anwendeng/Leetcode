<h2><a href="https://leetcode.com/problems/sort-vowels-in-a-string">2785. Sort Vowels in a String</a></h2><h3>Medium</h3><hr><p>Given a <strong>0-indexed</strong> string <code>s</code>, <strong>permute</strong> <code>s</code> to get a new string <code>t</code> such that:</p>

<ul>
	<li>All consonants remain in their original places. More formally, if there is an index <code>i</code> with <code>0 &lt;= i &lt; s.length</code> such that <code>s[i]</code> is a consonant, then <code>t[i] = s[i]</code>.</li>
	<li>The vowels must be sorted in the <strong>nondecreasing</strong> order of their <strong>ASCII</strong> values. More formally, for pairs of indices <code>i</code>, <code>j</code> with <code>0 &lt;= i &lt; j &lt; s.length</code> such that <code>s[i]</code> and <code>s[j]</code> are vowels, then <code>t[i]</code> must not have a higher ASCII value than <code>t[j]</code>.</li>
</ul>

<p>Return <em>the resulting string</em>.</p>

<p>The vowels are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>, and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;lEetcOde&quot;
<strong>Output:</strong> &quot;lEOtcede&quot;
<strong>Explanation:</strong> &#39;E&#39;, &#39;O&#39;, and &#39;e&#39; are the vowels in s; &#39;l&#39;, &#39;t&#39;, &#39;c&#39;, and &#39;d&#39; are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;lYmpH&quot;
<strong>Output:</strong> &quot;lYmpH&quot;
<strong>Explanation:</strong> There are no vowels in s (all characters in s are consonants), so we return &quot;lYmpH&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of letters of the&nbsp;English alphabet&nbsp;in <strong>uppercase and lowercase</strong>.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
LC:
> vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase.

So, use a vowel mask to judge whether a letter is a vowel or not.
Count the vowels & store their positions, use a variant of counting sort to sort the vowels.
# Approach
<!-- Describe your approach to solving the problem. -->
1. let `vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31))` which is computed in the compling time , in fact `0x208222`
2. let `n=|s|`
3. declare the array `int freq[53]={0}` since 'u'-'A'+1=53
4. declare `vector<int> pos` to store the positions for vowels
5. Proceed a loop for c in s do the following:
```cpp
if((vowMask>>(c&31))&1){// if c is a vowel
    freq[c-'A']++;// increase the freq by 1
    pos.push_back(i);// add the index i to pos
}
```
6. Use a variant for counting sort to sort the vowels
7. Add C version which has the same structure & elapsed time 3ms
# Why bitmask method works?
vowel mask can solve also other LC's question [LC 3136. Valid Word](https://leetcode.com/problems/valid-word/solutions/6959558/bitmask-for-vowel-bitset-beats-100/)
[https://youtu.be/G3wTKtkRZFI?si=NG-SYVul9gLNcONR](https://youtu.be/G3wTKtkRZFI?si=NG-SYVul9gLNcONR)

The ascii code for `AEIOUaeiou` is
```
64+1, 64+5, 64+9, 64+15, 64+16+5,
64+32+1, 64+32+5, 64+32+9, 64+32+15, 64+32+16+5
```
c is a vowel $\iff$ (c & 0x1f)= 1,5,9,15,21
and `0x208222=0b1000001000001000100010`

Use the condition `(0x208222 >> (c & 31)) & 1`!!!

Let's see the testcase `s="lEetcOde"`
```
freq=[0, 1, 0, 1, 0, 0, 2, 0, 0, 0] 
pos=[1, 2, 5, 7]
s="lEOtcede" 
```
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(53)$
# Code|C++ 3ms|C 3ms
```cpp []
class Solution {
public:
    static string sortVowels(string& s) {
        constexpr unsigned vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));
    //    cout<<hex<<vowMask<<endl;
        const int n=s.size();
        int freq[53]={0}; //'u'-'A'+1=53
        vector<int> pos;
        for(int i=0; i<n; i++){
            char c=s[i];
            if((vowMask>>(c&31))&1){
                freq[c-'A']++;
                pos.push_back(i);
            }
        }
    //    print(pos);
        int count=0, v=freq[0], j=0;

        for (int i: pos){
            while(count>=v)
                v+=freq[++j];
            s[i]='A'+j;
            count++;
        }
        return s;
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
```c []
#pragma GCC optimize("O3, unroll-loops")
const unsigned vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));
int pos[100000];
static char* sortVowels(char* s) {
    int freq[53]={0};
    int pz=0;
    for(int i=0; s[i]!='\0'; i++){
        const char c=s[i];
        if((vowMask>>(c&31))&1){
            freq[c-'A']++;
            pos[pz++]=i;
        }
    }
    int count=0, v=freq[0], j=0;

    for (int p=0; p<pz; p++){
        const int i=pos[p];
        while(count>=v)
            v+=freq[++j];
        s[i]='A'+j;
        count++;
    }
    return s;
}
```
