#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // buckets[i] = all numbers that appear exactly i times
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int f = (int)buckets.size() - 1; f >= 1 && (int)ans.size() < k; --f) {
            for (int x : buckets[f]) {
                ans.push_back(x);
                if ((int)ans.size() == k) break;
            }
        }
        return ans;
    }
};
