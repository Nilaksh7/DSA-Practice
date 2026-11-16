class Solution {
public:
    string digitSum(string s, int k) {
        if (s.size() <= k) return s;
        string ns = "";
        for (int i = 0, sum = 0; i < s.size(); ) {
            sum += s[i++]-'0';
            if (i%k == 0 || i == s.size()) ns += to_string(sum), sum = 0;
        }
        return digitSum(ns, k);
    }
};