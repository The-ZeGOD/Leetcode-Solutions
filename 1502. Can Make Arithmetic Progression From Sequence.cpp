class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // Sort the array in ascending order

        int diff = arr[1] - arr[0];  // Calculate the initial difference between the first two elements

        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;  // If the difference between any two consecutive elements is not the same, return false
            }
        }
        return true;
    }
};
