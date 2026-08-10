class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        int totalLeft = (m + n + 1) / 2; // elements needed on the left half

        while (low <= high) {
            int cut1 = (low + high) / 2;       // partition in nums1
            int cut2 = totalLeft - cut1;       // partition in nums2

            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                // Correct partition found
                if ((m + n) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if (left1 > right2) {
                high = cut1 - 1; // move left in nums1
            }
            else {
                low = cut1 + 1;  // move right in nums1
            }
        }

        return 0.0; // shouldn't reach here for valid input
    }
};