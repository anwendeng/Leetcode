<h2><a href="https://leetcode.com/problems/vowel-spellchecker">966. Vowel Spellchecker</a></h2><h3>Medium</h3><hr><p>Given a <code>wordlist</code>, we want to implement a spellchecker that converts a query word into a correct word.</p>

<p>For a given <code>query</code> word, the spell checker handles two categories of spelling mistakes:</p>

<ul>
	<li>Capitalization: If the query matches a word in the wordlist (<strong>case-insensitive</strong>), then the query word is returned with the same case as the case in the wordlist.

	<ul>
		<li>Example: <code>wordlist = [&quot;yellow&quot;]</code>, <code>query = &quot;YellOw&quot;</code>: <code>correct = &quot;yellow&quot;</code></li>
		<li>Example: <code>wordlist = [&quot;Yellow&quot;]</code>, <code>query = &quot;yellow&quot;</code>: <code>correct = &quot;Yellow&quot;</code></li>
		<li>Example: <code>wordlist = [&quot;yellow&quot;]</code>, <code>query = &quot;yellow&quot;</code>: <code>correct = &quot;yellow&quot;</code></li>
	</ul>
	</li>
	<li>Vowel Errors: If after replacing the vowels <code>(&#39;a&#39;, &#39;e&#39;, &#39;i&#39;, &#39;o&#39;, &#39;u&#39;)</code> of the query word with any vowel individually, it matches a word in the wordlist (<strong>case-insensitive</strong>), then the query word is returned with the same case as the match in the wordlist.
	<ul>
		<li>Example: <code>wordlist = [&quot;YellOw&quot;]</code>, <code>query = &quot;yollow&quot;</code>: <code>correct = &quot;YellOw&quot;</code></li>
		<li>Example: <code>wordlist = [&quot;YellOw&quot;]</code>, <code>query = &quot;yeellow&quot;</code>: <code>correct = &quot;&quot;</code> (no match)</li>
		<li>Example: <code>wordlist = [&quot;YellOw&quot;]</code>, <code>query = &quot;yllw&quot;</code>: <code>correct = &quot;&quot;</code> (no match)</li>
	</ul>
	</li>
</ul>

<p>In addition, the spell checker operates under the following precedence rules:</p>

<ul>
	<li>When the query exactly matches a word in the wordlist (<strong>case-sensitive</strong>), you should return the same word back.</li>
	<li>When the query matches a word up to capitlization, you should return the first such match in the wordlist.</li>
	<li>When the query matches a word up to vowel errors, you should return the first such match in the wordlist.</li>
	<li>If the query has no matches in the wordlist, you should return the empty string.</li>
</ul>

<p>Given some <code>queries</code>, return a list of words <code>answer</code>, where <code>answer[i]</code> is the correct word for <code>query = queries[i]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
<strong>Output:</strong> ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> wordlist = ["yellow"], queries = ["YellOw"]
<strong>Output:</strong> ["yellow"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= wordlist.length, queries.length &lt;= 5000</code></li>
	<li><code>1 &lt;= wordlist[i].length, queries[i].length &lt;= 7</code></li>
	<li><code>wordlist[i]</code> and <code>queries[i]</code> consist only of only English letters.</li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
1. Use vowel mask to find the vowels again
2. Build hash tables for all words, their corresponding lowercase words & their corresponding  words with wildcard vowels

1st approach uses `std::unordered_set` & `std::unordered_map` to build these 3 tables. Later try other method when having time.

2nd  approach uses trie with custom allocator
# Approach
<!-- Describe your approach to solving the problem. -->
1. declare vowel bitmask `vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31))`
2. define `string tolow(string w)` to convert w to its lowercase word
3. define `string toDeV(string w)` to convert w to its corresponding word with wildcard vowels as '$'
4. In `vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)` let `n=|wordlist|`
5. build `unordered_set<string> W`  for all words in wordlist
6. declare `unordered_map<string, string> Wlow, WdeV` with reserving space for better performance
7. Use a loop to build `Wlow` & `WdeV` as follows
```cpp
for (const auto& w : wordlist) {
    const string lw = tolow(w), dv = toDeV(lw);
    if (!Wlow.count(lw)) Wlow[lw] = w;
    if (!WdeV.count(dv)) WdeV[dv] = w;
}
```
8. Reuse `queries` for the returning results. Proceed the following loop
```cpp
for (auto& q : queries) {
    if (W.count(q)) continue;// find q in W
    string low = tolow(q), deV = toDeV(low);
    if (Wlow.count(low)) q = Wlow[low];// if low in Wlow q=Wlow[low]
    else if (WdeV.count(deV)) q = WdeV[deV];// else if deV in WdeV
    else q = ""; // none in any case
}
```
9. The Trie solution is the 2nd approach which runs in 55ms & slower than the hash table  version
10. Instead of hash tables, use 3 trie objects in combination of string arrays to solve.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n\times average(\text{|word| in wordlist})+|queries|)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(n)$
# Code 3 hash tables |19ms beats 100%
```cpp []
class Solution {
public:
    static constexpr unsigned vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));
    static string tolow(string w) {
        for (char& c : w) c=tolower(c);
        return w;
    }

    static string toDeV(string w) {
        for (char& c : w)
            if((vowMask>>(c&31))&1) c='$';
        return w;
    }

    static vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        const int n=wordlist.size();
        unordered_set<string> W(wordlist.begin(), wordlist.end());
        unordered_map<string, string> Wlow, WdeV;
        Wlow.reserve(n), WdeV.reserve(n);

        for (const auto& w : wordlist) {
            const string lw = tolow(w), dv = toDeV(lw);
            if (!Wlow.count(lw)) Wlow[lw] = w;
            if (!WdeV.count(dv)) WdeV[dv] = w;
        }

        for (auto& q : queries) {
            if (W.count(q)) continue;
            string low = tolow(q), deV = toDeV(low);
            if (Wlow.count(low)) q = Wlow[low];
            else if (WdeV.count(deV)) q = WdeV[deV];
            else q = "";
        }
        return queries;
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
# Trie is an advance data struture solving many LC's string questions
[Solve hard question [140. Word Break II](https://leetcode.com/problems/word-break-ii/solutions/5203799/dp-hash-vs-dp-trie-0ms-beats-100/). Please turn on the English subtitles if necessary]
[https://youtu.be/_E-fcmVmkYU?si=Ag7pjJ3qLcUFje9m](https://youtu.be/_E-fcmVmkYU?si=Ag7pjJ3qLcUFje9m)
1. The TrieNode is defined by
```cpp
struct TrieNode {
    TrieNode* links[58]; // 'z'-'A'+1=58
    int id;// point to the index of string stored in the array Word
};
```
2. Some global variables
```cpp
static constexpr int N=350000; 
static TrieNode pool[3][N];  // for 3 trie objects
static string Word[3][N];    // array Word for 3 tables
static int ptr[3]={0,0,0};   // node counters
static int wid[3]={0,0,0};   // word counters
```
3. define class Trie with construtor, insert & search which are not much different from the standard trie problems; the custom allocator has better performance than allocating 1 by 1.
4. In `spellchecker` declare 3 trie objects `Trie W(0), Wlow(1), WdeV(2)`
5. The procedure is similar in the 1st approach.
# Trie+ custom allocator||43ms
```
struct TrieNode {
    TrieNode* links[58]; // 'z'-'A'+1=58
    int id;
};

static constexpr int N=350000;  
static TrieNode pool[3][N];
static string Word[3][N];
static int ptr[3]={0,0,0};   // node counters
static int wid[3]={0,0,0};   // word counters

class Trie {
    int idx;
    TrieNode* newNode() {
        TrieNode* node=&pool[idx][ptr[idx]++];
        memset(node->links, 0, sizeof(node->links));
        node->id=-1;
        return node;
    }
public:
    TrieNode* root;
    Trie(int idx): idx(idx) {
        root=newNode();
    }
    void insert(const string& word, const string& word0) {
        TrieNode* Node=root;
        for(char c: word) {
            int i=c-'A';
            if(Node->links[i]==NULL)
                Node->links[i]=newNode();
            Node=Node->links[i];
        }
        if(Node->id==-1) {                // only for first time
            Node->id=wid[idx]++;
            Word[idx][Node->id]=word0;    // word
        }
    }
    string search(const string& word) {
        TrieNode* Node=root;
        for(char c: word) {
            int i=c-'A';
            if(Node->links[i]==NULL) return "";
            Node=Node->links[i];
        }
        return Node->id==-1 ? "" : Word[idx][Node->id];
    }
};

class Solution {
public:
    static constexpr unsigned vowMask=
    (1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));

    static string tolow(string w) {
        for(char& c : w) c=tolower(c);
        return w;
    }

    static string toDeV(string w) {
        for(char& c : w)
            if((vowMask>>(c&31))&1) c= '_';// between 'A' & 'z'
        return w;
    }

    static vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        Trie W(0), Wlow(1), WdeV(2);

        // build dictionaries
        for(const string& w : wordlist) {
            W.insert(w, w);
            string lw=tolow(w);
            string dv=toDeV(lw);
            Wlow.insert(lw, w);
            WdeV.insert(dv, w);
        }

        for(string& q : queries) {
            // exact match
            if (W.search(q)!="") continue;

            // case-insensitive
            string low=tolow(q);
            q=Wlow.search(low);
            if(q!= "") continue;

            // vowel-wildcard 
            string dev=toDeV(low);
            q=WdeV.search(dev);
        }
        return queries;
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
