class Solution {
public:
    // Calculate the sum of digits of a number
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Store each number with its digit sum
        vector<pair<int, int>> arr;

        for (int num : nums) {
            arr.push_back({digitSum(num), num});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());

        // Map each number to its sorted position
        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        // Find the minimum swaps using cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // Already visited or already in the correct position
            if (visited[i] || pos[nums[i]] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;

                // Find where the current number belongs
                j = pos[nums[j]];

                cycleSize++;
            }

            // A cycle of size k requires k - 1 swaps
            swaps += cycleSize - 1;
        }

        return swaps;
    }
};