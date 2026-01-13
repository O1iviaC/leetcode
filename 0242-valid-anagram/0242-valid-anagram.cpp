class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int letters[26] = {0};

        for (char c : s){
            letters[c - 'a']++;
        }

        for(char c : t){
            if(--letters[c - 'a'] < 0) return false;
        }
        return true;
    }
};