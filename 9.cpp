//Question :- Number of valid Words for Each Puzzles (https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/)
//Difficulty Level :- Hard
//Pre-requisite- Good Knowledge of Bit Manipulation
//To be honest ,i didn't get any idea about this question ,so i took help from youtube and discuss section

 int maskWord(string word) {
         int mask = 0;
        for (auto c : word) mask |= (1 << c-'a');
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for (auto word : words) freq[(maskWord(word))]++;
        vector<int> res;
        for (auto p : puzzles) {
            int mask = maskWord(p), submask = mask, first = (1 << p[0]-'a'), curr = 0;
            
            while (submask) {
                if (submask & first) curr += freq[submask];
                submask = (submask-1) & mask;
            }
            res.push_back(curr);
        }
        return res;
    }