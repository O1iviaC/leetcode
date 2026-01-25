/*
* we take in nums (an array with all our numbers), and k representing the first k highest occuring numbers within nums

* we create a map where the key of each pair would be the number from nums and the value from the pair represents its number of occurences. This is tracked using the for loop, everytime we see the key (represented by x) we increment its existing value of the pair and if that number never existed it is added to the map and its value is 1

* next we have a 2d array called buckets that is sized one more than the size of nums so that its last index number correctly reflects the size of nums since the maximum number of occurences for a number is the array size and since arrays are 0-indexed we need to make the array size one more than that.

* Now in the 2d array the first dimension represents the total occurences, and using p as a pointer iterating through our map freq, any time we see a key with a specific occurence we add it to the index of that first dimension. the second of the 2d array is a vector of all the keys that have the first dimension's number of occurences

* after iterating through the entire map we now want to return the k most frequently occuring numbers. With the first dimension of buckets representing occurences, this means the higher the array index of the first dimension, the higher the number of occurence so we iterate through this for loop backwards starting from buckets.size() - 1 all the way until we iterated backwards k number of times. At each iteration there is an inner for loop to push back all of the array elements within the vector of the second dimension of the buckets 2d array which holds all of the numbers at each amount of occurences.

* finally we return ans
*/
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
