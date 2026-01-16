class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int best = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            int idx = s[right] - 'A';
            count[idx]++;
            if (count[idx] > maxFreq) maxFreq = count[idx];

            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            best = max(best, right - left + 1);
        }
        return best;
    }
};
