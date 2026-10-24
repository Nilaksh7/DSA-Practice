class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int i = 0;

        while(i < s.size()){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }

            if(min < 0) min = 0;
            if(max < 0) return false;
            i++;
        }

        return min == 0;
    }
};