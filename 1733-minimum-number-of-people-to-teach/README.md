<h2><a href="https://leetcode.com/problems/minimum-number-of-people-to-teach">1733. Minimum Number of People to Teach</a></h2><h3>Medium</h3><hr><p>On a social network consisting of <code>m</code> users and some friendships between users, two users can communicate with each other if they know a common language.</p>

<p>You are given an integer <code>n</code>, an array <code>languages</code>, and an array <code>friendships</code> where:</p>

<ul>
	<li>There are <code>n</code> languages numbered <code>1</code> through <code>n</code>,</li>
	<li><code>languages[i]</code> is the set of languages the <code>i<sup>​​​​​​th</sup></code>​​​​ user knows, and</li>
	<li><code>friendships[i] = [u<sub>​​​​​​i</sub>​​​, v<sub>​​​​​​i</sub>]</code> denotes a friendship between the users <code>u<sup>​​​​​</sup><sub>​​​​​​i</sub></code>​​​​​ and <code>v<sub>i</sub></code>.</li>
</ul>

<p>You can choose <strong>one</strong> language and teach it to some users so that all friends can communicate with each other. Return <i data-stringify-type="italic">the</i> <i><strong>minimum</strong> </i><i data-stringify-type="italic">number of users you need to teach.</i></p>
Note that friendships are not transitive, meaning if <code>x</code> is a friend of <code>y</code> and <code>y</code> is a friend of <code>z</code>, this doesn&#39;t guarantee that <code>x</code> is a friend of <code>z</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can either teach user 1 the second language or user 2 the first language.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Teach the third language to users 1 and 3, yielding two users to teach.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>languages.length == m</code></li>
	<li><code>1 &lt;= m &lt;= 500</code></li>
	<li><code>1 &lt;= languages[i].length &lt;= n</code></li>
	<li><code>1 &lt;= languages[i][j] &lt;= n</code></li>
	<li><code>1 &lt;= u<sub>​​​​​​i</sub> &lt; v<sub>​​​​​​i</sub> &lt;= languages.length</code></li>
	<li><code>1 &lt;= friendships.length &lt;= 500</code></li>
	<li>All tuples <code>(u<sub>​​​​​i, </sub>v<sub>​​​​​​i</sub>)</code> are unique</li>
	<li><code>languages[i]</code> contains only unique values</li>
</ul>


# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Use bitset to replace hashset; the elapsed time will be speeded up very significantly.
For comparison, a version using unoredered_set is also made which runs in 227ms.
[This film show how to convert a version using hashset into a version using bitset. Please turn on the English subtitles if necessary]
[https://youtu.be/TZj1qyV-_m4?si=L6jcc51m88LVLlkF](https://youtu.be/TZj1qyV-_m4?si=L6jcc51m88LVLlkF)
# Approach
<!-- Describe your approach to solving the problem. -->
1. let `m=|languages|`
2. declare `vector<bitset<501>> know(m)` as known languages for each person, 1 `bitset<501>` for 1 person
3. Use a double loop to assign `know[i][l]` for l in `languages[i]` for i
4. declare `bitset<501> need=0` which denotes who need be taught a language eventually
5. Use a loop to find out who `need` as follows
```cpp
for (auto& f : friendships) {// trasvere over friendships
    int a=f[0]-1, b=f[1]-1;// 1-indexed for know
    if ((know[a] & know[b]).any()) continue; // can talk, because the intersection is not empty
    need[a]=need[b]=1;// a & b need be taught a language eventually
}
```
6. Let `ans=IT_MAX` be given initially
7. Proceed the loop to find out the min:
```cpp
for (int lang=1; lang<=n; lang++) { // languages for 1..n
    int cnt=0;
    for (int i=0; i<m; i++) {
        if (need[i] & !know[i][lang]) cnt++;// teach person[i] language lang
    }
    ans=min(ans, cnt);// take min
}
```
8. return `ans`
9. Add a hashset version
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(mn+|friendship|n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(501m)$
# Code|C++ 0ms
```cpp []
class Solution {
public:
    static int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size(); // number of people

        //known languages for each person
        vector<bitset<501>> know(m);
        for (int i=0; i<m; i++) 
            for (int l : languages[i]) know[i][l]=1;
        
        // people need be taught
        bitset<501> need=0;
        for (auto& f : friendships) {
            int a=f[0]-1, b=f[1]-1;
            if ((know[a] & know[b]).any()) continue; // can talk
            need[a]=need[b]=1;
        }

        // if no need
        if (need.count()==0) return 0;

        int ans=INT_MAX;
        for (int lang=1; lang<=n; lang++) { // languages for 1..n
            int cnt=0;
            for (int i=0; i<m; i++) {
                if (need[i] & !know[i][lang]) cnt++;
            }
            ans=min(ans, cnt);
        }

        return ans;
    }
};

```
# Hashset version|C++ unordered_set 227ms
```cpp []
// use unordered_set for comparison
class Solution {
public:
    static bool intersection(unordered_set<int>& X, unordered_set<int>& Y){
        if (X.size()>Y.size()) return intersection(Y, X);
        for(int x: X){
            if (Y.count(x)) return 1;
        }
        return 0;
    }
    static int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size(); // number of people

        // store known languages for each person
        vector<unordered_set<int>> know(m);
        for (int i=0; i<m; i++) 
            for (int l : languages[i]) know[i].insert(l);
        

        // people need be taught
        unordered_set<int> need;
        need.reserve(500);
        for (auto& f : friendships) {
            int a=f[0]-1, b=f[1]-1;
            if (intersection(know[a],know[b])) continue; // can talk
            need.insert(a);
            need.insert(b);
        }

        // if no need
        if (need.size()==0) return 0;

        int ans=INT_MAX;
        for (int lang=1; lang<=n; lang++) {   // languages for 1..n
            int cnt=0;
            for (int i: need) {
                if (!know[i].count(lang)) cnt++;
            }
            ans=min(ans, cnt);
        }

        return ans;
    }
};
```
