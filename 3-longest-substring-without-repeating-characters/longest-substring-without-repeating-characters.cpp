class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // maps char -> last index seen
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            // If this char was seen before AND it's within the current window
            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};