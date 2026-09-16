class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
			// Code here
			int n = arr.size();
			int result = 0;
			int mid = n>> 1;
			sort(arr.begin(), arr.begin() + mid);
			sort(arr.begin() + mid, arr.end());
			for (int i = 0; i<mid; ++i) {
				for (int j = n - 1; j >= mid; --j) {
					if (arr[i] >= arr[j]*5) {
						result += (j - mid) + 1;
						break;
					}
				}
			}
			return result;
		}
};