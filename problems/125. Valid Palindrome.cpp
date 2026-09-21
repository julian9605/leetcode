class Solution {
public:
    bool isPalindrome(string s) {
        // convert to lower case string
        string k = "";
        for (char c : s) {
            // check for uppercase
            if (c <= 'Z' && c >= 'A') {
                k.push_back(c - ('Z' - 'z'));
            }
            // lowercase
            if ((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0')) {
                k.push_back(c);
            }
        }

        // 2 pointers
        for (int l = 0; l < k.size(); l++) {
            int r = k.size() - l - 1;
            if (k[l] != k[r]) return false;
        }
        return true;
    }
};