class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = {1};
        vector<int> suffix = {1};
        vector<int> result;
        int product = 1;
        for(int i = 1; i < nums.size(); i++) {
            product *= nums[i - 1];
            prefix.push_back(product);
        }
        product = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            product *= nums[i + 1];
            suffix.push_back(product);
        }

        for(int i = 0, j = nums.size() - 1 ; i < nums.size() , j >= 0 ; i++, j--) {
            product = prefix[i] * suffix[j];
            result.push_back(product);
        }
        return result;
    }

};