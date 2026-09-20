class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
            }
            else return true;
        }

        return false;
    }
};