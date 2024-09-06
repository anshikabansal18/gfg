//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int atMostK(vector<int> &arr, int k){
        int n = arr.size();
        int left = 0, right = 0;
        unordered_map<int,int> mpp;
        int count = 0;
        while(right < n){
            mpp[arr[right]]++;
            while(mpp.size() > k){
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0){
                    mpp.erase(arr[left]);
                }
                left++;
            }
            
            count += right-left+1;
            right++;
        }
        
        return count;
    }
    int subarrayCount(vector<int> &arr, int k) {
        // code here
        return atMostK(arr,k) - atMostK(arr,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.subarrayCount(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends