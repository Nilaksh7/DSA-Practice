#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        // 1. Square all elements to remove signs
        for (int i = 0; i < n; ++i) {
            squares[i] = 1LL * nums[i] * nums[i];
        }
        
        // 2. Sort the squared values in ascending order
        sort(squares.begin(), squares.end());
        
        long long score = 0;
        int mid = n / 2;
        
        // 3. Subtract the first half (smaller squares) and add the second half (larger squares)
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                score -= squares[i];
            } else {
                score += squares[i];
            }
        }
        
        return score;
    }
};
