class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for(char ch : s){
            if(ch == '('){
                depth++;
                if(depth == 1) continue;
                ans.push_back(ch);
            }
            else{
                depth--;
                if(depth == 0) continue;
                ans.push_back(ch);
            }
        }

        return ans;
    }
};