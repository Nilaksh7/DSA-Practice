class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string prefix = "";

        for (int i = 0; i < n; i++) {

            int cur = target[i] - 'a';

            // First try to remain equal to target
            if (freq[cur] > 0) {
                freq[cur]--;
                prefix += target[i];
                continue;
            }

            // Can't remain equal.
            // Try making THIS position greater.
            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = prefix;
                    ans += char('a' + c);
                    freq[c]--;

                    // Fill rest in smallest possible order
                    for (int x = 0; x < 26; x++) {
                        ans += string(freq[x], char('a' + x));
                    }

                    return ans;
                }
            }

            // Can't make current position greater.
            // Backtrack to previous positions.
            for (int j = i - 1; j >= 0; j--) {

                // Return target[j] to available characters
                freq[target[j] - 'a']++;
                prefix.pop_back();

                // Find smallest available char > target[j]
                for (int c = target[j] - 'a' + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string ans = prefix;
                        ans += char('a' + c);
                        freq[c]--;

                        // Smallest possible suffix
                        for (int x = 0; x < 26; x++) {
                            ans += string(freq[x], char('a' + x));
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // We constructed exactly target.
        // Need STRICTLY greater, so backtrack.
        for (int j = n - 1; j >= 0; j--) {
            freq[target[j] - 'a']++;
            prefix.pop_back();

            for (int c = target[j] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = prefix;
                    ans += char('a' + c);
                    freq[c]--;

                    for (int x = 0; x < 26; x++) {
                        ans += string(freq[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};