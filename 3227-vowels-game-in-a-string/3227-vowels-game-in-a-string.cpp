class Solution {
public:
    static bool doesAliceWin(string& s) {
        return any_of(s.begin(), s.end(), [](char c) { return ((0x104111>>(c-'a'))&1); });
    }
};