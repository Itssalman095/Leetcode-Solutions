class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* matching empty string
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*' && j >= 2) {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char pc = p[j - 1];

                if (pc == '*') {
                    // p[j-2] is the character/dot before '*'
                    char prevPc = p[j - 2];

                    // Zero occurrences of prevPc
                    bool zeroCase = dp[i][j - 2];

                    // One or more occurrences, if current s char matches prevPc
                    bool moreCase = false;
                    if (prevPc == '.' || prevPc == s[i - 1]) {
                        moreCase = dp[i - 1][j];
                    }

                    dp[i][j] = zeroCase || moreCase;
                } else if (pc == '.' || pc == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};