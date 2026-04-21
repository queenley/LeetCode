// class Solution {
// public:
//     string addWhiteSpace(string sentence, int maxWidth, int numWord, bool isLast) {        
//         int remain_width = maxWidth - sentence.size();  
//         if (numWord == 1 || isLast) {
//             sentence += string(remain_width, ' ');
//             return sentence;
//         }

//         int spaces = numWord - 1, start = 0;                      
//         int remain_space = remain_width / spaces + remain_width % spaces;
        
//         for (int i = 0; i < spaces; i++) {
//             int idx_space = sentence.find(" ", start);
//             sentence.replace(idx_space, 1, string(remain_space, ' '));
//             start = idx_space + remain_space;
//             remain_width -= remain_space;
//             remain_space = remain_width / (spaces - i + 1) + remain_width % (spaces - i + 1);
//         }
                
//         return sentence;
//     }
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//         vector<string> output = {words[0]};
//         int i = 0, numWord = 1;
//         bool isLast = false;
//         // push words
//         for (int w = 1; w < words.size(); w++) {                        
//             if (w == words.size() - 1) isLast = true;
            
//             string word = words[w];
//             if (word.size() + output[i].size() > maxWidth - 1) {
//                 // add white spaces
//                 output[i] = addWhiteSpace(output[i], maxWidth, numWord, isLast);

//                 output.push_back(word);
//                 i++;                
//                 numWord = 1;
//             }

//             else {
//                 output[i] += ' ' + word;
//                 numWord++;
//             }
//         }
//         output[i] = addWhiteSpace(output[i], maxWidth, numWord, true);
//         return output;        
        
//     }
// };


class Solution {
public:
    string addWhiteSpace(string sentence, int maxWidth, int numWord, bool isLast) {
        int remain_width = maxWidth - sentence.size();
        if (numWord == 1 || isLast) {
            sentence += string(remain_width, ' ');
            return sentence;
        }

        int spaces = numWord - 1, start = 0;        
        for (int i = 0; i < spaces; i++) {
            int space_count = 1 + remain_width / spaces + (i < remain_width % spaces ? 1 : 0);  
            int idx_space = sentence.find(" ", start);
            sentence.replace(idx_space, 1, string(space_count, ' '));
            start = idx_space + space_count;
        }

        return sentence;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output = {words[0]};
        int i = 0, numWord = 1;
        bool isLast = false;

        for (int w = 1; w < words.size(); w++) {
            string word = words[w];
            bool isLastWord = (w == words.size() - 1);

            if (word.size() + output[i].size() > maxWidth - 1) {
                output[i] = addWhiteSpace(output[i], maxWidth, numWord, false); 
                output.push_back(word);
                i++;
                numWord = 1;
            } else {
                output[i] += ' ' + word;
                numWord++;
            }
        }
        
        output[i] = addWhiteSpace(output[i], maxWidth, numWord, true);
        return output;
    }
};