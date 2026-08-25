class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        // Number of elements that should be on the left side
        int half = (m + n + 1) / 2;

        while (low <= high) {
            
            int cut1 = low + (high - low) / 2;
            int cut2 = half - cut1;

            // Elements just outside the partitions
            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd total number of elements
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even total number of elements
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // Too many elements taken from nums1
            if (left1 > right2) {
                high = cut1 - 1;
            }
            // Too few elements taken from nums1
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};