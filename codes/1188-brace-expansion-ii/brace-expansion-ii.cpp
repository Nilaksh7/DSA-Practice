class Solution {
public:
    string s;
    int i = 0;

    // Parse an expression containing unions
    set<string> parseUnion() {
        set<string> res = parseConcat();

        while (i < s.size() && s[i] == ',') {
            i++;  // skip ','

            set<string> right = parseConcat();

            // Union
            res.insert(right.begin(), right.end());
        }

        return res;
    }

    // Parse concatenation
    set<string> parseConcat() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> cur;

            if (s[i] == '{') {
                i++;  // skip '{'

                cur = parseUnion();

                i++;  // skip '}'
            }
            else {
                // Single letter
                cur.insert(string(1, s[i]));
                i++;
            }

            // Cartesian product:
            // concatenate every string in res with every string in cur
            set<string> next;

            for (string a : res) {
                for (string b : cur) {
                    next.insert(a + b);
                }
            }

            res = next;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parseUnion();

        return vector<string>(ans.begin(), ans.end());
    }
};