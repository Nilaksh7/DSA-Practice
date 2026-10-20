#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        // The final array must exactly match the sorted version of nums
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int ans = 0;
        
        // Check every possible divisor k of n
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool valid = true;
            
            // Check each block of size k
            for (int i = 0; i < n / k; ++i) {
                int start = i * k;
                int drops = 0;
                int drop_idx = -1;
                
                // 1. Check if the block can be sorted via cyclic shift (at most 1 drop)
                for (int j = 0; j < k; ++j) {
                    if (nums[start + j] > nums[start + (j + 1) % k]) {
                        drops++;
                        drop_idx = j;
                    }
                }
                
                if (drops > 1) {
                    valid = false;
                    break;
                }
                
                // 2. Determine where the sorted version of this block begins
                int start_idx = (drops == 1) ? (drop_idx + 1) % k : 0;
                
                // 3. Verify it perfectly matches the corresponding block in sorted_nums
                for (int j = 0; j < k; ++j) {
                    if (nums[start + (start_idx + j) % k] != sorted_nums[start + j]) {
                        valid = false;
                        break;
                    }
                }
                
                if (!valid) break;
            }
            
            if (valid) {
                ans += k;
            }
        }
        
        return ans;
    }
};