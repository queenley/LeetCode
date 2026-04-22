class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (auto c: t) {
            if (c == s[idx]) idx++;
        }
        if (idx != s.size()) return false;
        return true;
    }
};