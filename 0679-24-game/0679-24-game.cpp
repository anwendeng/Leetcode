class rational {
    int p, q;

public:
    rational() : p(0), q(1) {}
    rational(int x) : p(x), q(1) {}
    rational(int p, int q) : p(p), q(q) {
        if (q == 0)
            throw invalid_argument("denominator is 0");
    }
    rational operator+(const rational& other) const {
        return rational(p * other.q + other.p * q, q * other.q);
    }
    rational operator-(const rational& other) const {
        return rational(p * other.q - other.p * q, q * other.q);
    }
    rational operator*(const rational& other) const {
        return rational(p * other.p, q * other.q);
    }
    rational operator/(const rational& other) const {
        return rational(p * other.q, q * other.p);
    }
    bool operator==(const int x) const {
        return p == x*q;
    }
    void reduced() {
        if (p == 0) {
            q = 1;
            return;
        }
        int g = gcd(p, q);
        p /= g, q /= g;
        if (q < 0)
            p = -p, q = -q;
    }
    void print() { cout << p << "/" << q << "\n"; }
};
char op[5] = "+-*/";
array<array<int, 3>, 5> pos{
    {{2, 4, 6}, {3, 5, 6}, {2, 5, 6}, {4, 5, 6}, {3, 4, 6}}};
constexpr int INF = 1e6 + 3;
rational st[4];
int top = -1;
class Solution {
public:
    static rational postfix(const string& s) {
        top = -1; // reset stack
        for (char c : s) {
            if (isdigit(c))
                st[++top] = rational(c - '0'); // number
            else {
                rational y = st[top--];
                rational x = st[top];
                switch (c) {
                case '+':
                    st[top] = x + y;
                    break;
                case '-':
                    st[top] = x - y;
                    break;
                case '*':
                    st[top] = x * y;
                    break;
                case '/':
                    if (y == 0)
                        return rational(INF); // divide by 0
                    st[top] = x / y;
                }
            }
        }
        rational r = st[top];
        r.reduced();
        //    st[top].print();
        return r;
    }

    static bool get24(auto& x) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) {
                    char ops3[3] = {op[i], op[j], op[k]};
                    for (const auto& p : pos) {
                        string s(7, '?');
                        for (int u = 0, v = 0, sz = 0; sz < 7; sz++) {
                            if (sz == p[v])
                                s[sz] = ops3[v++]; // place operator
                            else
                                s[sz] = '0' + x[u++]; // place digit
                        }
                        //    cout<<s<<"->";
                        if (postfix(s) == 24)
                            return 1;
                    }
                }
        return 0;
    }
    static int pack(auto& arr) {
        return (arr[0]<< 12) + (arr[1]<< 8) + (arr[2]<< 4) + arr[3];
    }
    static bool judgePoint24(vector<int>& cards) {
        bitset<0xffff> seen=0;
        for (int i=0; i<4; i++) {
            swap(cards[0], cards[i]);
            for (int j=1; j<4; j++) {
                swap(cards[1], cards[j]);
                for (int k=2; k<4; k++) {
                    swap(cards[2], cards[k]);
                    int x=pack(cards);
                    if (!seen[x]){
                        if (get24(cards)) return 1;
                        seen[x]=1;
                    }
                    swap(cards[2], cards[k]); // backtrack
                }
                swap(cards[1], cards[j]); // backtrack
            }
            swap(cards[0], cards[i]); // backtrack
        }
        return 0;
    }
};
