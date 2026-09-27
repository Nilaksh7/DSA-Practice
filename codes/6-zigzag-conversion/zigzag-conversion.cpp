class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;  // 1 = down, -1 = up

        for (char c : s) {
            rows[row] += c;

            if (row == 0)
                direction = 1;

            if (row == numRows - 1)
                direction = -1;

            row += direction;
        }

        string ans;

        for (string r : rows)
            ans += r;

        return ans;
    }
};