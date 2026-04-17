class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;        
        string output(n, ' ');
        int o_idx = 0;
        for (int row = 0; row < numRows; row++) {
            int s_idx = row;            
            while (s_idx < n) {                                        
                output[o_idx] = s[s_idx];
                o_idx++;
                if (s_idx % (numRows - 1) == row) {
                    s_idx += (numRows - 1 - row) + (numRows - 1) - row; // numRows - 2 = number of elements on the diagonal
                }
                else s_idx += row * 2;
                if (s_idx >= n) break;
            }
        }
        return output;
    }
};