class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // create a hashset to store all distinct numbers
        // go through the set
        // only start counting sequence length at the start of a sequence
        // start of a sequence: set.find(x - 1) == set.end()
        // initialize len to count for this seq length
        // while (set.find(x + len) != set.end()) len += 1
        // compare with max length: length = max(length, len)
        // return max length

        // create the set
        unordered_set<int> set;
        for (int& x : nums) {
            if (set.find(x) == set.end()) {
                set.insert(x);
            }
        }

        int length = 0;
        for (const int& x : set) {
            if (set.find(x-1) == set.end()) {
                // this is a starting number
                int len = 1;
                while (set.find(x + len) != set.end()) {
                    len += 1;
                }
                length = max(length, len);
            }
        }

        return length;
    }
};