<h2><a href="https://leetcode.com/problems/24-game">679. 24 Game</a></h2><h3>Hard</h3><hr><p>You are given an integer array <code>cards</code> of length <code>4</code>. You have four cards, each containing a number in the range <code>[1, 9]</code>. You should arrange the numbers on these cards in a mathematical expression using the operators <code>[&#39;+&#39;, &#39;-&#39;, &#39;*&#39;, &#39;/&#39;]</code> and the parentheses <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code> to get the value 24.</p>

<p>You are restricted with the following rules:</p>

<ul>
	<li>The division operator <code>&#39;/&#39;</code> represents real division, not integer division.

	<ul>
		<li>For example, <code>4 / (1 - 2 / 3) = 4 / (1 / 3) = 12</code>.</li>
	</ul>
	</li>
	<li>Every operation done is between two numbers. In particular, we cannot use <code>&#39;-&#39;</code> as a unary operator.
	<ul>
		<li>For example, if <code>cards = [1, 1, 1, 1]</code>, the expression <code>&quot;-1 - 1 - 1 - 1&quot;</code> is <strong>not allowed</strong>.</li>
	</ul>
	</li>
	<li>You cannot concatenate numbers together
	<ul>
		<li>For example, if <code>cards = [1, 2, 1, 2]</code>, the expression <code>&quot;12 + 12&quot;</code> is not valid.</li>
	</ul>
	</li>
</ul>

<p>Return <code>true</code> if you can get such expression that evaluates to <code>24</code>, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> cards = [4,1,8,7]
<strong>Output:</strong> true
<strong>Explanation:</strong> (8-4) * (7-1) = 24
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> cards = [1,2,1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
It's a hard question.
1. design rational class to deal +.-.* , / for rational numbers instead of floating arithmetics
2. Use postfix expression to treat the all possible calculations
3. here are 4!=24 ways to place the numbers
There are $4^3$=64 ways to place operators
There are 5 ways in insert the parentheses; their postfix expr look like the following 5 patterns
```
ab2c4d6
abc3d56
ab2cd56
abcd456
abc34d6
where  the number denote the positions the operators to place,
a, b,c,d denote the numbers 1-9.
If considering + & * are commutative, some different patterns have the same result.
```
`24*64*5` is not too big. Besides, some of them occurs not once.
# Approach
<!-- Describe your approach to solving the problem. -->
1. class rational is defined including the fraction reducing & comparing with int
2. Define some global variables such as
```cpp
char op[5]="+-*/";
array<array<int, 3>, 5> pos{{// there 5 diff ways for postfix expr
    {2, 4, 6}, {3, 5, 6}, 
    {2,  5, 6},// items denote the places for operators
    {4, 5, 6}, {3, 4, 6}}};
constexpr int INF=1e6+3;// deal with when denominator=0
```
3. define `rational postfix(const string& s)` which computes the value for the given postfix expr `s` where numbers consist all of 1 digit.
4. Define `bool get24(int x[4])` to judge whether there is a way to obtain 24 for the digits `x[4]` in the fixed positions
5. in `bool judgePoint24(vector<int>& cards)` uses a quadruple loop to find all possible permutations for `cards` with considering not repeating; in the innerst loop proceed `int arr[4]={a, b, c, d};
                        if (get24(arr)) return 1;`
6. If the loop is through, it's impossible to get 24 for these `cards`
7. A variant for `postfix(string& s)` us made in use of C-array as the stack which has elapsed time 4ms.
# Some computation for testcast cards=[4,1,8,7]
```cpp
41+7-8/:=>-1/4
417+8-/:=>INF
41+78-/:=>-5/1
4178+-/:=>-2/7
417+-8/:=>-1/2
41+7*8+:=>43/1
417+8*+:=>68/1
41+78*+:=>61/1
4178+*+:=>19/1
417+*8+:=>40/1
41+7*8-:=>27/1
417+8*-:=>-60/1
41+78*-:=>-51/1
4178+*-:=>-11/1
417+*8-:=>24/1
```
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
at most $O(7680)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class rational{
    int p, q;
public:
    rational(): p(0), q(1){}
    rational(int x): p(x), q(1){}
    rational(int p, int q): p(p), q(q){
        if (q==0) throw invalid_argument("denominator is 0");
    }
    rational operator+(const rational& other) const {
        return rational(p*other.q+other.p*q, q*other.q);
    }
    rational operator-(const rational& other) const {
        return rational(p*other.q-other.p*q, q*other.q);
    }
    rational operator*(const rational& other) const {
        return rational(p*other.p, q*other.q);
    }
    rational operator/(const rational& other) const {
        return rational(p*other.q, q*other.p);
    }
    bool operator==(const int x){
        reduced();
        return p==x && q==1;
    }
    void reduced(){
        if (p==0) { q=1; return;}
        int g=gcd(p, q);
        if (q<0)  p=-p, q=-q; 
        p/=g, q/=g;
    }
    void print(){
        cout<<p<<"/"<<q<<"\n";
    }
};
char op[5]="+-*/";
array<array<int, 3>, 5> pos{{
    {2, 4, 6}, {3, 5, 6}, {2,  5, 6},
    {4, 5, 6}, {3, 4, 6}}};
constexpr int INF=1e6+3;
class Solution {
public:
    static rational postfix(const string& s){
        vector<rational> st;
        for(char c: s){
            if (isdigit(c)) 
                st.push_back(rational(c-'0'));  // number
            else {
                rational y=st.back(); st.pop_back();
                rational x=st.back(); 
                switch(c){
                    case '+': st.back()=x+y; break;
                    case '-': st.back()=x-y; break;
                    case '*': st.back()=x*y; break;
                    case '/': 
                    if (y==0) return rational(INF);// divide by 0
                    st.back()=x/y;
                }
            }
        }
    //    st.back().print();
        return st.back();
    }

    static bool get24(int x[4]){
        for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        for(int k=0; k<4; k++){
            char ops3[3] = {op[i], op[j], op[k]};
            for(const auto& p : pos){
                string s(7, '?');
                for(int u=0, v=0, sz=0; sz<7; sz++){
                    if (sz==p[v]) s[sz]=ops3[v++]; // place operator
                    else  s[sz]='0'+x[u++]; // place digit
                }
            //    cout<<s<<"->";
                if (postfix(s)==24) return 1;
            }
        }
        return 0;
    }
    static bool judgePoint24(vector<int>& cards) {
        int a, b, c, d;
        bitset<10000> seen=0;
        int cnt=0, x=0;
        for(int i=0; i<4; i++){
            a=cards[i];
            for(int j=0; j<4; j++){
                if (i==j) continue;
                b=cards[j];
                for(int k=0; k<4; k++){
                    if(k==i ||k==j) continue;
                    c=cards[k];
                    for(int l=0; l<4; l++){
                        if (l==i || l==j || l==k) continue;
                        d=cards[l];
                        x=1000*a+100*b+10*c+d;
                        if (seen[x]) continue;
                    //    cout<<x<<":"<<cnt++<<"\n----\n";
                        seen[x]=1;
                        int arr[4]={a, b, c, d};
                        if (get24(arr)) return 1;
                    }
                }
            }
        }
        return 0;
    }
};
```
# C++ variant||4ms
```
// the rest is unchanged
rational st[4];
int top=-1;
class Solution {
public:
    static rational postfix(const string& s){
        top=-1;// reset stack
        for(char c: s){
            if (isdigit(c)) 
                st[++top]=rational(c-'0');  // number
            else {
                rational y=st[top--]; 
                rational x=st[top]; 
                switch(c){
                    case '+': st[top]=x+y; break;
                    case '-': st[top]=x-y; break;
                    case '*': st[top]=x*y; break;
                    case '/': 
                    if (y==0) return rational(INF);// divide by 0
                    st[top]=x/y;
                }
            }
        }
        return st[top];
    }
....

```
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>cards.length == 4</code></li>
	<li><code>1 &lt;= cards[i] &lt;= 9</code></li>
</ul>
