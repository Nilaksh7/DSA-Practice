class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        int bestLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1')
                ones++;

            // Try to shrink while we have exactly k ones
            while (ones == k) {
                int len = right - left + 1;

                if (len < bestLen) {
                    bestLen = len;
                    ans = s.substr(left, len);
                }
                else if (len == bestLen) {
                    string current = s.substr(left, len);

                    if (current < ans)
                        ans = current;
                }

                // Remove left character
                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};