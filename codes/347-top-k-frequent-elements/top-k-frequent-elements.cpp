class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency of every number
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // bucket[i] contains numbers that appear exactly i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        vector<int> ans;

        // Start from highest frequency
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};