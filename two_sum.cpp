class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices; // Maps numbers to their indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (numIndices.find(complement) != numIndices.end()) {
                result.push_back(numIndices[complement]); // Index of complement
                result.push_back(i); // Current index
                return result;
            }

            // Store the current number and its index in the map
            numIndices[nums[i]] = i;
        }

        return result; // If no solution is found
    }
};
