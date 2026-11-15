class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        // dp to track counts for even and odd sum subarrays
        vector<vector<int>> dp(2, vector<int>(2, 0));
        
        // Stores the final count of subarrays with an odd sum
        int count = dp[1][0]; 
        for (int i = 0; i < n; i++) {
            // Alternates between 0 and 1 for even/odd index tracking
            unsigned char idx = i & 1; 
            // Determines if the current element is odd (1) or even (0)
            unsigned char parity = arr[i] & 1; 
            
            // If the current element is odd, it contributes to odd subarrays
            // If the current element is even, it contributes to even subarrays
            dp[parity][idx] = (1 + dp[0][!idx]) % MOD;
            dp[!parity][idx] = dp[1][!idx] % MOD;
            
            // Accumulate the count of odd subarrays
            count = (count + dp[1][idx]) % MOD;
        }
        return count;
    }
};