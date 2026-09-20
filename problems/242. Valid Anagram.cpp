class Solution {
public:
    bool isAnagram(string s, string t) {
        // base case: check if s and t have the same lengths
        if (s.size() != t.size()) return false;

        // since they are lowercase english letters
        // there are only 26 lowercase letters
        // we can use 1 array to keep track of letter counts
        vector<int> count(26, 0);

        // we can count + for s letters, - for t letters
        // in the end, we check if the whole count is zero
        // if true, then it must be an anagram
        // s for add, t for sub
        for (int i = 0; i < s.size(); i++) {
            // add for s
            ++count[s[i] - 'a'];
            // sub for t
            --count[t[i] - 'a'];
        }

        // one loop through count to check if there exists element != 0
        for (int x : count) {
            if (x != 0) return false;
        }

        return true;
    }
};