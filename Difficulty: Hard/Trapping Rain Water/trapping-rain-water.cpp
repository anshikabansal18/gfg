class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;

        while (l < r) {

            // Left boundary is smaller → process left
            if (arr[l] <= arr[r]) {
                if (arr[l] >= left_max)
                    left_max = arr[l];
                else
                    ans += left_max - arr[l];
                l++;
            }

            // Right boundary is smaller → process right
            else {
                if (arr[r] >= right_max)
                    right_max = arr[r];
                else
                    ans += right_max - arr[r];
                r--;
            }
        }

        return ans;
    }
};