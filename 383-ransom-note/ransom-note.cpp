#include <unordered_map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        unordered_map<char, int> magazine_dict;
        for (auto c: magazine) {            
            if (magazine_dict.find(c) == magazine_dict.end()) magazine_dict[c] = 1;            
            else magazine_dict[c]++;
        }
        
        for (auto n: ransomNote) {
            if (magazine_dict[n] == 0 || magazine_dict.find(n) == magazine_dict.end()) return false;            
            magazine_dict[n]--;
        }
        return true;
    }
};