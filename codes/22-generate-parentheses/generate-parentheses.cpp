class Solution {
public:
    vector<string> ans;

    void backtrack(string& curr, int open, int close, int n) {
        // Used all n pairs
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add an opening bracket
        if (open < n) {
            curr.push_back('(');

            backtrack(curr, open + 1, close, n);

            curr.pop_back();
        }

        // We can add a closing bracket only if
        // there is an unmatched opening bracket
        if (close < open) {
            curr.push_back(')');

            backtrack(curr, open, close + 1, n);

            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr;

        backtrack(curr, 0, 0, n);

        return ans;
    }
};