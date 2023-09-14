#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;            // Left pointer
        int right = height.size() - 1;  // Right pointer
        int leftMax = 0;         // Maximum height on the left
        int rightMax = 0;        // Maximum height on the right
        int trappedWater = 0;    // Total trapped water

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    trappedWater += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    trappedWater += rightMax - height[right];
                }
                right--;
            }
        }

        return trappedWater;
    }
};
