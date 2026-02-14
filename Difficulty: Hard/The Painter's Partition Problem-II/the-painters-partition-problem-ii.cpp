class Solution {
  public:
     bool feasible(vector<int>& arr, int k, int maxtime) {
        int painters = 1, sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
            if(sum > maxtime) {
                painters++;
                sum = arr[i];
            }
        } return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        if(arr.size() == 1) return arr[0];
        if(k == 1) return accumulate(arr.begin(), arr.end(), 0);
        int low  = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(feasible(arr, k, mid)) high = mid-1;
            else low = mid+1;
        } return low;
    }
};