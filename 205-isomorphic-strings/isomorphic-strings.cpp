class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> isomorphic;
        unordered_map<char, char> isomorphic_reverse;

        for (int i = 0; i < s.size(); i++) {
            char sc = s[i], tc = t[i];
            if (isomorphic.find(sc) != isomorphic.end() && isomorphic[sc] != tc) return false;
            if (isomorphic_reverse.find(tc) != isomorphic_reverse.end() && isomorphic_reverse[tc] != sc) return false;      
            
            isomorphic[sc] = tc;
            isomorphic_reverse[tc] = sc;
        }
        
        return true;
    }
};