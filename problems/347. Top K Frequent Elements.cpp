class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // use a hashmap to keep track of freq of each number (num : freq)
        // create another hashmap, such that freq : vector<int> num
        // loop through the hashmap in descending freq order
        // construct res

        // map num : freq
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // map freq : vector of nums
        unordered_map<int, vector<int>> mp;
        for (const auto& [num, fr] : freq) {
            mp[fr].push_back(num);
        }

        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            // there exists values in this key
            if(mp.find(i+1) != mp.end()) {
                for (int num : mp[i+1]) {
                    res.push_back(num);
                    if (res.size() == k) {
                        return res;
                    }
                }
            }
        }

        return res;

    }
};