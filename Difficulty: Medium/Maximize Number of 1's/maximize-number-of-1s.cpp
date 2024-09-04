//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int left = 0, right = 0;
        int maxlen = 0;
        int zeroes = 0;
        while(right < n){
            if(arr[right] == 0){
                zeroes++;
            }
            
            if(zeroes > m){
                if(arr[left] == 0){
                    zeroes--;
                }
                left++;
            }
            
            if(zeroes <= m){
                int len = right - left + 1;
                maxlen = max(maxlen, len);
            }
            right++;
        }
        
        return maxlen;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends