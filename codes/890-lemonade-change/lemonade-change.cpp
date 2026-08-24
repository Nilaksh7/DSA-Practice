class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            if (bill == 5) {
                five++;
            }

            else if (bill == 10) {
                // Need one $5 as change
                if (five == 0)
                    return false;

                five--;
                ten++;
            }

            else { // bill == 20

                // Prefer $10 + $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // Otherwise give three $5 bills
                else if (five >= 3) {
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};