class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = 1e9;

        // best[i] = shortest target-sum subarray
        // completely within arr[0...i]
        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Make sum <= target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Found a subarray [left ... right]
            if (sum == target) {
                int len = right - left + 1;

                // Previous subarray must end before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Store the shortest subarray seen so far
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {
                // No new subarray ending at right
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }

        return ans == INF ? -1 : ans;
    }
};