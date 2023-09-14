//Copy From ChatGPT//

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            // Ensure nums1 is the smaller array to simplify the binary search
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int maxLeft, minRight;

        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX) {
                // Found the correct partition, calculate median
                if ((m + n) % 2 == 0) {
                    maxLeft = max(maxX, maxY);
                    minRight = min(minX, minY);
                    return (maxLeft + minRight) / 2.0;
                } else {
                    maxLeft = max(maxX, maxY);
                    return maxLeft;
                }
            } else if (maxX > minY) {
                // Shift partitionX to the left
                right = partitionX - 1;
            } else {
                // Shift partitionX to the right
                left = partitionX + 1;
            }
        }

        // If we reach here, it means input arrays are not sorted
        throw invalid_argument("Input arrays are not sorted.");
    }
};
