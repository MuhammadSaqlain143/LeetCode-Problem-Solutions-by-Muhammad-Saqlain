#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // Create a hash table to store the indices of elements
    std::unordered_map<int, int> num_indices;

    // Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
        // Calculate the complement needed to reach the target
        int complement = target - nums[i];

        // Check if the complement is already in the hash table
        if (num_indices.find(complement) != num_indices.end()) {
            // Return the indices of the two numbers that add up to the target
            return {num_indices[complement], i};
        }

        // Add the current number and its index to the hash table
        num_indices[nums[i]] = i;
    }

    // If no solution is found, return an empty vector
    return {};
}

int main() {
    // Example usage:
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);
    std::cout << result1[0] << " " << result1[1] << std::endl;  // Output: 0 1

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);
    std::cout << result2[0] << " " << result2[1] << std::endl;  // Output: 1 2

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = twoSum(nums3, target3);
    std::cout << result3[0] << " " << result3[1] << std::endl;  // Output: 0 1

    return 0;
}
