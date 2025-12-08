<h2><a href="https://leetcode.com/problems/count-square-sum-triples">1925. Count Square Sum Triples</a></h2><h3>Easy</h3><hr><p>A <strong>square triple</strong> <code>(a,b,c)</code> is a triple where <code>a</code>, <code>b</code>, and <code>c</code> are <strong>integers</strong> and <code>a<sup>2</sup> + b<sup>2</sup> = c<sup>2</sup></code>.</p>

<p>Given an integer <code>n</code>, return <em>the number of <strong>square triples</strong> such that </em><code>1 &lt;= a, b, c &lt;= n</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 2
<strong>Explanation</strong>: The square triples are (3,4,5) and (4,3,5).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation</strong>: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 250</code></li>
</ul>

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
[This video shows how to use Euler's formula to implement a linear solution. This video has the English subtitles and the English sound track provided by youtube; Please turn on if necessary]
[https://youtu.be/mzXMpT9AaFg?si=Ri00QMoqPLCNL43Y](https://youtu.be/mzXMpT9AaFg?si=Ri00QMoqPLCNL43Y)
Pythagorean triple $(a, b, c)$ ($a^2+b^2=c^2$)is primitive if $\gcd(a, b, c)=1$

Use **Euclid's formula** to find primitive Pythagorean triple $(a, b, c)$:

 $(a, b, c)=(s^2-t^2, 2st, s^2+t^2)$!
 where $s, t$ have different parities & $\gcd(s, t)=1$
 $(b, a, c)$ is other primitive Pythagorean triple.

The  triples $(ka, kb, kc)$ & $(kb, ka, kc)$ for $k=1,\cdots, n/c$  are the valid Pythagorean triples!
# Approach
<!-- Describe your approach to solving the problem. -->
Provide 2 variants: They are different only the methods to compute gcd, let's focus on the main part.
1. let `cnt=0, int nsqrt=sqrt(n)`
2. Proceed the double loop to use the Euclid's formula to find all valid Pythagorean triple as follows:
```cpp
for (int s=2; s<=nsqrt; s++) {
    for (int t=1+(s&1); t<s; t+=2) {
        if (GCD(s, t)!=1) continue;

    //  int a=s*s-t*t;
    //  int b=2*s*t;
        int c=s*s+t*t;

        if (c>n) break;

        // k multiples: ka, kb, kc
        int kmax=n/c;
        // count (a,b,c) and (b,a,c)
        cnt+=2*kmax;
    }
}
```
3. 1st C++ computes the gcd by using a variant of binary Euclidean algorithm in which this method is much faster than `std::gcd`.
4. 2nd C++ computes gcd by using a table which is really of $O(n)$ time.
5. Python code is done during the filming.
6. Add a C code by using table method computing gcd.
# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$O(n\log n)\to O(n)$
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$O(1)$
GCD table: $O(n)$
# Code |C++ 0ms
```cpp []
class Solution {
public:
    static int GCD(unsigned x, unsigned y){
        const int bx=countr_zero(x), by=countr_zero(y);
        const int bb=min(bx, by);
        x>>=bx, y>>=by;
        for(unsigned r; y; y=min(y, r)){
            r=x%y;
            x=exchange(y, r);
        }
        return x<<bb;
    }
    static int countTriples(int n) {
        int cnt=0;
        int nsqrt=sqrt(n);
        for (int s=2; s<=nsqrt; s++) {
            for (int t=1+(s&1); t<s; t+=2) {
                if (GCD(s, t)!=1) continue;

            //    int a=s*s-t*t;
            //    int b=2*s*t;
                int c=s*s+t*t;

                if (c>n) break;

                // k multiples: ka, kb, kc
                int kmax=n/c;
                // count (a,b,c) and (b,a,c)
                cnt+=2*kmax;
            }
        }
        return cnt;
    }
};

```
# Code Euclid's formula+ GCD table|C, C++ 0ms
```C []
#pragma GCC optimize("O3, unroll-loops")
static int GCD[23][23]={{0}};
static void GCD_ini(){
    if (GCD[1][1]) return; // compute once
    const int N=23;
    for(int i=1; i<N; i++){
        GCD[i][0]=GCD[0][i]=GCD[i][i]=i;
        for(int j=i+1; j<N; j++){
            int r=j-i;
            GCD[i][j]=GCD[j][i]=GCD[i][r];
        }
    }
}
static int countTriples(int n) {
    GCD_ini();
    int cnt=0;
    int nsqrt=sqrt(n);
    for (int s=2; s<=nsqrt; s++) {
        for (int t=1+(s&1); t<s; t+=2) {
            if (GCD[s][t]!=1) continue;

            int c=s*s+t*t;

            if (c>n) break;

            // k multiples: ka, kb, kc
            int kmax=n/c;
            // count (a,b,c) and (b,a,c)
             cnt+=2*kmax;
        }
    }
    return cnt;
}
```
```cpp []
class Solution {
public:
    static constexpr int N=23;
    static consteval array<array<short, N>, N> GCD_ini(){
        array<array<short, N>, N> GCD{};
        for(int i=1; i<N; i++){
            GCD[i][0]=GCD[0][i]=GCD[i][i]=i;
            for(int j=i+1; j<N; j++){
                int r=j-i;
                GCD[i][j]=GCD[j][i]=GCD[i][r];
            }
        }
        return GCD;
    }
    static int countTriples(int n) {
        constexpr auto GCD=GCD_ini();
        int cnt=0;
        int nsqrt=sqrt(n);
        for (int s=2; s<=nsqrt; s++) {
            for (int t=1+(s&1); t<s; t+=2) {
                if (GCD[s][t]!=1) continue;

            //    int a=s*s-t*t;
            //    int b=2*s*t;
                int c=s*s+t*t;

                if (c>n) break;

                // k multiples: ka, kb, kc
                int kmax=n/c;
                // count (a,b,c) and (b,a,c)
                cnt+=2*kmax;
            }
        }
        return cnt;
    }
};


```
 # Python code|0ms
```Python []
class Solution:
    def countTriples(self, n: int) -> int:
        cnt=0
        nsqrt=int(sqrt(n))
        for s in range(2, nsqrt+1):
            for t in range((s&1)+1, s, 2):
                if gcd(s,t)!=1: continue
                c=s*s+t*t
                if c>n: break
                k=n//c
                cnt+=2*k
        return cnt
        
```
