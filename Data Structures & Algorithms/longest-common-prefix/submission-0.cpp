class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        // Go through each character of the first string
        for (int i = 0; i < strs[0].size(); i++) {

            char current = strs[0][i];

            // Compare this character with every other string
            for (int j = 1; j < strs.size(); j++) {

                // If the current string is too short
                if (i >= strs[j].size()) {
                    return ans;
                }

                // If characters don't match
                if (strs[j][i] != current) {
                    return ans;
                }
            }

            // Character matched in all strings
            ans += current;
        }

        return ans;
    }
};