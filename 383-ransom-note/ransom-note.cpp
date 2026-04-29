#include <unordered_map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {        
        unordered_map<char, int> magazine_dict;
        for (auto c: magazine) magazine_dict[c]++;        

        for (auto n: ransomNote) {
            if (magazine_dict.find(n) == magazine_dict.end() || magazine_dict[n] == 0) return false;            
            magazine_dict[n]--;
        }
        return true;
    }
};