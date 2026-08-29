class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        vector<int> ans = nums;

        int i = 0;

        while (i < n) {
            int j = i;

            // Find the complete group
            while (j + 1 < n &&
                   v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int x = i; x <= j; x++) {
                indices.push_back(v[x].second);
            }

            // Smallest indices get smallest values
            sort(indices.begin(), indices.end());

            for (int x = 0; x < indices.size(); x++) {
                ans[indices[x]] = v[i + x].first;
            }

            i = j + 1;
        }

        return ans;
    }
};