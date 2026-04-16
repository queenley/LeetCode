class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        for (int col = 0; col < strs[0].size(); col++) {
            char c = strs[0][col];

            for (int row = 1; row < strs.size(); row++) {
                if (strs[row][col] != c || strs[row].size() <= col) {
                    return strs[0].substr(0, col);
                }
            }            
        }
        return strs[0];
    }
};