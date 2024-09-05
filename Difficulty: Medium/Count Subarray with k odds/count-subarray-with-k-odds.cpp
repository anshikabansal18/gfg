//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int atmostK(int n, vector<int>& nums, int k){
        int left = 0, right = 0;
        int count = 0;
        int oddCount = 0;
        while(right < n){
            if(nums[right] % 2 != 0){
                oddCount++;
            }
            
            while(oddCount > k){
                if(nums[left] % 2 != 0){
                    oddCount--;
                }
                left++;
            }
            
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return atmostK(n,nums,k) - atmostK(n,nums,k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends