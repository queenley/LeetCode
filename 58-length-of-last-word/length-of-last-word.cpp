class Solution {
public:
    int lengthOfLastWord(string s) {
        int output = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') output++;
            else if (output > 0) break;            
        }
        return output;
    }
};