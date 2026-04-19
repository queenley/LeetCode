class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();
        int haystack_size = haystack.size();
        if (needle_size > haystack_size) return -1;
        int index = 0;        
        while (index <= haystack_size - needle_size) {
            if (index > haystack_size - needle_size) break;
            int i = index;
            for (int j = 0; j < needle_size; j++) {                
                if (needle[j] == haystack[i]) {
                    if (j == needle_size - 1) return index;
                    i++;
                }
                else break;
            }
            index++; 
        }
        return -1;
    }
};