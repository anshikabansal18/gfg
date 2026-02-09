class Solution {
  public:
     int findKRotation(vector<int> &arr) {
        // Code Here
        int idx = -1;
        int n = arr.size();
        
        for (int i=0; i<n-1; i++) {
            if (arr[i] > arr[i+1]) {
                idx = i;
            }
        }
        
        return idx+1;
    }
};
