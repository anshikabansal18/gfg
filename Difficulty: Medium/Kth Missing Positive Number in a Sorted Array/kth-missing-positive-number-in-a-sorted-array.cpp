// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
      int n = arr.size();
        int missing = 0; // Count of missing numbers
        int current = 1; // Start from 1
        int i = 0;

        while (missing < k) {
            if (i < n && arr[i] == current) { // If current number is in array, skip it
                i++;
            } else {// Otherwise, it's missing
                missing++;
                if (missing == k) return current;
            }
            current++;
        }

        return -1; // Just in case
    }
};