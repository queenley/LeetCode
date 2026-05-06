class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // unordered_map<char, char> isomorphic;
        // unordered_map<char, char> isomorphic_reverse;
        
        // for (int i = 0; i < s.size(); i++) {
        //     char sc = s[i], tc = t[i];
        //     if (isomorphic.find(sc) != isomorphic.end() && isomorphic[sc] != tc) return false;
        //     if (isomorphic_reverse.find(tc) != isomorphic_reverse.end() && isomorphic_reverse[tc] != sc) return false;      
            
        //     isomorphic[sc] = tc;
        //     isomorphic_reverse[tc] = sc;
        // }
        
        // return true;

        int s_to_t[256];
        int t_to_s[256];
        memset(s_to_t, -1, sizeof(s_to_t));
        memset(t_to_s, -1, sizeof(t_to_s));

        for (int i = 0; i < s.size(); i++) {
            char sc = s[i], tc = t[i];

            if (s_to_t[sc] == -1 && t_to_s[tc] == -1) {
                s_to_t[sc] = tc;
                t_to_s[tc] = sc;
            }
            else if (s_to_t[sc] != tc || t_to_s[tc] != sc)
                return false;
        }
        return true;
    }
};