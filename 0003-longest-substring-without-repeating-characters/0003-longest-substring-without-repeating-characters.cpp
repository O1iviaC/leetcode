class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);

        int maximum = 0;
        int i = 0;
        for(int j = 0; j < s.size() ; j++){
            char c = s[j];

            if(last[c] >= i){
                i = last[c] + 1;
            }
            last[c] = j;
            maximum = max(j - i + 1, maximum);
        }
        return maximum;
    }
};