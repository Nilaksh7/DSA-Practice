class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int equal = 0;

        for (int num : nums) {
            if (num < target) {
                smaller++;
            } else if (num == target) {
                equal++;
            }
        }

        vector<int> ans;

        for (int i = smaller; i < smaller + equal; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};