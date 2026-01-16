class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> seen;
        vector<char> str;
        int maxFreq = 0;
        char maxC;
        int i = 0;
        while(i < s.length()){
            str.push_back(s[i]);
            seen[s[i]] = seen[s[i]] + 1;
            if(seen[s[i]] > maxFreq){
                 maxFreq = seen[s[i]];
                 maxC = s[i];
            }
            if(str.size() - maxFreq > k){
                seen[str.front()]--;
                if(str.front() == maxC) maxFreq--;
                str.erase(str.begin());
            }
            i++;
        }
        return str.size();
    }
};
