class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // Check if palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Only half of the characters are needed
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        int halfLen = n / 2;

        // DFS tries to construct the first half
        string half;

        function<string(int, bool)> dfs =
            [&](int pos, bool greater) -> string {

            if (pos == halfLen) {

                // Construct palindrome
                string ans = half;

                if (n % 2)
                    ans += mid;

                string rev = half;
                reverse(rev.begin(), rev.end());

                ans += rev;

                if (ans > target)
                    return ans;

                return "";
            }

            int targetChar = target[pos] - 'a';

            // If already greater, simply use smallest possible characters
            if (greater) {

                for (int c = 0; c < 26; c++) {
                    if (halfFreq[c] == 0)
                        continue;

                    halfFreq[c]--;
                    half.push_back('a' + c);

                    string res = dfs(pos + 1, true);

                    if (!res.empty())
                        return res;

                    half.pop_back();
                    halfFreq[c]++;
                }

                return "";
            }

            // We are still equal to target.
            // Try characters from target[pos] upward.
            for (int c = targetChar; c < 26; c++) {

                if (halfFreq[c] == 0)
                    continue;

                halfFreq[c]--;
                half.push_back('a' + c);

                string res = dfs(
                    pos + 1,
                    c > targetChar
                );

                if (!res.empty())
                    return res;

                half.pop_back();
                halfFreq[c]++;
            }

            return "";
        };

        return dfs(0, false);
    }
};