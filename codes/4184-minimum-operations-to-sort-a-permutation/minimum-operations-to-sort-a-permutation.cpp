#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        bool isAsc = true;
        bool isDesc = true;
        int idx = -1;
        
        // Find 0 and check the cyclic patterns
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) idx = i;
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
                isAsc = false;
            }
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
                isDesc = false;
            }
        }
        
        // Calculate min operations based on pattern
        if (isAsc) {
            if (idx == 0) return 0;
            return std::min(idx, n - idx + 2);
        }
        
        if (isDesc) {
            return std::min(idx + 2, n - idx);
        }
        
        // If neither cyclic ascending nor descending, it's impossible
        return -1;
    }
};