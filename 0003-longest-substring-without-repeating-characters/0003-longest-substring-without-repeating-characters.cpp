class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> track;
        int maximum = 0;
        int i = 0;
        for(int j = 0; j < s.size() ; j++){
            char c = s[j];

            if(track.count(c) && track[c] >= i){
                i = track[c] + 1;
            }
            track[c] = j;
            maximum = max(j - i + 1, maximum);
        }
        return maximum;
    }
};