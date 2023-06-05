class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int maxLength = 0;

        // Insert all numbers into the set
        for (int num : nums) {
            numSet.insert(num);
        }

        // Check each number for consecutive sequence
        for (int num : nums) {
            // Check only for the starting number of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                // Find the consecutive sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

            // Update the maximum length
            maxLength = max(maxLength, currentLength);
        }
    }
    return maxLength;
    }
};
